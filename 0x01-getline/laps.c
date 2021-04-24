#include "laps.h"
/**
 * race_state - race
 * @id: cars
 * @size: number of cars
 * Return: always 0.
 */
void race_state(int *id, size_t size)
{
	static int cars[64];
	static int laps[64];
	static size_t count;
	int exists;
	size_t i, j;

	if (!size)
		return;
	for (i = 0; i < size; i++)
	{
		exists = 0;
		for (j = 0; j < count; j++)
		{
			if (id[i] == cars[j])
			{
				exists = 1;
				laps[j] += 1;
				break;
			}
		}
		if (exists == 0)
		{
			cars[count] = id[i];
			count++;
			printf("Car %d joined the race\n", id[i]);
		}
	}
	printf("Race state:\n");
	for (j = 0; j < count; j++)
	{
		printf("Car %d [%d laps]\n", cars[j], laps[j]);
	}
}
