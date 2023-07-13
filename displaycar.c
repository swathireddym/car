//The code defines a function displayCars that displays the cars parked in the car park.
It checks if the car park is empty by checking the head variable. If the car park is empty, it prints a corresponding message. 
Otherwise, it traverses the linked list of cars and prints the slot number, car number, owner name, and parking time for each car.//
#include <stdio.h> // Include standard input/output library
#include <stdlib.h> // Include standard library
#include <string.h> // Include string manipulation functions
#include "carpark.h" // Include carpark.h header file

extern struct Car* head; // Declaration of head variable

void displayCars() {
    if (head == NULL) { // If the car park is empty
        printf("Car park lot is empty.\n"); // Display a message indicating that the car park is empty
        return;
    }

    struct Car* current = head; // Start from the head of the car park linked list
    printf("Cars parked in the car park:\n");

    while (current != NULL) { // Iterate through each car in the linked list
        double parkingTime = calculateParkingTime(current->timestamp); // Calculate the parking time for the current car
        printf("Slot number: %d, Car number: %s, Owner: %s, Parking time: %.2f hours\n",
               current->slotNumber, current->carNumber, current->ownerName, parkingTime); // Display the car details and parking time
        current = current->next; // Move to the next car
    }
}
