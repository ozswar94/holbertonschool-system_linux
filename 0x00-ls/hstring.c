#include "hstring.h"

/**
 * hstrcpy - copy string
 * @dst: First string
 * @src: Second string
 *
 * Return: dest
 */
char *hstrcpy(char *dst, const char *src)
{
	unsigned int i = 0;

	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}


/**
 * hstrcat - concat string
 * @s1: First string
 * @s2: Second string
 *
 * Return: s2
 */
char *hstrcat(char *s1, char *s2)
{
	unsigned int i = 0, j = 0;

	while (s1[i])
		i++;

	while (s2[j])
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}


/**
 * hstrlen - lenght string
 * @str: string
 *
 * Return: size of string
 */
unsigned int hstrlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * hmemset - copy string
 * @s: void ptr
 * @c: value set
 * @n: number of bytes set
 *
 * Return: dest
 */
void *hmemset(void *s, int c, unsigned int n)
{
	unsigned char *bytes = s;
	unsigned int i;

	for (i = 0; i < n; i++)
		bytes[i] = c;
	return (bytes);
}

/**
 * hstrcmp- compare two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: value of compare
 */
int hstrcmp(char *s1, char *s2)
{
	int i;
	int size_s1;
	int size_s2;

	if (!s1 || !s2)
		return (0);

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] > s2[i] || s1[i] < s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	for (size_s1 = 0; s1[size_s1]; size_s1++)
	;
	for (size_s2 = 0; s1[size_s2]; size_s2++)
	;
	if (size_s1 > size_s2)
		return (s1[size_s1] - s2[i]);
	if (size_s1 < size_s2)
		return (s1[i] - s2[size_s2]);
	return (0);
}
