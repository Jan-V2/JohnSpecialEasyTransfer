
#ifndef minidictuint8
#define minidictuint8

#if ARDUINO > 22
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


#define UINIT8_SIZE 10


class MiniDictUint8
{
public:
    MiniDictUint8() {}

    MiniDictUint8(uint8_t _size)
    {
        size = _size;
        data[_size];
        keys[_size];
    }

    uint8_t get(String key)
    {
        for (int i=0; i < idx; i++)
        {
            if (keys[i] == key)
            {
                return data[i];
            }
        }
        return 0;
    }


    bool has_key(String key)
    {
        if(find_key(key) > -1)
        {
            return true;
        }
        return false;
    }

    bool add(String key, uint8_t item)
    {
        if(idx+1 < size)
        {
            keys[idx] = key;
            data[idx] = item;
            idx++;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool update(String key, uint8_t d)
    {
        int _idx = find_key(key);
        if(_idx > -1)
        {
            data[_idx] = d;
            return true;

        }
        return false;
    }

    int spots_remaining()
    {
        return size - idx - 1;
    }

private:
    uint8_t data[UINIT8_SIZE];
    String keys[UINIT8_SIZE];
    int size = UINIT8_SIZE;
    int idx = 0;

    int find_key(String key)
    {
        for (int i=0; i < idx; i++)
        {
            if (keys[i] == key)
            {
                return i;
            }
        }
        return -1;
    }
};


#endif
