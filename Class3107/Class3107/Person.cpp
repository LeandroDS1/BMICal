#include "Person.h"

void Person::input() 
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter surname: ";
    cin >> surname;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter height (in cm): ";
    cin >> height;
    cout << "Enter weight (in kg): ";
    cin >> weight;
}

double Person::calculateBMI() const
{
    double heightInMeters = height / 100;
    return weight / (heightInMeters * heightInMeters);
}

string Person::getBMICategory() const
{
    double bmi = calculateBMI();
    if (bmi < 18.5) 
    {
        return "Underweight";
    }
    else if (bmi < 24.9) 
    {
        return "Normal weight";
    }
    else if (bmi < 29.9) 
    {
        return "Overweight";
    }
    else {
        return "Obese";
    }
}

void Person::printInfo() const {  
    cout << "Name: " << name << endl;
    cout << "Surname: " << surname << endl;
    cout << "Age: " << age << endl;
    cout << "ID: " << id << endl;
    cout << "Height: " << height << " cm" << endl;
    cout << "Weight: " << weight << " kg" << endl;
    cout << fixed << setprecision(1) << "BMI: " << calculateBMI() << endl;
    cout << "Category: " << getBMICategory() << endl;
}
