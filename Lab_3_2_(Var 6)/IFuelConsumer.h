#pragma once

class IFuelConsumer {
public:
	// ����������� ����� �� �������
	virtual double consume(double distance_passed) = 0;
};