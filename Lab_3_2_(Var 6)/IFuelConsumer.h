#pragma once

class IFuelConsumer {
public:
	// Виртуальный метод по заданию
	virtual double consume(double distance_passed) = 0;
};