#pragma once
#include <iostream>
#include "auto.h"
#include "MicroBus.h"

class LightCar : public Car {
public:
    // Конструктоы, деструкторы
    LightCar();

    LightCar(int mileage);

    LightCar(const string& make,
        const string& model,
        const string& no,
        int mileage,
        Color color,
        short year);

    LightCar(const LightCar& vehicles);


    ~LightCar() override;


    // Переопределения метода унаследованного от Car (а к нему подключен интерфейс IFuelConsumer)
    double consume(double distance_passed) override;


};