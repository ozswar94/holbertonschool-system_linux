#include "hls.h"

/**
 * setup_flag - setup the flag
 * @flag: pointer of flag
 */
void setup_flag(flag_t **flag)
{
	flag_t *tmp = (flag_t *)malloc(sizeof(flag_t));

	if (!tmp)
	{
		fprintf(stderr, "Error malloc flag !");
		exit(EXIT_FAILURE);
	}

	tmp->long_listing_f = 0;
	tmp->all = 0;
	tmp->almost_all = 0;
	tmp->list_on_file_per_line = 0;
	tmp->reverse = 0;
	tmp->recursive = 0;
	tmp->sorting_by_size = 0;
	tmp->sorting_by_modificationtime = 0;
	tmp->directory = 0;

	*flag = tmp;
}
