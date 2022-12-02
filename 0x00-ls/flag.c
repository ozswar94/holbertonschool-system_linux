#include  "hls.h"


/**
 * define_flag - setup option
 * @option: string option discribe
 * @flag: option command
 * Return: fotmat string
 */

void define_flag(char *option, flag_t *flag)
{
	int i;

	for (i = 0; option[i]; i++)
	{
		switch (option[i])
		{
			case '1':
				flag->list_on_file_per_line = 1;
				break;
			case 'a':
				flag->all = 1;
				flag->almost_all = 0;
				break;
			case 'A':
				flag->all = 1;
				flag->almost_all = 1;
				break;
			case 'l':
				flag->long_listing_f = 1;
				flag->list_on_file_per_line = 1;
				break;
		}
	}
}
