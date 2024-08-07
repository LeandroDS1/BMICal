#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Person
{
public:
    string name;
    string surname;
    int age;
    int id;
    double height;
    double weight;

    void input();
    double calculateBMI() const;
    string getBMICategory() const;
    void printInfo() const; 
};

#endif 
