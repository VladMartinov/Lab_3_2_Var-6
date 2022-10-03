#pragma once

#include <string>
// —обственный enum 
#include "color.h"
#include "IFuelConsumer.h"

using namespace std;

class Car : public IFuelConsumer
{
public:
    // ================================== конструкторы/деструктор

    Car();

    Car(int mileage);

    Car(const string& make,
        const string& model,
        const string& no,
        int mileage,
        Color color,
        short year);

    Car(const Car& vehicles);

    virtual ~Car();

    // ========================================== сеттеры/геттеры

    void setCompany(const string& company);
    void setModel(const string& model);
    void setNo(const string& no);
    void setMileage(int mileage);
    void setColor(Color color);
    void setYear(short year);

    string getTypeOfClass() const;
    string getCompany() const;
    string getModel() const;
    string getNo() const;
    int getMileage() const;
    Color getColor() const;
    short getYear() const;
    //int getCount() const;

    // ========================================== запись/ччтение файла

    void serialize(Car** array) const;
    void serialize(const string& filename, Car** array) const;
    void deserialize(Car** array);
    void deserialize(const string& filename, Car** array);


public:
    // метод по заданию - путеществие на машине
    void longTravel() const;
    // вывод на консоль значений элементов машины
    void print() const;
    // вывод отсортированного массива по заданию
    void sortedPrint(Car** array) const;

    // вызов записи и чтени€ всех элементов класса
    void write(ostream& f) const;
    void read(istream& f);

protected:

    // ========================================== запись/ччтение переменных разных типов

    static void writeStr(const string& s, ostream& f);
    static void writeStr(int mileage_, ostream& f);
    static void writeStr(Color color_, ostream& f);
    static void writeStr(short year_, ostream& f);
    static void writeStr(double consumption_, ostream& f);

    void readStr(string& s, istream& f);
    void readStr(int mileage_, istream& f);
    void readStr(Color color_, istream& f);
    void readStr(short year_, istream& f);
    void readStr(double consumption_, istream& f);


protected:

    // Ёлементы класса
    string typeOfClass_ = "Car";
    double consumption_;
    string company_;
    string model_;
    string no_;
    mutable int mileage_;
    Color color_;
    short year_;
    //static int Count;
};