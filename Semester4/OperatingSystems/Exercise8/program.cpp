#include <stdio.h>
#include <stdlib.h>

int find_bits_in_bitmap(unsigned char * bm_arr, int bmarr_size, int b_count)
{
	int i, j, b_place = 0, k;
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
				for (k = b_place; k <= j; k++)
				{
					bm_arr[k] = 1;
				}
				return b_place;
			}
		}
	return -1;
}

int main()
{
	int size = 40, i, b_count, result;
	unsigned char * bitmap;

	if ((bitmap = (unsigned char *)malloc(sizeof(unsigned char)*size)) == NULL)
	{
		printf("Unable to allocate enough memory for the 'bitmap' array\n");
		system("pause");
		return;
	}

	for (i = 0; i < size; i++)
	{
		bitmap[i] = 0;
	}
	for (i = 0; i < size / 2; i++)
	{
		bitmap[rand() % size] = 1;
	}

	printf("Number of sequential '0' bits?\n");
	scanf("%d", &b_count);

	if ((result = find_bits_in_bitmap(bitmap, size, b_count)) < 0)
	{
		printf("Couldn't find  %d sequential'0' bits!\n", b_count);
		system("pause");
		return;
	}
	printf("There is %d sequential '0' bits starting from bit No.%d in the bitmap array\n", b_count, result);

	system("pause");
	return 0;
}
