/**
 * Программное средство каталога автомобилей.
 * Разработчик - Дубинин А. В.
 * 08.03.2017
 */

#ifndef TYPES_H
#define TYPES_H

// Объявление новой структуры и имени типа - vehicle
typedef struct {
    char               model[MODEL_NAME_SIZE]; // марка автомобиля
    unsigned long int  price;                  // цена, в USD
    float              fuelConsumption;        // расход топлива, в литрах/100км
    unsigned int       longTermQuality;        // надежность, в годах
    unsigned int       comfort;                // комфортность, в баллах
} vehicle;

/*
 * Объявление новой структуры node, описывающей элемент списка автомобилей,
 * и имени типа list
 */
typedef struct node {
    vehicle car;
    struct node *next;
} list;

// Объявление нового имени типа listPtr - указатель на список автомобилей
typedef list *listPtr;

// Объявление нового имени типа actionType - указатель на функцию
typedef void (*actionType) (listPtr *index);

#endif
