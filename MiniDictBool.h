
#ifndef minidictbool
#define minidictbool

#if ARDUINO > 22
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define BOOL_SIZE 10



class MiniDictBool
{
public:
    MiniDictBool() {}



    bool get(String key)
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

    bool add(String key, bool item)
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

    bool update(String key, bool d)
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
    bool data[BOOL_SIZE];
    String keys[BOOL_SIZE];
    int size = BOOL_SIZE;
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
