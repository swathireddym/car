#ifndef PARKING_H
#define PARKING_H

struct Car {
    int carNumber;
    char ownerName[50];
    struct Car* next;
};

typedef void (*CarFunction)();

void executeFunction(CarFunction function);
void parkCar();
void removeCar();
void displayCars();
void searchCarByNumber();
void searchCarByOwner();
void calculateExpectedTime();
void addCarToWaitingList();
void manageParking();
void makePayment();
void trackLocation();

#endif
