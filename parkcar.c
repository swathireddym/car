//The code defines a function parkCar that adds a new car to a car park linked list. 
It creates a new car node, assigns it a slot number, car number, owner name, and timestamp. 
Then it adds the new car to the end of the linked list. The function returns the newly added car node.//
#include <stdio.h> // Include standard input/output library
#include <stdlib.h> // Include standard library
#include <string.h> // Include string manipulation functions
#include "carpark.h" // Include carpark.h header file

struct Car* head = NULL; // Declare a pointer to the head of the car park linked list
int currentSlotNumber = 1; // Initialize the current slot number to 1

struct Car* parkCar(const char* carNumber, const char* ownerName) {
    struct Car* newCar = (struct Car*)malloc(sizeof(struct Car)); // Allocate memory for a new Car struct
    newCar->slotNumber = currentSlotNumber++; // Assign the current slot number to the new car and increment it for the next car
    strncpy(newCar->carNumber, carNumber, sizeof(newCar->carNumber)); // Copy the car number to the new car's carNumber field
    strncpy(newCar->ownerName, ownerName, sizeof(newCar->ownerName)); // Copy the owner's name to the new car's ownerName field
    newCar->timestamp = time(NULL); // Set the timestamp of the new car to the current time
    newCar->next = NULL; // Set the next pointer of the new car to NULL

    if (head == NULL) { // If the car park is empty
        head = newCar; // Set the new car as the head of the car park linked list
    } else {
        struct Car* current = head; // Start traversing the linked list from the head
        while (current->next != NULL) { // Find the last car in the linked list
            current = current->next;
        }
        current->next = newCar; // Set the next pointer of the last car to the new car
    }

    return newCar; // Return the newly parked car
}
