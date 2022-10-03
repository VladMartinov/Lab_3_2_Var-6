#include <iostream>
#include "MicroBus.h"
#include <fstream>

// Деструктор
MicroBus::~MicroBus()
{
    cout << "   Micro Bus #" << no_ << " has been removed" << endl;
}

MicroBus::MicroBus()
{
    typeOfClass_ = "MicroBus";
    model_ = "unknown";
    company_ = "unknown";
    no_ = "x000xx";
    mileage_ = 0;
    color_ = Color::BLACK;
    year_ = 2017;
    consumption_ = 35.7;

    //Count++;


    std::cout << "Micro Bus #" << no_ << " has been added" << std::endl;
}

// Основной перегруженный - со всеми данными
MicroBus::MicroBus(const string& company,
    const string& model,
    const string& no,
    int mileage,
    Color color,
    short year)
    // сам список инициализации
{
    typeOfClass_ = "MicroBus";
    company_ = company;
    model_ = model;
    no_ = no;
    mileage_ = mileage;
    color_ = color;
    year_ = year;
    consumption_ = 35.7;
    //Count++;
    std::cout << "Micro Bus #" << no_ << " has been added" << std::endl;
}

// Перегруженный конструктор с одним параметром

MicroBus::MicroBus(int mileage)
    : MicroBus("unknown", "unknown", "x000xx", mileage, Color::BLACK, 2017)
{
    //Count++;
}

// Конструктор копирования
MicroBus::MicroBus(const MicroBus& vehicles) {
    typeOfClass_ = vehicles.typeOfClass_;
    model_ = vehicles.model_;
    company_ = vehicles.company_;
    no_ = vehicles.no_;
    mileage_ = vehicles.mileage_;
    color_ = vehicles.color_;
    year_ = vehicles.year_;
    consumption_ = 35.7;
    //Count++;
}


// Переопределенный метод по заданию (расчет потребленного топлива)
double MicroBus::consume(double distance_passed) {
    cout << "\n     Пройденная дистанция: " << distance_passed << endl;
    cout << "\n     Расход микро автобуса марки "<< company_ << ": " << consumption_ << endl;
    cout << "\n     Расчеты..." << endl;
    double fuelSpend = (distance_passed / 100) * consumption_;
    cout << "\n     Авто израсходовал: " << fuelSpend << "л. топлива." << endl;
    return fuelSpend;

}
