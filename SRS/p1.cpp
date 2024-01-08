#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#define ROWS 4
#define COLS 4

// Структура для представления точки в лабиринте
typedef struct {
    int x, y;
} Point;

// Функция для проверки, является ли точка допустимой в лабиринте
bool isValid(int maze[ROWS][COLS], bool visited[ROWS][COLS], int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] == 0 && !visited[x][y]);
}

// Реализация алгоритма Ли для поиска кратчайшего пути в лабиринте
int leeAlgorithm(int maze[ROWS][COLS], Point start, Point end) {
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    bool visited[ROWS][COLS];
    memset(visited, false, sizeof(visited));
    
    visited[start.x][start.y] = true;
    
    int queueX[ROWS * COLS];
    int queueY[ROWS * COLS];
    int front = 0, rear = 0;
    
    queueX[rear] = start.x;
    queueY[rear] = start.y;
    rear++;
    
    while (front < rear) {
        int x = queueX[front];
        int y = queueY[front];
        front++;
        
        if (x == end.x && y == end.y) {
            return maze[x][y];
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (isValid(maze, visited, nx, ny)) {
                queueX[rear] = nx;
                queueY[rear] = ny;
                rear++;
                visited[nx][ny] = true;
                maze[nx][ny] = maze[x][y] + 1;
            }
        }
    }
    
    return -1;
}

int main() {
// Пример использования
    int maze[ROWS][COLS] = {{0, 0, 0, 0},
                            {1, 1, 0, 1},
                            {0, 0, 0, 0},
                            {0, 1, 1, 0}};
    
    Point start = {0, 0};
    Point end = {3, 3};
    
    clock_t start_time = clock();
    
    int shortestPathLength = leeAlgorithm(maze, start, end);
    
    clock_t end_time = clock();
    
    double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Shortest path length: %d\n", shortestPathLength);
    printf("CPU time used: %f seconds\n", cpu_time_used);
    
    FILE *file = fopen("files/log.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    fprintf(file, "Shortest path length: %d\n", shortestPathLength);
    fprintf(file, "CPU time used: %f seconds\n", cpu_time_used);
    
    fclose(file);
    
    return 0;
}
