#pragma once
#include <iostream>
#include "auto.h"
#include "MicroBus.h"

class LightCar : public Car {
public:
    // �����������, �����������
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


    // ��������������� ������ ��������������� �� Car (� � ���� ��������� ��������� IFuelConsumer)
    double consume(double distance_passed) override;


};