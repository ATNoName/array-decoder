#ifndef ARR_H
#define ARR_H

#include <stdio.h>
#include <stdbool.h>


/*
 * Reads count int values from f storing the values in 
 * the specified array.
 *
 * Does not close the file f.
 */
void arr_readn(FILE *f, size_t count, int *arr);



/*
 * Reads characters from f storing the characters in the array 
 * pointed at by s. Stops reading when a newline character '\n' 
 * is reached, or when max_length characters are read. A newline
 * character is never stored in the array pointed at by s.
 *
 * Returns true if a newline character is reached (indicating
 * that an entire line of the file was read), or false otherwise.
 *
 * Does not close the file f.
 */
bool arr_readline(FILE *f, size_t max_length, char *s);


/*
 * Extracts integer values from a string where the integer values
 * are separated from one another by a single comma (no spaces).
 * The integer values are returned in a newly allocated array
 * having capacity exactly equal to the number of integers extracted.
 * The number of extracted integers is written into the object
 * pointed at by n.
 */
int *arr_fromstr(const char *s, size_t *n);



/*
 * Uncompresses the n element compressed array enc returning
 * a pointer to the first element of a new array
 * containing the uncompressed array. Writes the length of the
 * uncompressed array into the object pointed at by dec_len.
 *
 * The returned array has no excess capacity (i.e.,
 * all values in the returned array are meaningful).
 */
int *arr_decode(size_t n, const int *enc, size_t *dec_len);



#endif
