
#include <iostream>
#include <chrono>
#include "Person.h"
#include "Util.h"

using namespace std;

void displayMenu() 
{
    cout << "1. Linear Search\n";
    cout << "2. Binary Search\n";
    cout << "3. Bubble Sort\n";
    cout << "4. Insertion Sort\n";
    cout << "Enter your choice: ";
}

void printPersons(const Person persons[], int size) 
{
    for (int i = 0; i < size; ++i) {
        persons[i].printInfo();
        cout << "-------------------\n";
    }
}

int main() 
{
    const int NUM_PERSONS = 30;
    Person persons[NUM_PERSONS];

    for (int i = 0; i < NUM_PERSONS; ++i) {
        cout << "Enter details for person " << i + 1 << " (name surname age id height weight): " << endl;
        persons[i].input();
    }

    bool isSorted = false;

    while (true) 
    {
        displayMenu();
        int choice;
        cin >> choice;

        auto start = chrono::high_resolution_clock::now();

        if (choice == 1)
        {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            int index = Util::linearSearch(persons, NUM_PERSONS, id);
            if (index != -1) {
                cout << "Person found: ";
                persons[index].printInfo();
            }
            else {
                cout << "Person not found" << endl;
            }
        }
        else if (choice == 2) 
        {
            if (!isSorted) 
            {
                cout << "Sorting array using Bubble Sort for Binary Search...\n";
                Util::bubbleSort(persons, NUM_PERSONS);
                isSorted = true;
            }

            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            int index = Util::binarySearch(persons, NUM_PERSONS, id);
            if (index != -1) {
                cout << "Person found: ";
                persons[index].printInfo();
            }
            else {
                cout << "Person not found" << endl;
            }
        }
        else if (choice == 3) 
        {
            auto sortStart = chrono::high_resolution_clock::now();
            Util::bubbleSort(persons, NUM_PERSONS);
            auto sortFinish = chrono::high_resolution_clock::now();
            auto sortMicroseconds = chrono::duration_cast<chrono::microseconds>(sortFinish - sortStart);
            cout << "Array sorted using Bubble Sort in " << sortMicroseconds.count() << "µs\n";
            isSorted = true;
        }
        else if (choice == 4) 
        {
            auto sortStart = chrono::high_resolution_clock::now();
            Util::insertionSort(persons, NUM_PERSONS);
            auto sortFinish = chrono::high_resolution_clock::now();
            auto sortMicroseconds = chrono::duration_cast<chrono::microseconds>(sortFinish - sortStart);
            cout << "Array sorted using Insertion Sort in " << sortMicroseconds.count() << "µs\n";
            isSorted = true;
        }
        else {
            cout << "Invalid choice, please try again." << endl;
            continue;
        }

        auto finish = chrono::high_resolution_clock::now();
        auto microseconds = chrono::duration_cast<chrono::microseconds>(finish - start);
        cout << "Operation took " << microseconds.count() << "µs\n";

        cout << "Do you want to perform another operation? y or n: ";
        char cont;
        cin >> cont;
        if (cont == 'n' || cont == 'N') {
            break;
        }
    }

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
