#include "JohnsSpecialEasyTransfer.h"

/*
 * de begin functie initialized het object.
 * als deze functie een tweede keer gecalled word word die call genegeerd
 */

void JohnsSpecialEasyTransfer::begin(Stream *stream, uint8_t uint8_size, uint8_t int16_size, uint8_t int_size, uint8_t bool_size, Stream *debug_out = NULL)
{
    if(!did_init) {
        if (debug_out) {
            has_debug = true;
            debug_stream = debug_out;
        } else {
            has_debug = false;
        }

        recieve_stream = stream;
        hash_array_raw_uint8_t[uint8_size];
        hash_array_raw_int16_t[int16_size];
        hash_array_raw_int[int_size];
        hash_array_raw_bool[bool_size];


        map_uint8_t = HashMap<char*,uint8_t>( hash_array_raw_uint8_t, uint8_size );
        map_int16_t = HashMap<char*,int16_t>( hash_array_raw_int16_t, int16_size );
        map_int = HashMap<char*,int>( hash_array_raw_int, int_size );
        map_bool = HashMap<char*,bool>( hash_array_raw_bool, bool_size );

        uint8_t_remaining = uint8_size;
        uint16_t_remaining = int16_size;
        int_remaining = int_size;
        bool_remaining = bool_size;

        did_init = true;
    }

}


/*
 * de add recieve functies zijn voor het toevoegen van vars aan de hashmaps.
 * als een naam niet in de hashmap staat
 * todo refactor dit naar 1 generieke functie dit arg krijgt
 */
bool JohnsSpecialEasyTransfer::add_recieve_uint8(String name, uint8_t default_value = 0)
{
    if(uint8_t_remaining > 0) {
		
		uint8_t_idx++;
        uint8_t_remaining--;
        return true;
    } else {
        return false;
    }
}

bool JohnsSpecialEasyTransfer::add_recieve_int16(String name, int16_t default_value = 0)
{
    if(uint16_t_remaining > 0) {

        uint16_t_remaining--;
        return true;
    } else {
        return false;
    }
}


bool JohnsSpecialEasyTransfer::add_recieve_int(String name, int default_value = 0)
{
    if(int_remaining > 0) {

        int_remaining--;
        return true;
    } else {
        return false;
    }
}

bool JohnsSpecialEasyTransfer::add_recieve_bool(String name, bool default_value = false)
{
    
}

/*
 * Comment
 */
uint8_t JohnsSpecialEasyTransfer::get_uint8(String name)
{

}

int16_t JohnsSpecialEasyTransfer::get_int16(String name)
{

}

int JohnsSpecialEasyTransfer::get_int(String name)
{

}

bool JohnsSpecialEasyTransfer::get_bool(String name)
{
    
}

/*
 * Comment
 */
void JohnsSpecialEasyTransfer::send_uint8(String name, uint8_t value)
{

}

void JohnsSpecialEasyTransfer::send_int16(String name, int16_t value)
{

}

void JohnsSpecialEasyTransfer::send_int(String name, int value)
{

}

void JohnsSpecialEasyTransfer::send_bool(String name, bool)
{
    
}

/*
 * Comment
 */
void JohnsSpecialEasyTransfer::update()
{
    /*
    String ret = "";
    if (recieve_serial->available() && read_buffer.length() < buffer_size ) {
        char r_char = recieve_serial->read();  // pakt een char van de serial en plakt hem aan de buffer
        read_buffer += r_char;
        //recieve_serial->print(r_char);
    } else if((read_buffer.length() >= buffer_size) || read_buffer.indexOf(cmd_sep) > 0) {
        int cmd_sep_idx = read_buffer.indexOf(cmd_sep);
        if(cmd_sep_idx > 0) {
            // pakt commando en slices de buffer
            ret = read_buffer.substring(0, cmd_sep_idx);
            read_buffer = read_buffer.substring(cmd_sep_idx + 1);
        } else if (cmd_sep_idx == 0) {
            read_buffer = read_buffer.substring(1);
        } else {
            // recieve_serial->println("recieved garbage clearing buffer");
            read_buffer = "";
        }
    }
    */
}


