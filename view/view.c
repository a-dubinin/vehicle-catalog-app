/**
 * Программное средство каталога автомобилей.
 * Разработчик - Дубинин А. В.
 * 08.03.2017
 */

// Подключение заголовочных файлов
#include <stdio.h>
#include "../application/definitions.h"
#include "../application/types.h"
#include "view.h"

/**
 * Функция вывода на всю ширину окна горизонтальной полосы.
 */
void hr()
{
    int i;
    for (i = 0; i <= WINDOW_WIDTH; i++) {
        putchar(HYPHEN);
    }
    BR;
    return;
}

/**
 * Функция преобразования строки к верхнему регистру.
 * str - параметр типа string
 */
void toUpCase(char *str)
{
    char *buffer;
    for (buffer = str; *buffer != NULL_TERMINATED; buffer++) {
        *buffer = (char) toupper(*buffer);
    }
    return;
}

/**
 * Функция вывода на экран строки.
 * str - параметр-константа типа string
 */
void printString(const char *str)
{
    printf(PATTERN_STR, str);
    return;
}

/**
 * Функция вывода на экран заголовка.
 * title - параметр-константа типа string
 */
void renderTitle(const char *title)
{
    system(CALL_CLEAR);
    BR;
    printf(PATTERN_TITLE, title);
    hr();
    return;
}

/**
 * Функции вывода на экран строк в качестве заголовков.
 */

void renderListTitle()
{
    renderTitle(MSG_CATALOG_TITLE);
    return;
}

void renderEmptyListTitle()
{
    renderTitle(MSG_EMPTY_CATALOG_TITLE);
    return;
}

void renderAddCarTitle()
{
    renderTitle(MSG_ADD_CAR_TITLE);
    return;
}

void renderRemoveCarTitle()
{
    renderTitle(MSG_REMOVE_CAR_TITLE);
    return;
}

void renderSearchByWishesTitle()
{
    renderTitle(MSG_BY_WISHES_TITLE);
    return;
}

void renderSearchByFieldTitle()
{
    renderTitle(MSG_BY_FIELD_TITLE);
    return;
}

void renderSearchByModelTitle()
{
    renderTitle(MSG_BY_MODEL_TITLE);
    return;
}

void renderSearchByPriceTitle()
{
    renderTitle(MSG_BY_PRICE_TITLE);
    return;
}

void renderSearchByFuelConsumptionTitle()
{
    renderTitle(MSG_BY_FUEL_TITLE);
    return;
}

void renderSearchByLongTermQualityTitle()
{
    renderTitle(MSG_BY_QUALITY_TITLE);
    return;
}

void renderSearchByComfortTitle()
{
    renderTitle(MSG_BY_COMFORT_TITLE);
    return;
}

void renderSearchResultTitle()
{
    renderTitle(MSG_FOUND_TITLE);
    return;
}

void renderNotFoundMsg()
{
    renderTitle(MSG_NOT_FOUND);
    return;
}

void renderSortedMsg()
{
    renderTitle(MSG_SORTED);
    return;
}

void renderSavedMsg()
{
    renderTitle(MSG_SAVED);
    return;
}

/**
 * Функция вывода на экран головной строки списка автомобилей.
 */
void renderCarsListHeader()
{
    printf(
        PATTERN_LIST_HEADER,
        COLUMN_NUMBER,
        COLUMN_MODEL,
        COLUMN_PRICE,
        COLUMN_FUEL,
        COLUMN_QUALITY,
        COLUMN_COMFORT
    );
    hr();
    return;
}

/**
 * Функция вывода на экран одной строки списка автомобилей.
 * number - параметр-константа типа integer (номер строки)
 * car - параметр-константа типа vehicle (структура с информацией об автомобиле)
 */
void renderCarsListRow(const unsigned int number, const vehicle car)
{
    printf(
        PATTERN_LIST_ROW,
        number,
        car.model,
        car.price,
        car.fuelConsumption,
        car.longTermQuality,
        car.comfort
    );
    return;
}

/**
 * Функция вывода на экран одной строки списка найденных автомобилей.
 * number - параметр-константа типа integer (номер строки)
 * car - параметр-константа типа vehicle (структура с информацией об автомобиле)
 */
void renderSearchResult(const unsigned int number, const vehicle car)
{
    if (number == 1) {
        renderSearchResultTitle();
        renderCarsListHeader();
    }
    renderCarsListRow(number, car);
    return;
}

/**
 * Функция вывода на экран выбора действия после поиска автомобилей.
 * number - параметр-константа типа integer (количество найденных автомобилей)
 */
void renderSearchResultFooter(const unsigned int number)
{
    if (number == 0) {
        renderNotFoundMsg();
    } else {
        hr();
    }
    BR;
    puts(MSG_SEARCH_REPEAT);
    puts(MSG_RETURN_TO_MENU);
    return;
}

/**
 * Функция, реализующая возврат в главное меню программы.
 */
void returnToMainMenu()
{
    BR;
    puts(MSG_RETURN_TO_MENU);
    while (getchar() != ITEM_0) {}
    return;
}

/**
 * Функция отображения главного меню программы.
 * listSize - параметр-константа типа integer
 * (количество элементов динамического списка)
 * catalogSize - параметр-константа типа integer
 * (количество элементов типизированного файла каталога)
 */
void displayMainMenu(const unsigned int listSize, const unsigned int catalogSize)
{
    system(CALL_CLEAR);
    BR;

    // Для пустого списка можно только добавить новый элемент
    if (listSize > 0) {
        renderListTitle();
        puts(MSG_SELECT_ACTION);
        BR;
        puts(MSG_DISPLAY_CATALOG);
        puts(MSG_ADD_CAR);
        puts(MSG_REMOVE_CAR);
        puts(MSG_SEARCH_BY_WISHES);
        puts(MSG_SEARCH_BY_FIELD);
        puts(MSG_SORT_BY_ALPHABET);
    } else {
        renderEmptyListTitle();
        puts(MSG_SELECT_ACTION);
        BR;
        puts(MSG_ADD_CAR);
    }
    BR;
    if (listSize > 0 || catalogSize > 0) {
        puts(MSG_SAVE_CATALOG);
    }
    puts(MSG_APP_EXIT);
    BR;
    hr();
    printString(MSG_DO_SELECT);
    return;
}

