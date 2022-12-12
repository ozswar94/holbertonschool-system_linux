#include "laps.h"

/**
 * not_in_race - check if id is in race
 * @node: First operand
 * @id: Second operand
 *
 * Return: 1 if in race else 0
 */
int not_in_race(cars_t *node, int id)
{
	cars_t *tmp = node;

	while (tmp)
	{
		if (tmp->id == id)
		{
			tmp->laps += 1;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

/**
 * add_cars - insert new element on linked list
 * @head: heaod of linked list
 * @id: new id add
 *
 * Return: head of linkend otherwis NULL
 */
cars_t *add_cars(cars_t **head, int id)
{
	cars_t *curr = NULL;
	cars_t *new = NULL;

	if (!head)
		return (NULL);

	new = malloc(sizeof(cars_t));
	if (!new)
		return (NULL);
	new->id = id;
	new->laps = 0;
	new->next = NULL;
	printf("Car %d joined the race\n", new->id);

	if (!*head)
		return (new);

	curr = *head;
	if (id < curr->id)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		while (curr->next && curr->next->id < id)
			curr = curr->next;

		new->next = curr->next;
		curr->next = new;
	}
	return (*head);
}

/**
 * race_state - keeps track of the number of laps made
 * by several cars in a race
 * @id: ids on race
 * @size: size of id
 *
 */
void race_state(int *id, size_t size)
{
	size_t i;
	cars_t *tmp;
	static cars_t *node_cars;

	if (!size)
	{
		while (tmp && node_cars)
		{
			tmp = node_cars;
			node_cars = node_cars->next;
			free(tmp);
		}
		return;
	}

	if (!node_cars)
		for (i = 0; i < size; i++)
			node_cars = add_cars(&node_cars, id[i]);
	else
	{
		tmp = node_cars;
		for (i = 0; i < size; i++)
		{
			if (!not_in_race(tmp, id[i]))
				tmp = add_cars(&tmp, id[i]);

			tmp = tmp->next;
		}
	}

	tmp = node_cars;
	printf("Race state:\n");
	while (tmp)
	{
		printf("Car %d [%d laps]\n", tmp->id, tmp->laps);
		tmp = tmp->next;
	}
}
