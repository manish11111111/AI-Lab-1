#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int x, y;
    printf("Enter the Size of the Grid (x*y): ");
    scanf("%d%d", &x, &y);
    int grid[x][y];
    srand(time(NULL));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    printf("Randomly assigned grid states:\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    int initial_pos[2];
    initial_pos[0] = rand() % x;
    initial_pos[1] = rand() % y;

    printf("\nInitial Position in the Grid: Room[%d, %d] => %d\n",
           initial_pos[0], initial_pos[1], grid[initial_pos[0]][initial_pos[1]]);
    int directions[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},          {0, 1},
        {1, -1},  {1, 0}, {1, 1}
    };
    int steps = 0;
    while (1) {
        if (grid[initial_pos[0]][initial_pos[1]] == 1) {
            grid[initial_pos[0]][initial_pos[1]] = 0;
            printf("Step %d: Room[%d, %d] was dirty. Cleaned it.\n",
                   ++steps, initial_pos[0], initial_pos[1]);
        } else {
            int moved = 0;
            for (int d = 0; d < 8; d++) {
                int ni = initial_pos[0] + directions[d][0];
                int nj = initial_pos[1] + directions[d][1];

                if (ni >= 0 && ni < x && nj >= 0 && nj < y && grid[ni][nj] == 1) {
                    initial_pos[0] = ni;
                    initial_pos[1] = nj;
                    printf("Step %d: Current room clean. Moved to dirty neighbor Room[%d, %d].\n",
                           ++steps, ni, nj);
                    moved = 1;
                    break;
                }
            }

            if (!moved) {
                int found = 0;
                for (int i = 0; i < x && !found; i++) {
                    for (int j = 0; j < y && !found; j++) {
                        if (grid[i][j] == 1) {
                            initial_pos[0] = i;
                            initial_pos[1] = j;
                            printf("Step %d: No dirty neighbor. Moving to Room[%d, %d].\n",
                                   ++steps, i, j);
                            found = 1;
                        }
                    }
                }

                if (!found) {
                    printf("\nAll rooms are clean! Cleaning completed in %d steps.\n", steps);
                    break;
                }
            }
        }
    }
    printf("\nFinal grid state:\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (i == initial_pos[0] && j == initial_pos[1])
                printf("P ");
            else
                printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    getch();
    return 0;
}
