/**
 * Программное средство каталога автомобилей.
 * Разработчик - Дубинин А. В.
 * 08.03.2017
 */

// Подключение заголовочных файлов
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../application/definitions.h"
#include "../application/types.h"
#include "handler.h"

/**
 * Функция вызова повторяющихся функций программы.
 * index - параметр типа listPtr (указатель на заглавный элемент списка)
 * action - параметр типа actionType (указатель на функцию)
 */
void doRepeatedAction(listPtr *index, actionType action)
{
    char actionKey;
    action(index);
    do {
        actionKey = getchar();
        if (actionKey == ITEM_9) {
            action(index);
        }
    } while (actionKey != ITEM_0);
    return;
}

/**
 * Функция, формирующая динамический список автомобилей из файловой переменной.
 * Возвращает линейный однонаправленный список.
 * catalog - параметр файлового типа
 */
listPtr formList(FILE *catalog)
{
    // Указатели на заглавное и текущее звено списка
    listPtr index, current;
    vehicle car;

    // Выделение памяти с проверкой заглавному элементу списка
    index = (list *) malloc(sizeof(list));
    if (index == NULL) {
        puts(MSG_MEMORY_ERR);
        return NULL;
    }

    current = index;
    current->next = NULL;

    /*
     * Чтение элементов типизированного файла
     * и формирование динамического списка из этих элементов
     */
    while (1) {
        if (fread(&car, sizeof(vehicle), 1, catalog) < 1) {
            break;
        }

        // Выделение памяти с проверкой новому элементу списка
        current->next = (list *) malloc(sizeof(list));
        if (current->next == NULL) {
            puts(MSG_MEMORY_ERR);
            return NULL;
        }

        current = current->next;
        current->car = car;
        current->next = NULL;
    }

    return index;
}

/**
 * Функция, возвращающая количество элементов списка.
 * index - параметр типа listPtr (указатель на заглавный элемент списка)
 */
unsigned int countListSize(listPtr *index)
{
    listPtr current;
    unsigned int listSize;

    current = (*index)->next;
    listSize = 0;
    while (current != NULL) {
        listSize++;
        current = current->next;
    }
    return listSize;
}

/**
 * Функция вывода на экран списка автомобилей.
 * index - параметр типа listPtr (указатель на заглавный элемент списка)
 */
void displayCarsList(listPtr *index)
{
    renderCarsListHeader();

    listPtr current = (*index)->next;
    unsigned int i = 0;
    while (current != NULL) {
        i++;
        renderCarsListRow(i, current->car);
        current = current->next;
    }
    hr();
    return;
}

/**
 * Функция добавление нового элемента в список автомобилей.
 * index - параметр типа listPtr (указатель на заглавный элемент списка)
 */
void addCarsIntoList(listPtr *index)
{
    vehicle newCar;
    listPtr current, newNode;

    renderAddCarTitle();
    getchar();
    printString(MSG_MODEL);
    scanf(PATTERN_FULL_STR, newCar.model);
    printString(MSG_PRICE);
    scanf(PATTERN_UNSIGNED_LONG, &newCar.price);
    printString(MSG_FUEL);
    scanf(PATTERN_FLOAT, &newCar.fuelConsumption);
    printString(MSG_QUALITY);
    scanf(PATTERN_UNSIGNED, &newCar.longTermQuality);
    printString(MSG_COMFORT);
    scanf(PATTERN_UNSIGNED, &newCar.comfort);

    current = *index;
    while (current->next != NULL) {
        current = current->next;
    }

    newNode = (list *) malloc(sizeof(list));
    if (newNode == NULL) {
        puts(MSG_MEMORY_ERR);
        return;
    }
    newNode->car = newCar;
    newNode->next = current->next;
    current->next = newNode;
    hr();
    printf(MSG_ADD_SUCCESSFUL, newCar.model);
    puts(MSG_ADD_CONTINUE);
    puts(MSG_RETURN_TO_MENU);
    return;
}

/**
 * Функция удаления элемента из списка автомобилей.
 * index - параметр типа listPtr (указатель на заглавный элемент списка)
 */
