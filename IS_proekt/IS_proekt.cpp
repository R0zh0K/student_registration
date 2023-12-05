#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


struct Student {
    string name;
    int age;
    string faculty;
    int course;
    int group_number;
};

void addStudent() {
    ofstream file("students.txt", ios::app);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла" << endl;
        return;
    }

    Student student;

    cout << "Введите имя студента: ";
    getline(cin, student.name);

    cout << "Введите возраст студента: ";
    cin >> student.age;

    cout << "Введите факультет студента: ";
    cin.ignore();
    getline(cin, student.faculty);

    cout << "Введите курс студента: ";
    cin >> student.course;

    cout << "Введите номер группы студента: ";
    cin >> student.group_number;

    file << student.name << "," << student.age << "," << student.faculty << "," << student.course << "," << student.group_number << endl;

    file.close();

    cout << "Информация о студенте успешно добавлена" << endl;
}

void displayStudents() {
    ifstream file("students.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, faculty;
        int age, course, group_number;
        getline(ss, name, ',');
        ss >> age;
        ss.ignore();
        getline(ss, faculty, ',');
        ss >> course;
        ss.ignore();
        ss >> group_number;
        cout << "Имя: " << name << endl;
        cout << "Возраст: " << age << endl;
        cout << "Факультет: " << faculty << endl;
        cout << "Курс: " << course << endl;
        cout << "Номер группы: " << group_number << endl;
        cout << endl;
    }

    file.close();
}

int main() {
    setlocale(LC_ALL, "Russian");
    char choice;
    do {
        cout << "1. Добавить информацию о студенте" << endl;
        cout << "2. Вывести информацию о студентах" << endl;
        cout << "3. Выйти" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case '1':
            addStudent();
            break;
        case '2':
            displayStudents();
            break;
        case '3':
            cout << "Программа завершена" << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте еще раз" << endl;
            break;
        }

        cout << endl;

    } while (choice != '3');

    return 0;
}