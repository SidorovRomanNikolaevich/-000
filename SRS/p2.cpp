#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *logfile;
    logfile = fopen("log.txt", "w"); // открыть файл log.txt для записи

    if (logfile == NULL) {
        printf("Ошибка открытия файла");
        return 1;
    }

    while (1) {
        system("clear"); // очистить экран консоли

        // Получить информацию о текущем использовании ресурсов
        FILE *result = popen("ps aux | grep <p1.cpp>", "r");
        char buffer[1024];
        while (fgets(buffer, 1024, result) != NULL) {
            fprintf(logfile, "%s", buffer); // записать результаты в файл
            printf("%s", buffer); // вывести результаты на экран
        }
        pclose(result);

        // Задержка перед обновлением информации
        sleep(5); // обновлять информацию каждые 5 секунд
    }

    fclose(logfile); // закрыть файл

    return EXIT_SUCCESS;
}
