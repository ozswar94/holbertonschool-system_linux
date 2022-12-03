#include "line_hls.h"
#include "hls.h"

/**
 * print_list - list name of file
 * @node: head of node
 * @flag: option command
 *
 */
void print_list(line_hls_t *node, flag_t flag)
{
	line_hls_t *node_temp = node;
	int digit = 0;

	while (node_temp)
	{
		if (number_digit(node_temp->size) > digit)
			digit = number_digit(node_temp->size);
		node_temp = node_temp->next;
	}

	node_temp = node;
	while (node_temp)
	{
		format_string(node_temp, flag, digit);

		if (node_temp)
			node_temp = node_temp->next;
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
	new_node->time = (char *)malloc(sizeof(char) * 256);

	if (!(new_node->perm) || !(new_node->usrname) || !(new_node->grpname) ||
		!(new_node->name) || !(new_node->time))
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
		free(tmp->time);
		free(tmp);
	}
}
