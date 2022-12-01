#include "line_hls.h"
#include "hls.h"

/**
 * print_name - list name of file
 * @node: head of node
 *
 */
void print_name(line_hls_t *node)
{
	line_hls_t *node_temp = node;
	int i = 0;

	while (node_temp)
	{
		if (node_temp && node_temp->name[0] == '.')
		{
			node_temp = node_temp->next;
			if (!node_temp)
				printf("\n");
			continue;
		}
		/*space bitween value*/
		if (i != 0)
			printf("  ");

		if (node_temp->next == NULL)
			printf("%s\n", node_temp->name);
		else
			printf("%s", node_temp->name);

		node_temp = node_temp->next;
		i++;
	}
}


/**
 * add_line - add new element on list
 * @node: head of node
 *
 */
void add_line(line_hls_t **node)
{
	line_hls_t *new_node;

	new_node = (line_hls_t *)malloc(sizeof(line_hls_t));
	if (!new_node)
	{
		fprintf(stderr, "Error malloc node!");
		clean(*node);
		exit(EXIT_FAILURE);
	}

	new_node->perm = (char *)malloc(sizeof(char) * 12);
	new_node->usrname = (char *)malloc(sizeof(char) * 256);
	new_node->grpname = (char *)malloc(sizeof(char) * 256);
	new_node->name = (char *)malloc(sizeof(char) * 256);

	if (!(new_node->perm) || !(new_node->usrname) || !(new_node->grpname) ||
		!(new_node->name))
	{
		fprintf(stderr, "Error malloc string add_line()!");
		clean(*node);
		exit(EXIT_FAILURE);
	}
	new_node->next = *node;
	*node = new_node;
}



/**
 * clean - clean all nodes
 * @node: head of node
 *
 */
void clean(line_hls_t *node)
{
	line_hls_t *tmp = node;

	while (node)
	{
		tmp = node;
		node = node->next;

		free(tmp->perm);
		free(tmp->usrname);
		free(tmp->grpname);
		free(tmp->name);
		free(tmp);
	}
}
