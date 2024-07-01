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
    cout << "������� ������� ����������: ";
    cin >> newEmployee.lastName;
    cout << "������� ������� ����������: ";
    cin >> newEmployee.age;
    employees.push_back(newEmployee);
    cout << "��������� ��������.\n";
}

void editEmployee(vector<Employee>& employees) {
    string lastName;
    cout << "������� ������� ����������, ������ �������� ������ ���������������: ";
    cin >> lastName;

    for (auto& employee : employees) {
        if (employee.lastName == lastName) {
            cout << "������� ����� ������� ����������: ";
            cin >> employee.lastName;
            cout << "������� ����� ������� ����������: ";
            cin >> employee.age;
            cout << "������ ���������� ���������.\n";
            return;
        }
    }

    cout << "��������� � �������� " << lastName << " �� ������.\n";
}

void deleteEmployee(vector<Employee>& employees) {
    string lastName;
    cout << "������� ������� ����������, �������� ������ �������: ";
    cin >> lastName;

    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if (it->lastName == lastName) {
            employees.erase(it);
            cout << "��������� ������.\n";
            return;
        }
    }

    cout << "��������� � �������� " << lastName << " �� ������.\n";
}

void searchByLastName(const vector<Employee>& employees) {
    string lastName;
    cout << "������� ������� ���������� ��� ������: ";
    cin >> lastName;

    for (const auto& employee : employees) {
        if (employee.lastName == lastName) {
            cout << "�������: " << employee.lastName << ", �������: " << employee.age << "\n";
            return;
        }
    }

    cout << "��������� � �������� " << lastName << " �� ������.\n";
}

void printAllEmployees(const vector<Employee>& employees) {
    for (const auto& employee : employees) {
        cout << "�������: " << employee.lastName << ", �������: " << employee.age << "\n";
    }
}

void saveToFile(const vector<Employee>& employees, const string& filename) {
    ofstream outputFile(filename);

    for (const auto& employee : employees) {
        outputFile << employee.lastName << " " << employee.age << "\n";
    }

    cout << "������ ����������� �������� � ���� " << filename << ".\n";
}

void loadFromFile(vector<Employee>& employees, const string& filename) {
    ifstream inputFile(filename);

    if (!inputFile) {
        cout << "�� ������� ������� ���� " << filename << ".\n";
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

    cout << "������ ����������� �������� �� ����� " << filename << ".\n";
}

int main() {

    setlocale(LC_ALL, "rus");

    vector<Employee> employees;
    string file = "file.txt";

    loadFromFile(employees, file);

    int choice;


    cout << "\n�������� �����:\n";
    cout << "1. �������� ����������\n";
    cout << "2. ������������� ������ ����������\n";
    cout << "3. ������� ����������\n";
    cout << "4. ����� ���������� �� �������\n";
    cout << "5. ������� ���������� ��� ���� �����������\n";
    cout << "6. ��������� ������ ����������� � ����\n";
    cout << "0. �����\n";
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
        cout << "�� ��������!\n";
        break;
    default:
        cout << "�������� �����.\n";
    }

    return 0;
}
