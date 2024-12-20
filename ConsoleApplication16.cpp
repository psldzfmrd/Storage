#include <stdio.h>
#include <stdlib.h>
#include "File1.h"
#include <string.h>

void ReadDatabase() {
    FILE* file;
    int i = 0;
    while (true) {
        puts("Введите имя файла:");
        fflush(stdin);
        scanf("%s", &filename);
        file = fopen(filename, "rt");
        if (file != NULL) break;
        else printf("Неверное имя файла. Попробуйте снова.\n");
    }
    while (fscanf(file, "%s %s %u %u%lf\n", &films[i].director, &films[i].name, &films[i].year, &films[i].quantity, &films[i].price) != EOF) {
        i++;
        film_count += 1;
    }
    fclose(file);
}

void ShowMenu() {
        while (true) {
            puts("Выберите действие: ");
            puts("1 - Просмотр данных");
            puts("2 - Редактирование записи");
            puts("3 - Добавление записи");
            puts("4 - Удаление записи");
            puts("5 - Сортировка данных");
            puts("6 - Найти фильм по названию");
            puts("7 - Средняя стоимость фильма");
            puts("8 - Сохранить данные");
            puts("9 - Выход из программы");
            unsigned opt;
            scanf_s("%u", &opt);
            fflush(stdin);
            switch (opt) {
            case 1: ShowDatabase(&film_count,films); break;
            case 2: CorrectDatabase(&film_count,films); break;
            case 3: AddDatabase(&film_count,films); break;
            case 4: DeleteDatabase(&film_count,films); break;
            case 5: SortDatabase(&film_count, films); break;
            case 6: FindinDatabase(&film_count, films); break;
            case 7: MiddlePriceDatabase(&film_count, films); break;
            case 8: SaveDatabase(&film_count, films); break;
            case 9: QuitDatabase(&film_count, films); break;
            default: puts("Неверная команда");
            }
        }
}
int main() {
	system("chcp 1251");
	ReadDatabase();
    ShowMenu();
}