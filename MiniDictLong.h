
#ifndef minidictlong
#define minidictlong

#if ARDUINO > 22
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


#define LONG_SIZE 5



class MiniDictLong
{
public:
    MiniDictLong() {}

    MiniDictLong(uint8_t _size)
    {
        size = _size;
        data[_size];
        keys[_size];
    }

    long get(String key)
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

    bool add(String key, long item)
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

    bool update(String key, long d)
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
    long data[LONG_SIZE];
    String keys[LONG_SIZE];
    int size = LONG_SIZE;
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
