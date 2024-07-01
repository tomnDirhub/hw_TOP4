#include <iostream>
#include <fstream>
#include <windows.h>
#include <time.h>
#include <string>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <vector>

using namespace std;

struct Employee {
    string lastName;
    int age;
};

void addEmployee(vector<Employee>& employees) {
    Employee newEmployee;
    cout << "Введите фамилию сотрудника: ";
    cin >> newEmployee.lastName;
    cout << "Введите возраст сотрудника: ";
    cin >> newEmployee.age;
    employees.push_back(newEmployee);
    cout << "Сотрудник добавлен.\n";
}

void editEmployee(vector<Employee>& employees) {
    string lastName;
    cout << "Введите фамилию сотрудника, данные которого хотите отредактировать: ";
    cin >> lastName;

    for (auto& employee : employees) {
        if (employee.lastName == lastName) {
            cout << "Введите новую фамилию сотрудника: ";
            cin >> employee.lastName;
            cout << "Введите новый возраст сотрудника: ";
            cin >> employee.age;
            cout << "Данные сотрудника обновлены.\n";
            return;
        }
    }

    cout << "Сотрудник с фамилией " << lastName << " не найден.\n";
}

void deleteEmployee(vector<Employee>& employees) {
    string lastName;
    cout << "Введите фамилию сотрудника, которого хотите удалить: ";
    cin >> lastName;

    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if (it->lastName == lastName) {
            employees.erase(it);
            cout << "Сотрудник удален.\n";
            return;
        }
    }

    cout << "Сотрудник с фамилией " << lastName << " не найден.\n";
}

void searchByLastName(const vector<Employee>& employees) {
    string lastName;
    cout << "Введите фамилию сотрудника для поиска: ";
    cin >> lastName;

    for (const auto& employee : employees) {
        if (employee.lastName == lastName) {
            cout << "Фамилия: " << employee.lastName << ", Возраст: " << employee.age << "\n";
            return;
        }
    }

    cout << "Сотрудник с фамилией " << lastName << " не найден.\n";
}

void printAllEmployees(const vector<Employee>& employees) {
    for (const auto& employee : employees) {
        cout << "Фамилия: " << employee.lastName << ", Возраст: " << employee.age << "\n";
    }
}

void saveToFile(const vector<Employee>& employees, const string& filename) {
    ofstream outputFile(filename);

    for (const auto& employee : employees) {
        outputFile << employee.lastName << " " << employee.age << "\n";
    }

    cout << "Список сотрудников сохранен в файл " << filename << ".\n";
}

void loadFromFile(vector<Employee>& employees, const string& filename) {
    ifstream inputFile(filename);

    if (!inputFile) {
        cout << "Не удалось открыть файл " << filename << ".\n";
        return;
    }

    employees.clear();
    string lastName;
    int age;

    while (inputFile >> lastName >> age) {
        Employee employee;
        employee.lastName = lastName;
        employee.age = age;
        employees.push_back(employee);
    }

    cout << "Список сотрудников загружен из файла " << filename << ".\n";
}

int main() {

    setlocale(LC_ALL, "rus");

    vector<Employee> employees;
    string file = "file.txt";

    loadFromFile(employees, file);

    int choice;


    cout << "\nВыберите пункт:\n";
    cout << "1. Добавить сотрудника\n";
    cout << "2. Редактировать данные сотрудника\n";
    cout << "3. Удалить сотрудника\n";
    cout << "4. Поиск сотрудника по фамилии\n";
    cout << "5. Вывести информацию обо всех сотрудниках\n";
    cout << "6. Сохранить список сотрудников в файл\n";
    cout << "0. Выход\n";
    cin >> choice;

    switch (choice) {
    case 1:
        addEmployee(employees);
        break;
    case 2:
        editEmployee(employees);
        break;
    case 3:
        deleteEmployee(employees);
        break;
    case 4:
        searchByLastName(employees);
        break;
    case 5:
        printAllEmployees(employees);
        break;
    case 6:
        saveToFile(employees, file);
        break;
    case 0:
        saveToFile(employees, file);
        cout << "До свидания!\n";
        break;
    default:
        cout << "Неверный выбор.\n";
    }

    return 0;
}
