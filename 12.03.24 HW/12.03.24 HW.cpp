#include <iostream>
using namespace std;

class Transport {
protected:
    virtual void output() = 0;
    virtual double fuelConsumption() = 0;
    virtual double getCost() = 0;
    virtual void setCost(double cost) = 0;
    virtual int getCapacity() = 0;
    virtual int getSeats() = 0;
public:
    void displayOutput() {
        output();
    }
};

class Car : public Transport {
    double cost;
    int capacity;
    int seats;
public:
    Car() : cost(50000), capacity(1000), seats(5) {}
protected:
    void output() override {
        cout << "Car: " << "cost: " << cost << ", capacity: " << capacity << ", seats: " << seats << ", fuel consumption: " << fuelConsumption() << endl;
    }
public:
    double fuelConsumption() override {
        return capacity * 0.05;
    }
    double getCost() override {
        return cost;
    }
    void setCost(double cost) override {
        this->cost = cost;
    }
    void setCostPublic(double cost) {
        setCost(cost);
    }
    int getCapacity() override {
        return capacity;
    }
    int getSeats() override {
        return seats;
    }
};

class Plane : public Transport {
    double cost;
    int capacity;
    int seats;
public:
    Plane() : cost(4000000), capacity(15000), seats(300) {}
protected:
    void output() override {
        cout << "Aircraft: " << "cost: " << cost << ", capacity: " << capacity << ", seats: " << seats << ", fuel consumption: " << fuelConsumption() << endl;
    }
public:
    double fuelConsumption() override {
        return capacity * 0.3;
    }
    double getCost() override {
        return cost;
    }
    void setCost(double cost) override {
        this->cost = cost;
    }
    void setCostPublic(double cost) {
        setCost(cost);
    }
    int getCapacity() override {
        return capacity;
    }
    int getSeats() override {
        return seats;
    }
};

class Tank : public Transport {
    double cost;
    int capacity;
    int seats;
public:
    Tank() : cost(1000000), capacity(5000), seats(4) {}
protected:
    void output() override {
        cout << "Tank: " << "cost: " << cost << ", capacity: " << capacity << ", seats: " << seats << ", fuel consumption: " << fuelConsumption() << endl;
    }
public:
    double fuelConsumption() override {
        return capacity * 0.7;
    }
    double getCost() override {
        return cost;
    }
    void setCost(double cost) override {
        this->cost = cost;
    }
    void setCostPublic(double cost) {
        setCost(cost);
    }
    int getCapacity() override {
        return capacity;
    }
    int getSeats() override {
        return 0;
    }
};

void processTransports(Transport* transports[], int size) {
    for (int i = 0; i < size; i++) {
        transports[i]->displayOutput();
    }
}

int main() {
    const int SIZE = 3;
    Transport* transports[SIZE];

    int cost;

    cout << "Enter the cost for the Car: ";
    cin >> cost;

    Car* car = new Car();
    car->setCostPublic(cost);
    transports[0] = car;

    cout << "Enter the cost for the Plane: ";
    cin >> cost;

    Plane* plane = new Plane();
    plane->setCostPublic(cost);
    transports[1] = plane; 

    cout << "Enter the cost for the Tank: ";
    cin >> cost;

    Tank* tank = new Tank();
    tank->setCostPublic(cost);
    transports[2] = tank;

    processTransports(transports, SIZE);

    for (int i = 0; i < SIZE; i++) {
        delete transports[i];
    }
}
