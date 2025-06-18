#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int absVal(int a) { return a < 0 ? -a : a; }

int main() {
    int x, y;
    printf("Enter the Size of the Grid (x*y): ");
    scanf("%d%d", &x, &y);
    int grid[x][y];
    srand(time(NULL));

    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            grid[i][j] = rand() % 2;

    printf("Initial grid state:\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }

    int posX = rand() % x;
    int posY = rand() % y;
    int steps = 0;

    printf("\nInitial Position: Room[%d, %d]\n", posX, posY);

    while (1) {
        if (grid[posX][posY] == 1) {
            grid[posX][posY] = 0;
            printf("Step %d: Cleaned Room[%d, %d].\n", ++steps, posX, posY);
        } else {
            // Find nearest dirty room
            int minDist = INT_MAX;
            int targetX = -1, targetY = -1;
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++) {
                    if (grid[i][j] == 1) {
                        int dist = absVal(i - posX) + absVal(j - posY);
                        if (dist < minDist) {
                            minDist = dist;
                            targetX = i;
                            targetY = j;
                        }
                    }
                }
            }

            if (targetX == -1) break; // All clean

            // Move one step toward nearest dirty room
            if (targetX > posX) posX++;
            else if (targetX < posX) posX--;

            else if (targetY > posY) posY++;
            else if (targetY < posY) posY--;

            printf("Step %d: Moved to Room[%d, %d].\n", ++steps, posX, posY);
        }
    }

    printf("\nAll rooms clean! Total steps = %d\n", steps);
    getch();
    return 0;
}
