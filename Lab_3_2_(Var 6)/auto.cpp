#include "auto.h"

#include <iostream>
#include <ctime>
#include <fstream>
#include "auto.h"
#include "LightCar.h"
#include "MicroBus.h"

using namespace std;

Car::Car()
{
    model_ = "unknown";
    company_ = "unknown";
    no_ = "x000xx";
    mileage_ = 0;
    color_ = Color::BLACK;
    year_ = 2017;
    //Count++;


    std::cout << "Car #" << no_ << " has been added" << std::endl;
}

// Основной перегруженный - со всеми данными
Car::Car(const string& company,
    const string& model,
    const string& no,
    int mileage,
    Color color,
    short year)
    // сам список инициализации
    : company_(company), model_(model), no_(no), mileage_(mileage), color_(color), year_(year), consumption_(0)

{
    //Count++;
    std::cout << "Car #" << no_ << " has been added" << std::endl;
}

// Перегруженный конструктор с одним параметром

Car::Car(int mileage)
    : Car("unknown", "unknown", "x000xx", mileage, Color::BLACK, 2017)
{
    //Count++;
}

// Конструктор копирования
Car::Car(const Car& vehicles) {
    model_ = vehicles.model_;
    company_ = vehicles.company_;
    no_ = vehicles.no_;
    mileage_ = vehicles.mileage_;
    color_ = vehicles.color_;
    year_ = vehicles.year_;

    //Count++;
}
// Деструктор
Car::~Car()
{
    //Count--;
    cout << "   Car #" << no_ << " has been removed" << endl;
}


// ==================== СЕТТЕРЫ / ГЕТТЕРЫ =======================

void Car::setCompany(const string& company)
{
    company_ = company;
}

void Car::setModel(const string& model)
{
    model_ = model;
}

void Car::setNo(const string& no)
{
    no_ = no;
}

void Car::setMileage(int mileage)
{
    mileage_ = mileage;
}

void Car::setColor(Color color)
{
    color_ = color;
}

void Car::setYear(short year)
{
    year_ = year;
}

string Car::getTypeOfClass() const 
{
    return typeOfClass_;
}

string Car::getCompany() const
{
    return company_;
}

string Car::getModel() const
{
    return model_;
}

string Car::getNo() const
{
    return no_;
}

int Car::getMileage() const
{
    return mileage_;
}

Color Car::getColor() const
{
    return color_;
}

short Car::getYear() const
{
    return year_;
}

//int Car::getCount() const {
//    return Count;
//}

// =========================================== Writer

void Car::writeStr(const string& s, ostream& f)
{
    size_t l = s.length();
    f.write((const char*)&l, sizeof(size_t));
    f.write(s.data(), l);
}

void Car::writeStr(int s, ostream& f)
{
    f.write((const char*)&s, sizeof(int));
}

void Car::writeStr(Color s, ostream& f)
{

    f.write((const char*)&s, sizeof(Color));
}

void Car::writeStr(short s, ostream& f)
{
    f.write((const char*)&s, sizeof(short));
}

void Car::writeStr(double s, ostream& f)
{
    f.write((const char*)&s, sizeof(double));
}

void Car::write(ostream& f) const
{
    writeStr(typeOfClass_, f);
    writeStr(company_, f);
    writeStr(model_, f);
    writeStr(no_, f);
    writeStr(mileage_, f);
    writeStr(color_, f);
    writeStr(year_, f);
    writeStr(consumption_, f);
}
// =========================================== Reader

void Car::readStr(string& s, istream& f)
{
    size_t l;
    f.read((char*)&l, sizeof(size_t));
    char* str = new char[l + 1];
    f.read(str, l);
    str[l] = 0;
    s = str;
    delete[] str;
}

void Car::readStr(int s, istream& f)
{
    f.read((char*)&mileage_, sizeof(int));
}

void Car::readStr(Color s, istream& f)
{
    f.read((char*)&color_, sizeof(Color));
}

void Car::readStr(short s, istream& f)
{
    f.read((char*)&year_, sizeof(short));
}

void Car::readStr(double s, istream& f)
{
    f.read((char*)&s, sizeof(double));
}


void Car::read(istream& f)
{
    readStr(company_, f);
    readStr(model_, f);
    readStr(no_, f);
    readStr(mileage_, f);
    readStr(color_, f);
    readStr(year_, f);
    readStr(consumption_, f);
}


// ====================== запись/чтение файла =============================


void Car::serialize(Car** array) const {
    string path = "myFile.txt";
    ofstream out(path, ios::binary);
    for (int i = 0; i < 6; i++) {
        array[i]->write(out);
    }

}

void Car::serialize(const std::string& filename, Car** array) const {
    string path = filename;

    ofstream out(path, ios::binary);
    for (int i = 0; i < 6; i++) {
        array[i]->write(out);
    }
}

