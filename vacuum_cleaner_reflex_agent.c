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

    // Assign random states: 0 = clean, 1 = dirty
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
            // Move randomly
            int newX = posX, newY = posY;
            while (1) {
                int dx = (rand() % 3) - 1;
                int dy = (rand() % 3) - 1;
                newX = posX + dx;
                newY = posY + dy;
                if (newX >= 0 && newX < x && newY >= 0 && newY < y)
                    break;
            }
            posX = newX;
            posY = newY;
            printf("Step %d: Moved to Room[%d, %d].\n", ++steps, posX, posY);
        }

        // Check if all are clean
        int dirty = 0;
        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
                if (grid[i][j] == 1)
                    dirty = 1;

        if (!dirty) break;
    }

    printf("\nAll rooms clean! Total steps = %d\n", steps);
    getch();
    return 0;
}
