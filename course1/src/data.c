#include "../include/common/data.h"
#include <stdio.h>

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
    if(data == 0){
        *ptr = '0';
        *(ptr + 1) = '\0';
        return 2;
    }

    uint8_t isNegative = 0; // is negative flag
    uint8_t length = 0; // keeps track of output string length

    if(data < 0){ // if the data is negative
        data = data * -1;
        isNegative = 1;
    }

    while(data != 0){
        int32_t remainder = data % base; // why remainder is int32_t because data is int32_t
        *(ptr + length) = (remainder > 9) ? (remainder - 10) + 'a' : remainder + '0';   // for ex: if remainder is 15 and base is 16 then to convert 15 to in base 16. we will do 15-10=5 and then 5+a which will be f. hence take a simple example of data being 255 and base being 16. output of itoa will be ff.
        data = data/base;
        length++;
    }

    if(isNegative){
        *(ptr + length) = '-';
        length++;
    }

    uint8_t * start = ptr;
    uint8_t * end = ptr + length - 1;

    while(start < end){
        uint8_t temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    *(ptr + length) = '\0'; // mandatory shit

    return length + 1;
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
    int32_t result = 0;
    uint8_t sign = 0;

    if(*ptr == '-'){
        sign = 1;
        ptr++;
        digits--;
    }

    for(uint8_t i=0; i<digits; i++){
        uint8_t digit = *(ptr + i);
        int8_t value;

        if(digit >= '0' && digit <= '9'){
            value = digit - '0';
        }
        else if(digit >= 'a' && digit <= 'f'){
            value = digit - 10 + 'a';
        }
        else if(digit >= 'A' && digit <= 'F'){
            value = digit - 10 + 'A';
        }
        else{
            return 0;
        }

        result = result * base + value;
    }

    if(sign){
        return -1 * result;
    }

    return result;
}


