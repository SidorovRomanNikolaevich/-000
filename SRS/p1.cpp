#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// Функция для вывода графа на экран
void printGraph(int graph[SIZE][SIZE]) {
    printf("Граф:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Функция для поиска кратчайшего пути между двумя вершинами с помощью алгоритма Ли
void leeAlgorithm(int graph[SIZE][SIZE], int startX, int startY, int targetX, int targetY) {
    int queue[SIZE * SIZE][2];
    int front = 0, rear = 0;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    // Инициализация массива расстояний
    int distance[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            distance[i][j] = -1;
        }
    }

    // Начальная вершина
    distance[startX][startY] = 0;
    queue[rear][0] = startX;
    queue[rear][1] = startY;
    rear++;

    // Алгоритм Ли
    while (front != rear) {
        int currentX = queue[front][0];
        int currentY = queue[front][1];
        front++;

        for (int i = 0; i < 4; i++) {
            int newX = currentX + dx[i];
            int newY = currentY + dy[i];
            if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE && graph[newX][newY] == 1 && distance[newX][newY] == -1) {
                distance[newX][newY] = distance[currentX][currentY] + 1;
                queue[rear][0] = newX;
                queue[rear][1] = newY;
                rear++;
            }
        }
    }

    // Вывод кратчайшего пути
    printf("Кратчайший путь от (%d,%d) до (%d,%d) равен %d\n", startX, startY, targetX, targetY, distance[targetX][targetY]);
}

int main() {
    // Инициализация графа случайными значениями
    int graph[SIZE][SIZE];
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            graph[i][j] = rand() % 2; // заполняем случайными значениями 0 или 1
        }
    }

    // Вывод графа на экран
    printGraph(graph);

    // Поиск кратчайшего пути между двумя вершинами
    int startX, startY, targetX, targetY;
    printf("Введите координаты начальной вершины (x y): ");
    scanf("%d %d", &startX, &startY);
    printf("Введите координаты конечной вершины (x y): ");
    scanf("%d %d", &targetX, &targetY);
    leeAlgorithm(graph, startX, startY, targetX, targetY);

    return EXIT_SUCCESS;
}
