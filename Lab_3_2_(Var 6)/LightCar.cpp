#include <iostream>
#include "LightCar.h"
#include <fstream>

// Деструктор
LightCar::~LightCar()
{
    cout << "   Light Car #" << no_ << " has been removed" << endl;
}

LightCar::LightCar()
{
    typeOfClass_ = "LightCar";
    model_ = "unknown";
    company_ = "unknown";
    no_ = "x000xx";
    mileage_ = 0;
    color_ = Color::BLACK;
    year_ = 2017;
    consumption_ = 12.5;

    //Count++;


    std::cout << "Light Car #" << no_ << " has been added" << std::endl;
}

// Основной перегруженный - со всеми данными
LightCar::LightCar(const string& company,
    const string& model,
    const string& no,
    int mileage,
    Color color,
    short year)
    // сам список инициализации
{
    typeOfClass_ = "LightCar";
    company_ = company;
    model_ = model;
    no_ = no;
    mileage_ = mileage;
    color_ = color;
    year_ = year;
    consumption_ = 12.5;
    //Count++;
    std::cout << "Light Car #" << no_ << " has been added" << std::endl;
}

// Перегруженный конструктор с одним параметром

LightCar::LightCar(int mileage)
    : LightCar("unknown", "unknown", "x000xx", mileage, Color::BLACK, 2017)
{
    //Count++;
}

// Конструктор копирования
LightCar::LightCar(const LightCar& vehicles) {
    typeOfClass_ = vehicles.typeOfClass_;
    model_ = vehicles.model_;
    company_ = vehicles.company_;
    no_ = vehicles.no_;
    mileage_ = vehicles.mileage_;
    color_ = vehicles.color_;
    year_ = vehicles.year_;
    consumption_ = 12.5;

    cout << "\nOperato copivonna\n";
    //Count++;
}

// Переопределенный метод по заданию (расчет потребленного топлива)
double LightCar::consume(double distance_passed) {
    cout << "\n     Пройденная дистанция: " << distance_passed << endl;
    cout << "\n     Расход легкового авто марки " << company_ << ": " << consumption_ << endl;
    cout << "\n     Расчеты..." << endl;
    double fuelSpend = (distance_passed / 100) * consumption_;
    cout << "\n     Авто израсходовал: " << fuelSpend << "л. топлива." << endl;
    return fuelSpend;

}
