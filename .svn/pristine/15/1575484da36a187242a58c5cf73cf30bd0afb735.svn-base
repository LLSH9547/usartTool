#include "myString.h"
#include "string.h"
#include "stdio.h"

myString::myString()
{

}


void myString::memcpy_string(char *string)
{
    strcpy(this->string,string);
}

void myString::memcpy_array(char *array, uint16_t len)
{
    uint16_t loop_i;
    for(loop_i=0;loop_i<len;loop_i++)
    {
        this->array[loop_i] = array[loop_i];
    }
}
/**
 * @brief 将一个数组中的每个字节分成两个字符
 *
 * @param String 字符串首地址
 * @param array 数组首地址
 */
void myString::OneHexToTwoChar(uint16_t index,uint16_t len)
{
    uint16_t loop_i = 0;
    for (; loop_i < len; loop_i++)
    {
        this->string[loop_i*2] = hexToChar(this->array[index+loop_i]>>4 & 0x0f);
        this->string[loop_i*2+1] = hexToChar(this->array[index+loop_i] & 0x0f);
    }
    this->string[len*2] = '\0';
}
/**
 * @brief 大端排列的两个字节转成16进制
 *
 * @param array 数组首地址
 * @return uint16_t 16进制数
 */
uint16_t myString::arraytoU16_Big(uint8_t* array_src)
{
    return (uint16_t)array_src[0]<<8 | array_src[1];
}


/**
 * @brief 大端排列的4个字节转成32进制
 *
 * @param array 数组首地址
 * @return uint32_t 32进制数
 */
uint32_t myString::arraytoU32_Big(uint8_t* array_src)
{
    return (uint32_t)array_src[0]<<24 | (uint32_t)array_src[1]<<16 | (uint16_t)array_src[2]<<8 | array_src[3];
}

/**
 * @brief 将数字转成字符
 * 注意：本函数用于将0-15数字转成对应的0-F字符
 * @param hex
 * @return char
 */
char myString::hexToChar(char hex)
{
    if (0 <= hex && hex <= 9)
    {
        return hex + '0';
    }
    else if (10 <= hex && hex <= 15)
    {
        return hex + 'a' - 10;
    }
    return '0';
}
char myString::charToHex(char Char)
{
    if('0'<=Char && Char<='9')
    {
        return Char - '0';
    }
    else if('a'<=Char && Char<='f')
    {
        return Char - 'a' + 10;
    }
    else
    {
        return Char - 'A' + 10;
    }
}

void myString::stringToHex(uint16_t index,uint16_t len)
{
    uint16_t length = 0;
    for(length=0;length<len/2;length++)
    {
       this->array[length]=(charToHex(this->string[index+length*2])<<4 | charToHex(this->string[index+length*2+1]));
    }
}


void myString::HexToString(uint8_t *array_dec,uint8_t *array_src,uint16_t len)
{
    uint16_t loop_i=0;
    for(loop_i=0;loop_i<len;loop_i++)
    {
        sprintf((char*)array_dec,"%2.2x",(char*)array_src[loop_i]);
        array_dec+=2;
    }
    array_dec[len*2]='\0';
}
