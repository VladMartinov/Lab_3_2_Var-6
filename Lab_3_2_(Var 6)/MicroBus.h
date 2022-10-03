#pragma once
#include <iostream>
#include "auto.h"
#include "LightCar.h"

class MicroBus : public Car {
public:
    // Конструктоы, деструкторы
    MicroBus();

    MicroBus(int mileage);

    MicroBus(const string& make,
        const string& model,
        const string& no,
        int mileage,
        Color color,
        short year);

    MicroBus(const MicroBus& vehicles);


    ~MicroBus() override;

    // Переопределения метода унаследованного от Car (а к нему подключен интерфейс IFuelConsumer)
    double consume(double distance_passed) override;


};