void removeCarsFromList(listPtr *index)
{
    listPtr current, removed;
    unsigned int listSize, i, n;

    listSize = countListSize(index);
    if (listSize > 0) {
        renderRemoveCarTitle();
        displayCarsList(index);
        current = *index;
        printString(MSG_REMOVE_SELECT);
        scanf(PATTERN_UNSIGNED, &n);

        // Проверка на существование введенного № элемента
        if (n > 0 && n <= listSize) {
            for (i = 1; i < n; i++) {
                current = current->next;
            }
            removed = current->next;
            current->next = removed->next;
            renderRemoveCarTitle();
            displayCarsList(index);
            printf(MSG_REMOVE_SUCCESSFUL, removed->car.model);
            free(removed);
        }
        BR;
        puts(MSG_REMOVE_CONTINUE);
    } else {
        renderEmptyListTitle();
        BR;
    }
    puts(MSG_RETURN_TO_MENU);
    return;
}

/**
 * Функция поиска автомобилей в соответствии с требованиями покупателя.
 * index - параметр типа listPtr (указатель на заглавный элемент списка)
 */
void searchByWishes(listPtr *index)
{
    listPtr current;
    vehicle car;
    unsigned int i;
    unsigned long int minPrice, maxPrice;
    float minFuelConsumption, maxFuelConsumption;
    unsigned int minLongTermQuality, maxLongTermQuality;
    unsigned int minComfort, maxComfort;

    renderSearchByWishesTitle();
    printString(MSG_SEARCH_PRICE_MIN);
    scanf(PATTERN_UNSIGNED_LONG, &minPrice);
    printString(MSG_SEARCH_PRICE_MAX);
    scanf(PATTERN_UNSIGNED_LONG, &maxPrice);
    printString(MSG_SEARCH_FUEL_MIN);
    scanf(PATTERN_FLOAT, &minFuelConsumption);
    printString(MSG_SEARCH_FUEL_MAX);
    scanf(PATTERN_FLOAT, &maxFuelConsumption);
    printString(MSG_SEARCH_QUALITY_MIN);
    scanf(PATTERN_UNSIGNED, &minLongTermQuality);
    printString(MSG_SEARCH_QUALITY_MAX);
    scanf(PATTERN_UNSIGNED, &maxLongTermQuality);
    printString(MSG_SEARCH_COMFORT_MIN);
    scanf(PATTERN_UNSIGNED, &minComfort);
    printString(MSG_SEARCH_COMFORT_MAX);
    scanf(PATTERN_UNSIGNED, &maxComfort);

    i = 0;
    current = *index;
    while (current->next != NULL) {
        car = current->next->car;

        /*
         * Проверка на вхождение характеристик автомобиля из списка,
         * в диапазон заданных покупателем значений.
         */
        if ((car.price >= minPrice)
            && (car.price <= maxPrice)
            && (car.fuelConsumption >= minFuelConsumption)
            && (car.fuelConsumption <= maxFuelConsumption)
            && (car.longTermQuality >= minLongTermQuality)
            && (car.longTermQuality <= maxLongTermQuality)
            && (car.comfort >= minComfort)
            && (car.comfort <= maxComfort)
        ) {
            i++;
            renderSearchResult(i, car);
        }
        current = current->next;
    }
    renderSearchResultFooter(i);
    return;
}

/**
 * Функция поиска автомобилей по соответствующему полю.
 * index - параметр типа listPtr (указатель на заглавный элемент списка)
 */
