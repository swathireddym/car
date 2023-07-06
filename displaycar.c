//The code defines a function displayCars that displays the cars parked in the car park.
It checks if the car park is empty by checking the head variable. If the car park is empty, it prints a corresponding message. 
Otherwise, it traverses the linked list of cars and prints the slot number, car number, owner name, and parking time for each car.//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carpark.h"

extern struct Car* head; // Declaration of head variable

void displayCars() {
    if (head == NULL) {
        printf("Car park lot is empty.\n");
        return;
    }

    struct Car* current = head;
    printf("Cars parked in the car park:\n");

    while (current != NULL) {
        double parkingTime = calculateParkingTime(current->timestamp);
        printf("Slot number: %d, Car number: %s, Owner: %s, Parking time: %.2f hours\n",
               current->slotNumber, current->carNumber, current->ownerName, parkingTime);
        current = current->next;
    }
}
