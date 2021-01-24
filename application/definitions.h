/**
 * Программное средство каталога автомобилей.
 * Разработчик - Дубинин А. В.
 * 08.03.2017
 */

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// Объявление макроса (перевод курсора на новую строку)
#define BR putchar('\n')

// Объявление символических констант
#define CALL_CLEAR         "clear"
#define CATALOG_FILE       "vehicle_catalog.dat"
#define CATALOG_READ_MODE  "a+b"
#define CATALOG_WRITE_MODE "wb"
#define WINDOW_WIDTH       79
#define MODEL_NAME_SIZE    50
#define NULL_TERMINATED    '\0'
#define HYPHEN             '-'
#define ITEM_0             '0'
#define ITEM_1             '1'
#define ITEM_2             '2'
#define ITEM_3             '3'
#define ITEM_4             '4'
#define ITEM_5             '5'
#define ITEM_6             '6'
#define ITEM_9             '9'

// Объявление символических констант (сообщения пользовательского интерфейса)
#define MSG_CATALOG_TITLE       "Каталог автомобилей"
#define MSG_EMPTY_CATALOG_TITLE "Каталог автомобилей пуст"
#define MSG_ADD_CAR_TITLE       "Добавление автомобиля в каталог"
#define MSG_REMOVE_CAR_TITLE    "Удаление автомобиля из каталога"
#define MSG_BY_WISHES_TITLE     "Поиск в соответствии с требованиями покупателя"
#define MSG_BY_FIELD_TITLE      "Поиск в каталоге по полю"
#define MSG_BY_MODEL_TITLE      "Поиск по марке автомобиля"
#define MSG_BY_PRICE_TITLE      "Поиск по стоимости"
#define MSG_BY_FUEL_TITLE       "Поиск по расходу топлива"
#define MSG_BY_QUALITY_TITLE    "Поиск по надежности"
#define MSG_BY_COMFORT_TITLE    "Поиск по комфортности"
#define MSG_FOUND_TITLE         "Найденные в каталоге автомобили"
#define MSG_NOT_FOUND           "По вашему запросу ничего не найдено"
#define MSG_SORTED              "Каталог автомобилей отсортирован по алфавиту"
#define MSG_SAVED               "Изменения в каталоге успешно сохранены"
#define MSG_MEMORY_ERR          "Ошибка выделения памяти элементу списка"
#define MSG_SELECT_ACTION       "Выберите действие:"
#define MSG_DISPLAY_CATALOG     " 1 - вывести каталог на экран"
#define MSG_ADD_CAR             " 2 - добавить автомобиль в каталог"
#define MSG_REMOVE_CAR          " 3 - удалить автомобиль из каталога"
#define MSG_SEARCH_BY_WISHES    " 4 - поиск в каталоге по требованию"
#define MSG_SEARCH_BY_FIELD     " 5 - поиск в каталоге по полю"
#define MSG_SORT_BY_ALPHABET    " 6 - сортировка каталога по алфавиту"
#define MSG_SAVE_CATALOG        " 9 - сохранить изменения в каталоге"
#define MSG_APP_EXIT            " 0 - выйти из программы"
#define MSG_DO_SELECT           "(выберите пункт меню и нажмите клавишу ENTER) "
#define MSG_MODEL               " Марка автомобиля: "
#define MSG_PRICE               " Цена (USD): "
#define MSG_FUEL                " Расход топлива (литров / 100 км): "
#define MSG_QUALITY             " Надежность (лет): "
#define MSG_COMFORT             " Комфортность (баллов): "
#define MSG_ADD_SUCCESSFUL      "Автомобиль '%s' добавлен в список!\n"
#define MSG_ADD_CONTINUE        " 9 - продолжить добавление"
#define MSG_REMOVE_SELECT       "Введите № из списка для удаления: "
#define MSG_REMOVE_SUCCESSFUL   "Автомобиль '%s' удален из списка!\n"
#define MSG_REMOVE_CONTINUE     " 9 - продолжить удаление"
#define MSG_SEARCH_PRICE_MIN    " Минимальная цена (USD): "
#define MSG_SEARCH_PRICE_MAX    " Максимальная цена (USD): "
#define MSG_SEARCH_FUEL_MIN     " Минимальный расход топлива (литров / 100 км): "
#define MSG_SEARCH_FUEL_MAX     " Максимальный расход топлива (литров / 100 км): "
#define MSG_SEARCH_QUALITY_MIN  " Минимальное число лет безотказной работы: "
#define MSG_SEARCH_QUALITY_MAX  " Максимальное число лет безотказной работы: "
#define MSG_SEARCH_COMFORT_MIN  " Минимальная комфортность (баллов): "
#define MSG_SEARCH_COMFORT_MAX  " Максимальная комфортность (баллов): "
#define MSG_SEARCH_BY_MODEL     " 1 - марка автомобиля"
#define MSG_SEARCH_BY_PRICE     " 2 - стоимость"
#define MSG_SEARCH_BY_FUEL      " 3 - расход топлива"
#define MSG_SEARCH_BY_QUALITY   " 4 - надежность"
#define MSG_SEARCH_BY_COMFORT   " 5 - комфортность"
#define MSG_SEARCH_SELECT       "Выберите № поля, по которому будет осуществлен поиск"
#define MSG_SEARCH_REPEAT       " 9 - повторить поиск"
#define MSG_RETURN_TO_MENU      " 0 - возврат в главное меню "

#define COLUMN_NUMBER  "№ | "
#define COLUMN_MODEL   "Марка | "
#define COLUMN_PRICE   "Цена | "
#define COLUMN_FUEL    "Расход | "
#define COLUMN_QUALITY "Надёжность | "
#define COLUMN_COMFORT "Комфорт"

#define PATTERN_TITLE         " %s\n\n"
#define PATTERN_LIST_ROW      "%3u | %-30s | %7lu | %6.2f | %10u | %7u\n"
#define PATTERN_LIST_HEADER   "%8s%38s%14s%s%s%s\n"
#define PATTERN_FULL_STR      "%[^\n]s"
#define PATTERN_STR           "%s"
#define PATTERN_UNSIGNED_LONG "%lu"
#define PATTERN_FLOAT         "%f"
#define PATTERN_UNSIGNED      "%u"

#endif
