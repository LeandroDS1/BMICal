#include "Util.h"


int Util::linearSearch(Person persons[], int size, int id) 
{
    for (int i = 0; i < size; ++i) {
        if (persons[i].id == id) {
            return i;
        }
    }
    return -1; 
}


int Util::binarySearch(Person persons[], int size, int id) 
{
    int left = 0;
    int right = size - 1;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        if (persons[mid].id == id) {
            return mid;
        }
        if (persons[mid].id < id) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; 
}


void Util::bubbleSort(Person persons[], int size) 
{
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (persons[j].id > persons[j + 1].id) {
                Person temp = persons[j];
                persons[j] = persons[j + 1];
                persons[j + 1] = temp;
            }
        }
    }
}

void Util::insertionSort(Person persons[], int size)
{
    for (int i = 1; i < size; ++i) {
        Person key = persons[i];
        int j = i - 1;
        while (j >= 0 && persons[j].id > key.id) {
            persons[j + 1] = persons[j];
            j = j - 1;
        }
        persons[j + 1] = key;
    }
}

