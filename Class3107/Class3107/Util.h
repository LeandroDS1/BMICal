#ifndef UTIL_H
#define UTIL_H

#include <string>
#include "Person.h"

class Util
{
public:
    static int linearSearch(Person persons[], int size, int id);
    static int binarySearch(Person persons[], int size, int id);
    static void bubbleSort(Person persons[], int size);
    static void insertionSort(Person persons[], int size);
};

#endif 
