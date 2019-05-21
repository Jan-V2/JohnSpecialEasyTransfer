
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
#include "HashMap.h"
//#include <NewSoftSerial.h>
//#include <math.h>
//#include <stdio.h>
//#include <stdint.h>
//#include <avr/io.h>

// buffer_size bepaald de maximale lengte van commandos
const int buffer_size = 16;
// dit zijn de header bytes. elk bericht moet met deze bytes beginnen
// deze codes zijn niet gebruikt in ascii
const uint8_t HEADER_1 = 140;
const uint8_t HEADER_2 = 156;


class JohnsSpecialEasyTransfer{
	public:
		void begin(Stream *stream, uint8_t uint8_size, uint8_t int16_size, uint8_t int_size, uint8_t bool_size, Stream *debug_out = NULL);
		
		// met deze methods voeg je vars toe aan de hasmaps
		// true if success false if geen ruimte meer
		bool add_recieve_uint8(String name, uint8_t default_value = 0);
		bool add_recieve_int16(String name, int16_t default_value = 0);
		bool add_recieve_int(String name, int default_value = 0);
		bool add_recieve_bool(String name, bool default_value = false);
		
		// om waardes uit de maps te halen null als waarde niet in de maps zit
		uint8_t get_uint8(String name);
		int16_t get_int16(String name);
		int get_int(String name);
		bool get_bool(String name);
				
		// om waardes te versuren 
		void send_uint8(String name, uint8_t value);
		void send_int16(String name, int16_t value);
		void send_int(String name, int value);
		void send_bool(String name, bool);

		
		// leest de serial uit en update de waardes
		void update();
		
	private:
		Stream *recieve_stream;
		Stream *debug_stream;
		bool has_debug;
		bool did_init;
		
		
		// de ruwe hastypes. worden alleen gebruikt on naar de maps te passen. 
		// het zijn hier vars om memoryleaks te voorkomen.
		HashType<char*,uint8_t> hash_array_raw_uint8_t[];
		HashType<char*,int16_t> hash_array_raw_int16_t[];
		HashType<char*,int> hash_array_raw_int[];
		HashType<char*,bool> hash_array_raw_bool[];
		
		// de daadwerkelijke maps
		HashMap<char*,uint8_t> map_uint8_t;
		HashMap<char*,int16_t> map_int16_t;
		HashMap<char*,int> map_int;
		HashMap<char*,bool> map_bool;
		
		// het aantal nog vrije plekken in de hashmap
		uint8_t uint8_t_remaining;
		uint8_t uint16_t_remaining;
		uint8_t	int_remaining;
		uint8_t bool_remaining;
		
		uint8_t uint8_t_idx = 0;
		uint8_t uint16_t_idx = 0;
		uint8_t	int_idx = 0;
		uint8_t bool_idx = 0;
		
		// buffer_size bepaald de maximale lengte van commandos
		uint8_t buffer[buffer_size];
		
};


#endif
