
#ifndef JohnsSpecialEasyTransfer_H
#define JohnsSpecialEasyTransfer_H


//make it a little prettier on the front end.
#define details(name) (byte*)&name,sizeof(name)

//Not neccessary, but just in case.
#if ARDUINO > 22
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "Stream.h"
#include <HashMap.h>
//#include <NewSoftSerial.h>
//#include <math.h>
//#include <stdio.h>
//#include <stdint.h>
//#include <avr/io.h>



const int SIZE_UINT8_T = 1;
const int SIZE_INT = 2;
const int SIZE_BOOL = 1;
const int TYPE_MARKER_SIZE = 1;

// buffer_size bepaald de maximale lengte van commandos
const int buffer_size = 16;
// dit zijn de header bytes. elk bericht moet met deze bytes beginnen
// deze codes zijn niet gebruikt in ascii
const uint8_t HEADER_1 = 140;
const uint8_t HEADER_2 = 156;
const uint8_t NAME_MAX_LEN = 32;

const bool debug_enabled = true;

enum Transfer_Phase
{
    TRANSFER_FAILED,
    READING_HEADER1,
    READING_HEADER2,
    READING_LEN,
    READING_TYPE,
    READING_VAL,
    READING_NAME,
};

class JohnsSpecialEasyTransfer
{
public:
    JohnsSpecialEasyTransfer() {}
    void begin(Stream *stream, uint8_t uint8_size, uint8_t int_size, uint8_t bool_size, Stream *debug_out = NULL);

    // met deze methods voeg je vars toe aan de hasmaps
    // true if success false if geen ruimte meer
    bool add_recieve_uint8(String name, uint8_t default_value = 0);
    bool add_recieve_int(String name, int default_value = 0);
    bool add_recieve_bool(String name, bool default_value = false);

    // om waardes uit de maps te halen null als waarde niet in de maps zit
    uint8_t get_uint8(String name);
    int get_int(String name);
    bool get_bool(String name);

    // om waardes te versuren
    void send_uint8(String name, uint8_t value);
    void send_int(String name, int value);
    void send_bool(String name, bool);

    // leest de serial uit en update de waardes
    void update();

    struct
    {
        int failed_transfers = 0;
        int trashed_bytes = 0;
        int wrong_type = 0;
    } debug;

    void print_debug();

private:
    Stream *_stream;
    Stream *debug_stream;
    bool has_debug;
    bool did_init;

    // de ruwe hastypes. worden alleen gebruikt on naar de maps te passen.
    // het zijn hier vars om memoryleaks te voorkomen.
    HashType<char*,uint8_t> hash_array_raw_uint8_t[];
    HashType<char*,int> hash_array_raw_int[];
    HashType<char*,bool> hash_array_raw_bool[];

    // de daadwerkelijke maps
    HashMap<char*,uint8_t> map_uint8_t;
    HashMap<char*,int> map_int;
    HashMap<char*,bool> map_bool;

    // het aantal nog vrije plekken in de hashmaps
    uint8_t uint8_t_remaining;
    uint8_t	int_remaining;
    uint8_t bool_remaining;

    // de huidige schijfindex van de hashmaps
    uint8_t uint8_t_idx = 0;
    uint8_t	int_idx = 0;
    uint8_t bool_idx = 0;

    Transfer_Phase transfer_phase = READING_HEADER1;


    // buffer_size bepaald de maximale lengte van commandos
    uint8_t buffer[buffer_size];

    void send_name(String name);
    void init_send();

    char* str_2_char(String str);
    void println_int_debug(String name, int val);
    void println_string_debug(String str);
    void print_debug_buffer(char buffer[]);

    struct
    {
        uint8_t data_len;
        uint8_t type_len;
        uint8_t name_len;
        uint8_t name_idx = 0;
        uint8_t data_idx = 0;
        uint8_t val_idx = 0;
        uint8_t val[2];
        char type_char;
        char name_buf[NAME_MAX_LEN];
    } recieved;

    struct
    {
        char _uint8 = 'u';
        char _bool = 'b';
        char _int = 'i';
    } type_chars;
};


#endif
