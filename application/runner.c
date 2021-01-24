/**
 * Программное средство каталога автомобилей.
 * Разработчик - Дубинин А. В.
 * 08.03.2017
 */

// Подключение заголовочных файлов
#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"
#include "types.h"
#include "runner.h"
#include "../handler/handler.h"

/**
 * Функция запуска и исполнения программы.
 */
void runApplication()
{
    /*
     * catalogSize - количество элементов файла каталога,
     * listSize - количество элементов динамического списка,
     * isExit - флаг выхода из программы
     */
    unsigned int catalogSize, listSize, isExit;
    char actionKey;

    /*
     * Открытие файла каталога, формирование динамического списка на основе
     * данных из файла, закрытие файла каталога.
     */
    FILE *catalog = fopen(CATALOG_FILE, CATALOG_READ_MODE);
    listPtr index = formList(catalog);
    fclose(catalog);

    // Вычисление количества элементов из файла каталога
    catalogSize = countListSize(&index);

    isExit = 0;
    do {
        // Вычисление количества элементов динамического списка
        listSize = countListSize(&index);

        displayMainMenu(listSize, catalogSize);
        actionKey = getchar();
        switch (actionKey) {

            // Процедура отображения списка автомобилей
            case ITEM_1:
                if (listSize > 0) {
                    renderListTitle();
                    displayCarsList(&index);
                    returnToMainMenu();
                }
                break;

            // Процедура добавления элемента в список
            case ITEM_2:
                doRepeatedAction(&index, addCarsIntoList);
                break;

            // Процедура удаление элемента из списка
            case ITEM_3:
                if (listSize > 0) {
                doRepeatedAction(&index, removeCarsFromList);
                }
                break;

            // Процедура поиска в соответствии с требованиями покупателя
            case ITEM_4:
                if (listSize > 0) {
                    doRepeatedAction(&index, searchByWishes);
                }
                break;

            // Процедура поиска по соответствующему полю
            case ITEM_5:
                if (listSize > 0) {
                    searchByField(&index);
                }
                break;

            // Процедура сортировки по алфавиту
            case ITEM_6:
                if (listSize > 0) {
                    sortByAlphabet(&index);
                    returnToMainMenu();
                }
                break;

            // Процедура записи в файл элементов динамического списка
            case ITEM_9:
                if ((listSize > 0) || (catalogSize > 0)) {
                    catalogSize = saveCatalog(&index);
                    returnToMainMenu();
                }
                break;

            // Выход из программы
            case ITEM_0:
                isExit = 1;
                break;
        }
    } while (isExit == 0);

    free(index);
    return;
}

