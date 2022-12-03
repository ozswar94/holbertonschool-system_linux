#include "line_hls.h"


/**
 * number_digit - count number of digiti
 * @nb: number
 *
 * Return: digit of number
 */

int number_digit(unsigned int nb)
{
	int i;
	unsigned int digit = 1;

	for (i = 0; digit < nb; i++)
		digit *= 10;

	return (i);
}

/**
 * format_string - list name of file
 * @node: head of node
 * @flag: option command
 * @digit: print with the good digit for option -l
 * Return: fotmat string
 */
void format_string(line_hls_t *node, flag_t flag, int digit)
{
	if (hstrlen(node->name) == 2 || hstrlen(node->name) == 1)
	{
		if (flag.almost_all &&
			(hstrcmp(node->name, ".") == 0 || hstrcmp(node->name, "..") == 0))
		{
			if (node->next == NULL)
				printf("\n");
			return;
		}
	}

	if (!(flag.all) && node->name[0] == '.')
	{
		if (node->next == NULL && !flag.list_on_file_per_line)
			printf("\n");
		return;
	}

	if (flag.long_listing_f)
	{
		printf("%s %u %s %s %*u %s %s\n", node->perm, node->hlnk,
				node->usrname, node->grpname, digit, node->size,
				node->time, node->name);
		return;
	}

	if (flag.list_on_file_per_line)
	{
		printf("%s\n", node->name);
		return;
	}

	if (node->next == NULL)
		printf("%s\n", node->name);
	else
		printf("%s ", node->name);
}
