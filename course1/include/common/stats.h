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
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 



/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */
 
 

/**
@brief prints array
@param takes pointer to array
@param takes size of array
@return nothing just prints array having uint8_t values as elements
*/
void print_array(uint8_t* data, int size);


/**
@brief sorts array
@param takes pointer to array
@param takes size of array
@return nothing
*/
void sortArray(uint8_t* data, int size);


/**
@brief finds median
@param takes pointer to array
@param takes size of array
@return median uint8_t value
*/
uint8_t findMedian(uint8_t* data, int size);


/**
@brief finds mean
@param takes pointer to array
@param takes size of array
@return mean 
*/
uint8_t findMean(uint8_t* data, int size);


/**
@brief finds maximum
@param takes pointer to array
@param takes size of array
@return max
*/
uint8_t findMaximum(uint8_t* data, int size);


/**
@brief finds minimum
@param takes pointer to array
@param takes size of array
@return min
*/
uint8_t findMinimum(uint8_t* data, int size);


/**
@brief print stats
@param takes pointer to array
@param takes size of array
@return nothing just prints stats
*/
void printStats(uint8_t* data, int size);




#endif /* __STATS_H__ */
