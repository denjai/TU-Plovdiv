#include <stdio.h>
#include <stdlib.h>

int find_bits_in_bitmap(unsigned char * bm_arr, int bmarr_size, int b_count)
{
	int i, j, b_place = 0;
	for (i = 0, j = 0; i < bmarr_size; i++)
		if (bm_arr[i])
		{
			b_place = i + 1;
			j = 0;
		}
		else
		{
			j++;
			if (j == b_count)
			{
				return b_place;
			}

		}
	return -1;
}

void main()
{
	int memory_size, i, b_count, freeblock_start;
	unsigned char *memory, *bitmap;

	printf("How many bytes of memory do you want to manage?\n");
	scanf("%d", &memory_size);

	if ((memory = (unsigned char *)malloc(sizeof(unsigned char) * 8 * memory_size)) == NULL)
	{
		printf("Unable to allocate enough memory for the 'memory' array\n");
		system("pause");
		return;
	}

	if ((bitmap = (unsigned char *)malloc(sizeof(unsigned char)*memory_size)) == NULL)
	{
		printf("Unable to allocate enough memory for the 'bitmap' array\n");
		system("pause");
		return;
	}

	for (i = 0; i < memory_size; i++)
	{
		bitmap[i] = 0;
	}

	for (i = 0; i < memory_size / 2; i++)
	{
		bitmap[rand() % memory_size] = 1;
	}

	printf("How much bytes of memory do you need?\n");
	scanf("%d", &b_count);

	if ((freeblock_start = find_bits_in_bitmap(bitmap, memory_size, b_count)) < 0)
	{
		printf("Couldn't find enough free bytes!\n");
		system("pause");
		return;
	}

	printf("There is a big enough block of memory found at %d place in the bitmap, starting from bit No.%d in the memory\n", freeblock_start, freeblock_start * 8);
	printf("Do you want to show the bitmap? [y/n]\n\n");

	if (getch() == 'y')
	{
		for (i = 0; i < memory_size; i++)
		{
			printf("%c", bitmap[i] + 48);
		}
	}

	printf("\n");
	system("pause");
}
