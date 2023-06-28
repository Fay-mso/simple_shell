#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: Calculates the sum of numbers from 1 to 10
 * and prints the result.
 *
 * Return: 0 (Success)
 */
int main(void)
{
	int i;
	int sum = 0;

	for (i = 1; i <= 10; i++)
	{
	sum += i;
	}

	printf("The sum is: %d\n", sum);

	return (0);
}
