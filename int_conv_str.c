#include "stdlib.h"

/* PROTOTYPES USED */
char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size);
/**
 * get_int - Converts an integer to a string.
 * @num: The number to convert to a string.
 *
 * Return:
 *   - A character pointer to the newly created string.
 *   - NULL if memory allocation (malloc) fails.
 *
 * Description:
 *   This function takes an integer `num` and converts it into a character
 *   pointer representing the number as a string. It accounts for negative
 *   numbers by including a negative sign if necessary. Memory is allocated
 *   for the string, and if the allocation fails, it returns NULL.
 */
char *get_int(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *retrn;

	temp = _abs(num);
	length = get_numbase_len(temp, 10);

	if (num < 0 || num_l < 0)
	{
		length++; /* Add space for the negative sign */
	}
	retrn = malloc(length + 1); /* Allocate memory for the string */
	if (!retrn)
	{
		return (NULL);
	}

	fill_numbase_buff(temp, 10, retrn, length);
	if (num < 0 || num_l < 0)
	{
		retrn[0] = '-';
	}

	return (retrn);
}

/**
 * _abs - Calculates the absolute value of an integer.
 * @i: The integer to get the absolute value of.
 *
 * Return:
 *   - The unsigned integer representation of the absolute value of `i`.
 *
 * Description:
 *   This function calculates and returns the absolute value of an integer `i`.
 */
unsigned int _abs(int i)
{
	if (i < 0)
	{
		return (-(unsigned int)i);
	}
	return ((unsigned int)i);
}

/**
 * get_numbase_len - Calculates the length buffer needed for an unsigned int.
 * @num: The number to calculate the needed length for.
 * @base: The base of the number representation used by the buffer.
 *
 * Return:
 *   - An integer representing the length of the buffer needed
 *	(excluding the null byte).
 *
 * Description:
 *   This function calculates and returns the length of the buffer needed to
 *   represent an unsigned integer `num` in the specified base.
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int leng = 1; /* All numbers contain at least one digit */

	while (num > base - 1)
	{
		leng++;
		num = num / base;
	}
	return (leng);
}

/**
 * fill_numbase_buff - Fills a buffer with correct numbers up to base 36.
 * @num: The number to convert to a string given the base.
 * @base: The base of the number used in conversion (works up to base 36).
 * @buff: The buffer to fill with the result of the conversion.
 * @buff_size: The size of the buffer in bytes.
 *
 * Description:
 *   This function fills the buffer `buff` with the correct numerical values
 *   based on the given number `num` and base. The conversion works for bases
 *   up to 36 and takes into account letter representations for values beyond 9
 */
void fill_numbase_buff(unsigned int num, unsigned int
		base, char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9) /* Return lowercase ASCII value representation */
			buff[i] = rem + 87; /* 10 will be 'a', 11 = 'b', ... */
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}
