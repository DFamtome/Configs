#include <stdio.h>


void print_hexa(int number)
{
	printf("0x%.8x\n", number);
}

int array_max(const int array[], size_t size)
{
	if (size == 0)
	{
		return 0;
	}

	int max = array[0];
	

	for (size_t i = 1; i < size; ++i)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}

	return max;
}

int array_vice_max(const int array[], size_t size)
{
	if (size == 0)
	{
		return 0;
	}

	if (size == 1)
	{
		return array[0];
	}

	int max;
	int vice_max;

	if (array[0] > array[1])
	{
		max = array[0];
		vice_max = array[1];
	}
	else
	{
		max = array[1];
		vice_max = array[0];
	}

	for (size_t i = 0; i < size ; ++i)
	{
		int v = array[i];

		if (v > max)
		{
			max = v;
		}
		else if (v > vice_max)
		{
			vice_max = v;
		}
	}

	return vice_max;
}


int main(void)
{

	printf("=== Print_exa exos ===\n");

	print_hexa(42);
	print_hexa(1024);
	print_hexa(0);

	printf("=== Array_max exos ===\n");

	const int data[] = {1, 5, 2, 10, 11};
	int r = array_max(data, 5);
	printf("%s\n", r == 11 ? "Test passed" : "Test no passed");

	printf("=== Array_vice_max	")

	return 0;
}


