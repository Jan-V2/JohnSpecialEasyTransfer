
#ifndef minidict
#define minidict

#if ARDUINO > 22
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

// niet gebruikt
template <typename T>



class MiniDict
{
public:
    MiniDict() {}

    MiniDict(uint8_t _size)
    {
        size = _size;
        data[_size];
        keys[_size];
    }

    T get(String key)
    {
        for (int i=0; i < idx; i++)
        {
            if (keys[i] == key)
            {
                return data[i];
            }
        }
    }



    bool has_key(String key)
    {
        if(find_key(key) > -1)
        {
            return true;
        }
        return false;
    }

    bool add(String key, T item)
    {
        if(idx+1 < size)
        {
            Serial.println("test");
            keys[idx] = key;
            Serial.println("tessdft");
            data[idx] = item;
            Serial.println("tesasdfat");
            idx++;
            Serial.println("tesasdfaasdt");
            return true;
        }
        else
        {
            return false;
        }
    }

    bool update(String key, T d)
    {
        int _idx = find_key(key);
        if(idx > -1)
        {
            data[idx] = d;
            return true;

        }
        return false;
    }

    int spots_remaining()
    {
        return size - idx - 1;
    }

private:
    T data[];
    String keys[];
    int size;
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
