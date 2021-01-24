/**
 * Программное средство каталога автомобилей.
 * Разработчик - Дубинин А. В.
 * 08.03.2017
 */

#ifndef VIEW_H
#define VIEW_H

/*
 * Прототипы функций
 */
void hr();
void toUpCase(char *str);
void printString(const char *str);
void renderTitle(const char *title);
void renderListTitle();
void renderEmptyListTitle();
void renderAddCarTitle();
void renderRemoveCarTitle();
void renderSearchByWishesTitle();
void renderSearchByFieldTitle();
void renderSearchByModelTitle();
void renderSearchByPriceTitle();
void renderSearchByFuelConsumptionTitle();
void renderSearchByLongTermQualityTitle();
void renderSearchByComfortTitle();
void renderSearchResultTitle();
void renderNotFoundMsg();
void renderSortedMsg();
void renderSavedMsg();
void renderCarsListHeader();
void renderCarsListRow(const unsigned int number, const vehicle car);
void renderSearchResult(const unsigned int number, const vehicle car);
void renderSearchResultFooter(const unsigned int number);
void returnToMainMenu();
void displayMainMenu(const unsigned int listSize, const unsigned int catalogSize);

#endif

