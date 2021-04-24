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
	static size_t counter;
	int exists;
	size_t i, j;

	if (!size)
		return;
	for (i = 0; i < size; i++)
	{
		exists = 0;
		for (j = 0; j < counter; j++)
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
			cars[counter] = id[i];
            car_sort(cars, laps, counter);
			counter++;
			printf("Car %d joined the race\n", id[i]);
		}
	}
	printf("Race state:\n");
	for (j = 0; j < counter; j++)
	{
		printf("Car %d [%d laps]\n", cars[j], laps[j]);
	}
}
/**
 * car_sort - sort cars.
 * @cars: array of cars
 * @laps: array of laps
 * @counter: number of cars in the race
 * Return: always 0.
 */
void car_sort(int *cars, int *laps, int counter)
{
	int tmp;
	int x;

	for (x = counter; x > 0; x--)
	{
		if (cars[x] < cars[x - 1])
		{
			tmp = cars[x - 1];
			cars[x - 1] = cars[x];
			cars[x] = tmp;
			tmp = laps[x - 1];
			laps[x - 1] = laps[x];
			laps[x] = tmp;
		}
	}
}
