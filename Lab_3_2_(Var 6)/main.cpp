#include "auto.h"
#include "LightCar.h"
#include "MicroBus.h"
#include <fstream>
#include <iostream>

using namespace std;

// Модернезированный код из Лабораторной работы №2 номер 3. Весь код был описан в той лабораторноей работе, здесь будет описаны его модернизированные части

int main() {
    setlocale(LC_ALL, "Russian");


    Car* array[6];

    cout << "\n===================== OPEN THE FILE  =====================\n";
    // Вызов метода для считывания данных из файла
    array[0]->deserialize(array);

    // Вывод значений после считывания данных из файла
    array[0]->print();
    array[1]->print();
    array[2]->print();
    array[3]->print();
    array[4]->print();
    array[5]->print();

    cout << "\n===================== CLOSE THE FILE =====================\n";

    //  создаем пустой ОБЪЕКТ КЛАССА LightCar на стеке
    array[0] = new LightCar();

    //  создаем ОБЪЕКТ КЛАССА LightCar на стеке
    array[1] = new LightCar("Ford", "Focus", "e888ap", 10250, Color::BLUE, 2010);

    //   создаем ОБЪЕКТ КЛАССА MicroBus на стеке : вызовется конструктор с одним параметром
    array[2] = new MicroBus(4000);


    // Установление параметров для объекта
    array[2]->setCompany("KamAZ");
    array[2]->setModel("NewModel");
    array[2]->setNo("o379ac");
    array[2]->setColor(Color::RED);
    array[2]->setYear(2005);


    //    создаем ОБЪЕКТ КЛАССА LightCar на стеке
    array[3] = new LightCar("Toyota", "Lexus", "a777aa", 135000, Color::GRAY, 2011);

    cout << "\nПробег лексуса до путешетсвия: " << array[3]->getMileage() << "\n";

    // Вызов метода по заданию из Лаб.2
    array[3]->longTravel();

    cout << "\nПробег лексуса после путешетсвия: " << array[3]->getMileage() << " (полюбому скрутил)\n";

    cout << "Отправляемся в еще 2 путеществия: \n";

    array[3]->longTravel();
    array[3]->longTravel();

    cout << "\nПробег лексуса после 2-х путешетсвий: " << array[3]->getMileage() << " (полюбому скрутил)\n";


    cout << endl;
    // Вывод на экран объектов массива
    array[0]->print();
    array[1]->print();
    array[2]->print();
    array[3]->print();

    // Создание еще 2-х объектов для точной проверки работоспособности Отсортированного вывода
    array[4] = new MicroBus("ACrob", "Zenva", "p324ad", 103242, Color::BLUE, 2011);
    array[5] = new MicroBus("Zesord", "Banvo", "g212rp", 30000, Color::BLUE, 2016);

    cout << endl;

    LightCar().print();
    std::cout << std::endl;

    LightCar("VAZ", "2109", "c111cc", 205000, Color::BLACK, 2007).print();
    std::cout << std::endl;


    // Метод для расчета потребления топлива (по заданию)
    array[3]->consume(1235.4);
    array[4]->consume(1235.4);


    cout << "\nSORTED TEST\n";
    // Вызов сортировочного метода
    array[0]->sortedPrint(array);


    cout << "\n Remove the main array: \n";


    // Очистка файда
    fstream clear_file("myFile.txt", ios::out);
    clear_file.close();

    // Запись данных в файл
    array[0]->serialize(array);

    //cout << "Count of objects : " << array[0].getCount() << " \n";\

    // Очистка памяти
    for (int i = 0; i < 6; ++i)
        delete array[i];

    return 0;
}
