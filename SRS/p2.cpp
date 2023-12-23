#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *logfile;
    char path[] = "files/log.txt"; // путь к файлу log.txt

    logfile = fopen(path, "w"); // открыть файл log.txt для записи

    if (logfile == NULL) {
        printf("Ошибка открытия файла");
        return 1;
    }

    while (1) {
        system("clear"); // очистить экран консоли

        // Получить информацию о текущем использовании ресурсов
        FILE *result = popen("ps aux | grep <название_вашей_программы>", "r");
        char buffer[1024];
        while (fgets(buffer, 1024, result) != NULL) {
            printf("%s", buffer); // вывести результаты на экран
        }
        pclose(result);

        // Записать результаты в файл
        result = popen("ps aux | grep <название_вашей_программы>", "r");
        while (fgets(buffer, 1024, result) != NULL) {
            fprintf(logfile, "%s", buffer); // записать результаты в файл
        }
        pclose(result);

        // Задержка перед обновлением информации
        sleep(5); // обновлять информацию каждые 5 секунд
    }

    fclose(logfile); // закрыть файл

    return EXIT_SUCCESS;
}