void Car::deserialize(Car** array)
{
    string path = "myFile.txt";
    ifstream in(path, ios::binary);
    for (int i = 0; i < 6; i++) {
        string typeClass;
        readStr(typeClass, in);
        if (typeClass == "LightCar")
            array[i] = new LightCar();
        else
            array[i] = new MicroBus();

        array[i]->read(in);
    }
}

void Car::deserialize(const string& filename, Car** array) {
    string path = filename;

    ifstream in(path, ios::binary);
    for (int i = 0; i < 6; i++) {
        array[i]->read(in);
    }
}

// ====================== ОСТАЛЬНОЕ =============================

// Долгое путешествие по заданию
void Car::longTravel() const
{
    srand(time(0));

    int randomTravel = (rand() % 10000);

    cout << "\nОтправляемся в путишествие длинной : " << randomTravel << " .";

    mileage_ += randomTravel;
}

// вывод модели номера и компании машины на экран
void Car::print() const
{
    cout << "\n" << company_ << " " << model_ << " (" << no_ << ")" << endl;
}

// Вывод отсортированного массива по заданию
void Car::sortedPrint(Car** array) const {
    Car* arraySorted[6];
    for (int i = 0; i < 6; i++)
        arraySorted[i] = array[i];

    for (int i = 1; i < 6; i++)
        if (arraySorted[i]->year_ >= 2011)
            for (int j = 0; j < 6; j++)
                if (arraySorted[j]->mileage_ < arraySorted[i]->mileage_ || arraySorted[j]->year_ < 2011) {
                            // Обмен данных между двумя одинаковыми классами
                    if (arraySorted[j]->typeOfClass_ == arraySorted[i]->typeOfClass_)
                    {
                        if (arraySorted[i]->typeOfClass_ == "LightCar") {
                            Car* temp = new LightCar();
                            temp = arraySorted[j];
                            arraySorted[j] = arraySorted[i];
                            arraySorted[i] = temp;
                        }
                        else
                        {
                            Car* temp = new MicroBus();
                            temp = arraySorted[j];
                            arraySorted[j] = arraySorted[i];
                            arraySorted[i] = temp;
                        }
                    }
                    else
                    {
                        // Обмен данных между двумя разными (классы полностью переписыватся) классами
                        if (arraySorted[i]->typeOfClass_ == "LightCar") {
                            Car* temp = new LightCar();
                            temp = arraySorted[j];
                            arraySorted[j] = new MicroBus();
                            arraySorted[j] = arraySorted[i];
                            arraySorted[i] = new LightCar();
                            arraySorted[i] = temp;
                        }
                        else
                        {
                            Car* temp = new MicroBus();
                            temp = arraySorted[j];
                            arraySorted[j] = new LightCar();
                            arraySorted[j] = arraySorted[i];
                            arraySorted[i] = new MicroBus();
                            arraySorted[i] = temp;
                        }
                    }
                }

    for (int i = 1; i < 6; i++)
        if (arraySorted[i]->year_ < 2011)
            for (int j = 0; j < 6; j++) {
                if (arraySorted[j]->mileage_ < arraySorted[i]->mileage_ && arraySorted[j]->year_ < 2011) {
                    // Как и сверху
                    if (arraySorted[j]->typeOfClass_ == arraySorted[i]->typeOfClass_)
                    {
                        if (arraySorted[i]->typeOfClass_ == "LightCar") {
                            Car* temp = new LightCar();
                            temp = arraySorted[j];
                            arraySorted[j] = arraySorted[i];
                            arraySorted[i] = temp;
                        }
                        else
                        {
                            Car* temp = new MicroBus();
                            temp = arraySorted[j];
                            arraySorted[j] = arraySorted[i];
                            arraySorted[i] = temp;
                        }
                    }
                    else
                    {
                        // Также описано сверху
                        if (arraySorted[i]->typeOfClass_ == "LightCar") {
                            Car* temp = new LightCar();
                            temp = arraySorted[j];
                            arraySorted[j] = new MicroBus();
                            arraySorted[j] = arraySorted[i];
                            arraySorted[i] = new LightCar();
                            arraySorted[i] = temp;
                        }
                        else
                        {
                            Car* temp = new MicroBus();
                            temp = arraySorted[j];
                            arraySorted[j] = new LightCar();
                            arraySorted[j] = arraySorted[i];
                            arraySorted[i] = new MicroBus();
                            arraySorted[i] = temp;
                        }
                    }
                }
            }
    //Вывод на экран отсортированного массива
    for (int i = 0; i < 6; i++) {
        cout << "\n     YEAR : " << arraySorted[i]->year_ << "\n";
        cout << "     MILEAGE : " << arraySorted[i]->mileage_ << "\n";
        arraySorted[i]->print();
    }
}

//int Car::Count = 0;