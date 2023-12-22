#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

void printGraph(int graph[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void leeAlgorithm(int graph[ROWS][COLS], int startX, int startY, int endX, int endY) {
    int queue[ROWS * COLS][2];
    int front = 0, rear = 0;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    queue[rear][0] = startX;
    queue[rear][1] = startY;
    rear++;

    while (front != rear) {
        int x = queue[front][0];
        int y = queue[front][1];
        front++;

        for (int k = 0; k < 4; k++) {
            int newX = x + dx[k];
            int newY = y + dy[k];

            if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS && graph[newX][newY] == 0) {
                graph[newX][newY] = graph[x][y] + 1;
                queue[rear][0] = newX;
                queue[rear][1] = newY;
                rear++;
            }
        }
    }

    if (graph[endX][endY] == 0) {
        printf("Кратчайший путь не найден\n");
    } else {
        printf("Кратчайший путь: %d\n", graph[endX][endY]);
    }
}

int main() {
    int graph[ROWS][COLS] = {
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 0}
    };

    printf("Сгенерированный граф:\n");
    printGraph(graph);

    int startX, startY;
    int endX, endY;

    printf("Введите координаты начальной вершины (x y): ");
    scanf("%d %d", &startX, &startY);
    printf("Введите координаты конечной вершины (x y): ");
    scanf("%d %d", &endX ,&endY);

    leeAlgorithm(graph,startX,startY,endX,endY);

    return EXIT_SUCCESS;
}
