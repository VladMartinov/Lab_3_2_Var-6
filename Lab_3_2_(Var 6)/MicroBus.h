#pragma once
#include <iostream>
#include "auto.h"
#include "LightCar.h"

class MicroBus : public Car {
public:
    // �����������, �����������
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

    // ��������������� ������ ��������������� �� Car (� � ���� ��������� ��������� IFuelConsumer)
    double consume(double distance_passed) override;


};