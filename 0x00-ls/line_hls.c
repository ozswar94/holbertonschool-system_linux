#include "line_hls.h"
#include "hls.h"

/**
 * print_name - list name of file
 * @node: head of node
 * @flag: flag option
 *
 */
void print_name(line_hls_t *node, flag_t *flag)
{
	line_hls_t *node_temp = node;

	while (node_temp->next)
	{
		if (node_temp->name[0] == '.' && flag->almost_all)
		{
			node_temp = node_temp->next;
			continue;
		}
		else
		{
			if (node_temp->next->next == NULL)
				fprintf(stdout, "%s\n", node_temp->name);
			else
				fprintf(stdout, "%s  ", node_temp->name);
		}
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
		return;

	new_node->perm = (char *)malloc(sizeof(char) * 12);
	new_node->usrname = (char *)malloc(sizeof(char) * 256);
	new_node->grpname = (char *)malloc(sizeof(char) * 256);
	new_node->name = (char *)malloc(sizeof(char) * 256);
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
