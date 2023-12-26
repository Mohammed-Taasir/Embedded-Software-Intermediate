/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include <stdint.h>
#include "../include/common/stats.h"
#include "../include/common/platform.h"

/* Size of the Data Set */
#define SIZE (40)

/*
int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

   //Other Variable Declarations Go Here 
   //Statistics and Printing Functions Go Here 
  //printf("hello world");
  
  printf("before sorting\n");
  printArray(test, SIZE);
  printStats(test, SIZE);
  printf("after sorting\n");
  sortArray(test, SIZE);
  printArray(test, SIZE);
  
  return 0;

}
*/

void print_array(uint8_t* data, int size){
  #ifdef VERBOSE
      for(uint8_t i=0; i<size; i++){
        PRINTF("%u ", *(data + i));
      }
      PRINTF("\n");
  #endif
}

void sortArray(uint8_t* data, int size){
  for(uint8_t i=0; i<size-1; i++){
    for(uint8_t j=0; j<size-1-i; j++){
      if(data[j] < data[j+1]){
        uint8_t temp = data[j];
        data[j] = data[j+1];
        data[j+1] = temp;
      }
    }
  }
}

uint8_t findMean(uint8_t* data, int size){
  uint32_t sum = 0;
  for(uint8_t i=0; i<size; i++){
    sum += *(data + i);
  }
  return sum/size;
}

uint8_t findMedian(uint8_t* data, int size){
  sortArray(data, size);
  
  uint8_t median;
  
  if(size % 2){
  	median = data[size/2];
  }else{
  	median = (data[(size/2) - 1] + data[size/2])/2;
  }
  
  return median;
  //return data[size/2];
}

uint8_t findMaximum(uint8_t* data, int size){
  uint8_t maximum = 0; // 0 is the minimum value in unsigned 8 bit integer range (0-255)
  for(uint8_t i=0; i<size; i++){
    if(data[i] > maximum){
      maximum = data[i];
    }
  }
  return maximum;
}

uint8_t findMinimum(uint8_t* data, int size){
  uint8_t minimum = 0xFF; // 255 is the maximum value in unsigned 8 bit integer range
  for(uint8_t i=0; i<size; i++){
    if(data[i] < minimum){
      minimum = data[i];
    }
  }
  return minimum;
}


void printStats(uint8_t* data, int size){
  print_array(data, size);
  PRINTF("Statistics \n");
  PRINTF("Mean : %u\n", findMean(data, size));
  PRINTF("Median : %u\n", findMedian(data, size));
  PRINTF("Minimum : %u\n", findMinimum(data, size));
  PRINTF("Maximum : %u\n", findMaximum(data, size));
}
/* Add other Implementation File Code Here */