void searchByField(listPtr *index)
{
    listPtr current;
    vehicle car;
    unsigned int i, isRepeat, isExit;
    char actionKey;
    char specificModel[MODEL_NAME_SIZE];
    char normalizedSpecificModel[MODEL_NAME_SIZE];
    char normalizedModel[MODEL_NAME_SIZE];
    unsigned long int specificPrice;
    float specificFuelConsumption;
    unsigned int specificLongTermQuality;
    unsigned int specificComfort;

    renderSearchByFieldTitle();
    BR;
    puts(MSG_SEARCH_BY_MODEL);
    puts(MSG_SEARCH_BY_PRICE);
    puts(MSG_SEARCH_BY_FUEL);
    puts(MSG_SEARCH_BY_QUALITY);
    puts(MSG_SEARCH_BY_COMFORT);
    BR;
    hr();
    puts(MSG_SEARCH_SELECT);
    BR;
    puts(MSG_RETURN_TO_MENU);

    do {
        i = 0;
        current = *index;
        isRepeat = 0;
        isExit = 0;
        actionKey = getchar();
        switch (actionKey) {
            case ITEM_1:

                /*
                 * Поиск по марке автомобиля реализован путем нахождения
                 * вхождения введенной строки в наименовании марки,
                 * без учета регистра.
                 */
                renderSearchByModelTitle();
                getchar();
                printString(MSG_MODEL);
                scanf(PATTERN_FULL_STR, specificModel);
                while (current->next != NULL) {
                    car = current->next->car;
                    strcpy(normalizedSpecificModel, specificModel);
                    toUpCase(normalizedSpecificModel);
                    strcpy(normalizedModel, car.model);
                    toUpCase(normalizedModel);
                    if (strstr(normalizedModel, normalizedSpecificModel) != NULL) {
                        i++;
                        renderSearchResult(i, car);
                    }
                    current = current->next;
                }
                renderSearchResultFooter(i);
                break;
            case ITEM_2:
                renderSearchByPriceTitle();
                printString(MSG_PRICE);
                scanf(PATTERN_UNSIGNED_LONG, &specificPrice);
                while (current->next != NULL) {
                    car = current->next->car;
                    if (specificPrice == car.price) {
                        i++;
                        renderSearchResult(i, car);
                    }
                    current = current->next;
                }
                renderSearchResultFooter(i);
                break;
            case ITEM_3:
                renderSearchByFuelConsumptionTitle();
                printString(MSG_FUEL);
                scanf(PATTERN_FLOAT, &specificFuelConsumption);
                while (current->next != NULL) {
                    car = current->next->car;
                    if (specificFuelConsumption == car.fuelConsumption) {
                        i++;
                        renderSearchResult(i, car);
                    }
                    current = current->next;
                }
                renderSearchResultFooter(i);
                break;
            case ITEM_4:
                renderSearchByLongTermQualityTitle();
                printString(MSG_QUALITY);
                scanf(PATTERN_UNSIGNED, &specificLongTermQuality);
                while (current->next != NULL) {
                    car = current->next->car;
                    if (specificLongTermQuality == car.longTermQuality) {
                        i++;
                        renderSearchResult(i, car);
                    }
                    current = current->next;
                }
                renderSearchResultFooter(i);
                break;
            case ITEM_5:
                renderSearchByComfortTitle();
                printString(MSG_COMFORT);
                scanf(PATTERN_UNSIGNED, &specificComfort);
                while (current->next != NULL) {
                    car = current->next->car;
                    if (specificComfort == car.comfort) {
                        i++;
                        renderSearchResult(i, car);
                    }
                    current = current->next;
                }
                renderSearchResultFooter(i);
                break;
            case ITEM_9:
                isRepeat = 1;
                isExit = 1;
                break;
            case ITEM_0:
                isExit = 1;
                break;
        }
    } while (isExit == 0);

    if (isRepeat == 1) {
        searchByField(index);
    }
    return;
}

/**
 * Функция сортировки по алфавиту списка по марке автомобиля.
 * index - параметр типа listPtr (указатель на заглавный элемент списка)
 */
void sortByAlphabet(listPtr *index)
{
    listPtr current;
    vehicle car;
    unsigned int isSorted;
    char normalizedCurrentModel[MODEL_NAME_SIZE];
    char normalizedNextModel[MODEL_NAME_SIZE];

    do {
        isSorted = 1;
        current = (*index)->next;
        while (current->next != NULL) {

            /*
             * Сортировка без учета регистра.
             * Для этого сравниваются марки автомобилей, приведенные
             * к верхнему регистру.
             */
            strcpy(normalizedCurrentModel, current->car.model);
            toUpCase(normalizedCurrentModel);
            strcpy(normalizedNextModel, current->next->car.model);
            toUpCase(normalizedNextModel);
            if (strcmp(normalizedCurrentModel, normalizedNextModel) > 0) {
                car = current->car;
                current->car = current->next->car;
                current->next->car = car;
                isSorted = 0;
            }
            current = current->next;
        }
    } while (isSorted == 0);

    renderSortedMsg();
    return;
}

/**
 * Функция для сохранения информации об автомобилях из динамического списка
 * в файл каталога.
 * Возвращает количество элементов списка.
 * index - параметр типа listPtr (указатель на заглавный элемент списка)
 */
unsigned int saveCatalog(listPtr *index)
{
    FILE *catalog;
    listPtr current;
    unsigned int catalogSize;

    catalog = fopen(CATALOG_FILE, CATALOG_WRITE_MODE);
    current = (*index)->next;
    catalogSize = 0;
    while (current != NULL) {
        fwrite(&current->car, sizeof(vehicle), 1, catalog);
        current = current->next;
        catalogSize++;
    }
    fclose(catalog);

    renderSavedMsg();
    return catalogSize;
}

