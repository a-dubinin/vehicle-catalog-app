/**
 * Программное средство каталога автомобилей.
 * Разработчик - Дубинин А. В.
 * 08.03.2017
 */

#ifndef HANDLER_H
#define HANDLER_H

/*
 * Прототипы функций
 */
void doRepeatedAction(listPtr *index, actionType action);
listPtr formList(FILE *catalog);
unsigned int countListSize(listPtr *index);
void displayCarsList(listPtr *index);
void addCarsIntoList(listPtr *index);
void removeCarsFromList(listPtr *index);
void searchByWishes(listPtr *index);
void searchByField(listPtr *index);
void sortByAlphabet(listPtr *index);
unsigned int saveCatalog(listPtr *index);

#endif

