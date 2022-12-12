#ifndef _LAPS_H_
#define _LAPS_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/**
 * struct cars_s - cars on race (linked list)
 * @id: id of cars
 * @laps: number laps of the race
 * @next: node next on linked list
 *
 * Description: Longer description
 */
typedef struct cars_s
{
	int id;
	int laps;
	struct cars_s *next;
} cars_t;

void race_state(int *id, size_t size);

#endif /*_LAPS_H_*/
