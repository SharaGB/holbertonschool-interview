#ifndef _SANDPILES_H_
#define _SANDPILES_H_

#include <stdio.h>

int refactor_spaces(int grid1[3][3], int i, int j, int end_process);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void sum_grids(int grid1[3][3], int grid2[3][3]);
void print_grid_topple(int grid[3][3]);

#endif /* _SANDPILES_H_ */
