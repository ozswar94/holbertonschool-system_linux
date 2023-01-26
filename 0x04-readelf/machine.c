#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "machine.h"

/**
* choose_machine - select the good machine by id and print name of machine
* @id_machine: id of machine
*
*/
void choose_machine(int id_machine)
{
	FILE *file;
	int read;
	char id[3];
	char *line = NULL;
	size_t len = 0;
	char machine_name[64];

	file = fopen("machine.txt", "r");
	if (file == NULL)
	{
		perror("error open");
		return;
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		memset(id, '\0', 3);
		memset(machine_name, '\0', 64);

		strncpy(id, line, 2);
		strcpy(machine_name, (line + 4));

		if (atoi(id) == id_machine)
			printf("%s", machine_name);
	}
	free(line);
	fclose(file);
}
