#ifndef MYSTRING_H
#define MYSTRING_H

#include <stdint.h>

class myString{

public:
    myString();
    uint16_t arraytoU16_Big(uint8_t* array_src);
    uint32_t arraytoU32_Big(uint8_t* array_src);
    void OneHexToTwoChar(uint16_t index,uint16_t len);
    void stringToHex(uint16_t index,uint16_t len);
    char charToHex(char Char);
    char hexToChar(char hex);
    void memcpy_string(char* string);
    void memcpy_array(char* array,uint16_t len);
    void HexToString(uint8_t *array_dec,uint8_t *array_src,uint16_t len);
    char array[1000];
    char string[1000];
private:

};


#endif // MYSTRING_H
