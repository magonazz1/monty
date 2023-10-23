#include <stdlib.h>

/* PROTOYPES USED */
char **str_split(char *str, char *delimiters);
int is_delimiter(char ch, char *delimiters);
int word_length(char *str, char *delimiters);
int word_count(char *str, char *delimiters);
char *next_word(char *str, char *delimiters);

/**
 * str_split - Splits a string into words.
 * @str: The string to split into words.
 * @delimiters: The delimiters used to separate words.
 *
 * Return: A 2D array of pointers to each word.
 */
char **str_split(char *str, char *delimiters)
{
	char **words = NULL;
	int wc, word_len, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = word_count(str, delimiters);

	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wc)
	{
		word_len = word_length(str, delimiters);
		if (is_delimiter(*str, delimiters))
		{
			str = next_word(str, delimiters);
		}
		words[i] = malloc((word_len + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < word_len)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0'; /* set end of string */
		str = next_word(str, delimiters);
		i++;
	}
	words[i] = NULL; /* last element is null for iteration */
	return (words);
}

/**
 * is_delimiter - Checks if a character is a delimiter.
 * @ch: The character to check.
 * @delimiters: Pointer to a null-terminated array of delimiters.
 *
 * Return: 1 if it's a delimiter, 0 if not.
 */
int is_delimiter(char ch, char *delimiters)
{
	int i = 0;

	while (delimiters[i])
	{
		if (delimiters[i] == ch)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * word_length - Gets the length of the current word in a string.
 * @str: The string to get the word length from the current word.
 * @delimiters: The delimiters used to separate words.
 *
 * Return: The word length of the current word.
 */
int word_length(char *str, char *delimiters)
{
	int w_leng = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delimiter(str[i], delimiters))
			pending = 1;
		else if (pending)
		{
			w_leng++;
		}
		if (w_leng > 0 && is_delimiter(str[i], delimiters))
			break;
		i++;
	}
	return (w_leng);
}

/**
 * word_count - Gets the word count in a string.
 * @str: The string to get the word count from.
 * @delimiters: The delimiters used to separate words.
 *
 * Return: The word count in the string.
 */
int word_count(char *str, char *delimiters)
{
	int wc = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delimiter(str[i], delimiters))
		{
			pending = 1;
		}
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

/**
 * next_word - Gets the next word in a string.
 * @str: The string to get the next word from.
 * @delimiters: The delimiters used to separate words.
 *
 * Return: A pointer to the first character of the next word.
 */
char *next_word(char *str, char *delimiters)
{
	int pending = 0;
	int i = 0;

	while (*(str + i))
	{
		if (is_delimiter(str[i], delimiters))
		{
			pending = 1;
		}
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}
