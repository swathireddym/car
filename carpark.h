//The code defines a header file "carpark.h" that declares structures and functions related to a car park management system. 
It includes functions for parking a car, removing a car, displaying parked cars, calculating parking time and fees, as well as saving and loading data to/from files. 
The header file encapsulates the functionality of the car park system for use in other source files.//

#ifndef CAR_PARK_H // Header guard to prevent multiple inclusions
#define CAR_PARK_H

#include <stdio.h> // Include standard input/output library
#include <stdlib.h> // Include standard library
#include <string.h> // Include string manipulation functions
#include <time.h> // Include time-related functions
#include <ctype.h> // Include character type functions

#define PARKING_RATE_PER_HOUR 50 // Define a constant for the parking rate per hour

struct Car { // Define the Car structure
    int slotNumber; // Slot number of the car
    char carNumber[20]; // Car number
    char ownerName[50]; // Owner's name
    time_t timestamp; // Timestamp of when the car was parked
    struct Car* next; // Pointer to the next car in the linked list
};

struct Car* parkCar(const char* carNumber, const char* ownerName); // Function prototype for parking a car
int removeCar(int slotNumber); // Function prototype for removing a car
void displayCars(); // Function prototype for displaying parked cars
double calculateParkingTime(time_t parkedTime); // Function prototype for calculating parking time
double calculateParkingFee(double parkingTime); // Function prototype for calculating parking fee
void saveData(const char* filename); // Function prototype for saving car park data to a file
void loadData(const char* filename); // Function prototype for loading car park data from a file

#endif // End of header guard
