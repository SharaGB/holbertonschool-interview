#include "sandpiles.h"

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: First sandpile
 * @grid2: Second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, end_process = 1, all_sum = 0, count = 0;

	sum_grids(grid1, grid2);

	while (end_process == 1)
	{
		end_process = 0;

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				grid2[i][j] = grid1[i][j];
				if (grid1[i][j] >= 4)
					all_sum += 1;
			}
		}

		if (all_sum > 0)
		{
			printf("=\n");
			print_grid_topple(grid1);
		}

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] >= 4 && grid2[i][j] >= 4 && count < all_sum)
				{
					end_process = refactor_spaces(grid1, i, j, end_process);
					count += 1;
				}
			}
		}
	}
}

/**
 * print_grid_topple - to print the grid
 * @grid: the grid to print
 */
void print_grid_topple(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * refactor_spaces - refactoring ifs
 * @grid1: the grid to be changed
 * @i: iterator for the loop
 * @j: iterator for the inner loop
 * @end_process: the state if the proccess end or not
 *
 * Return: the end_proccess state
 */

int refactor_spaces(int grid1[3][3], int i, int j, int end_process)
{
	if (i - 1 >= 0)
	{
		grid1[i - 1][j] += 1;
		if (grid1[i - 1][j] >= 4)
			end_process = 1;
	}
	if (i + 1 < 3)
	{
		grid1[i + 1][j] += 1;
		if (grid1[i + 1][j] >= 4)
			end_process = 1;
	}
	if (j - 1 >= 0)
	{
		grid1[i][j - 1] += 1;
		if (grid1[i][j - 1] >= 4)
			end_process = 1;
	}
	if (j + 1 < 3)
	{
		grid1[i][j + 1] += 1;
		if (grid1[i][j + 1] >= 4)
			end_process = 1;
	}
	grid1[i][j] -= 4;
	if (grid1[i][j] >= 4)
		end_process = 1;

	return (end_process);
}

/**
 * sum_grids - the sums of the grids
 * @grid1: the grid one
 * @grid2: the second grid
 */

void sum_grids(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}
