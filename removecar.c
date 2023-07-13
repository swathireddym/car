//The code defines a function removeCar that removes a car from the car park linked list based on the given slot number. 
It traverses the linked list to find the car with the specified slot number and removes it from the list. 
It also calculates the parking time and fee for the removed car.
The function returns 1 if the car is successfully removed, 0 if the car park is empty, and -1 if the car is not found in the specified slot number.//
#include <stdio.h> // Include standard input/output library
#include <stdlib.h> // Include standard library
#include <string.h> // Include string manipulation functions
#include "carpark.h" // Include carpark.h header file

extern struct Car* head; // Declare the head variable (assumes it's defined in another file)

int removeCar(int slotNumber) {
    if (head == NULL) { // If the car park is empty
        return 0; // Return 0 to indicate that no cars are parked in the car park
    }

    struct Car* current = head; // Start traversing the car park from the head
    struct Car* previous = NULL; // Keep track of the previous car in the linked list

    while (current != NULL && current->slotNumber != slotNumber) { // Find the car with the specified slot number
        previous = current;
        current = current->next;
    }

    if (current == NULL) { // If the car with the specified slot number is not found
        return -1; // Return -1 to indicate that the car was not found
    }

    double parkingTime = calculateParkingTime(current->timestamp); // Calculate the parking time for the removed car
    double parkingFee = calculateParkingFee(parkingTime); // Calculate the parking fee based on the parking time

    if (previous == NULL) { // If the car to be removed is the head of the linked list
        head = current->next; // Update the head to point to the next car
    } else {
        previous->next = current->next; // Update the previous car's next pointer to skip the current car
    }

    free(current); // Free the memory occupied by the removed car

    printf("Car in slot number %d removed successfully.\n", slotNumber); // Display removal success message
    printf("Parking time: %.2f hours\n", parkingTime); // Display the calculated parking time
    printf("Parking fee: %.2f rupees\n", parkingFee); // Display the calculated parking fee

    return 1; // Return 1 to indicate successful removal of the car
}


   
  
