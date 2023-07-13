//The code includes functions for calculating parking time and fee, saving data to a file, and loading data from a file.

The calculateParkingTime function calculates the parking time in hours by taking the parked time as input and comparing it with the current time. It returns the calculated parking time.

The calculateParkingFee function takes the parking time as input and calculates the parking fee by multiplying it with a predefined parking rate per hour.

The saveData function saves the car park data to a specified file. It opens the file in write mode, iterates over the linked list of cars, and writes the slot number, car number, owner name, and timestamp to the file.

The loadData function loads car park data from a specified file. It opens the file in read mode, reads each line, and extracts the slot number, car number, owner name, and timestamp. It then creates a new car node with the extracted data and adds it to the linked list.
The code provides functionality for calculating parking time and fee, saving data to a file, and loading data from a file in the car park management system.//

#include <stdio.h> // Include standard input/output library
#include <stdlib.h> // Include standard library
#include <string.h> // Include string manipulation functions
#include "carpark.h" // Include carpark.h header file

extern struct Car* head; // Declaration of head variable

double calculateParkingTime(time_t parkedTime) {
    time_t currentTime = time(NULL); // Get the current time
    double diffInSeconds = difftime(currentTime, parkedTime); // Calculate the difference in seconds between the current time and the parked time
    double diffInHours = diffInSeconds / 3600; // Convert the difference to hours
    return diffInHours; // Return the parking time in hours
}

double calculateParkingFee(double parkingTime) {
    return parkingTime * PARKING_RATE_PER_HOUR; // Calculate the parking fee by multiplying the parking time with the predefined rate per hour
}

void saveData(const char* filename) {
    FILE* file = fopen(filename, "w"); // Open the specified file in write mode
    if (file == NULL) { // Check if the file opening was successful
        printf("Error opening file for writing.\n");
        return;
    }

    struct Car* current = head; // Start from the head of the car park linked list
    while (current != NULL) { // Iterate through each car in the linked list
        fprintf(file, "%d,%s,%s,%ld\n", current->slotNumber, current->carNumber,
                current->ownerName, (long)current->timestamp); // Write the car details to the file in the specified format
        current = current->next; // Move to the next car
    }

    fclose(file); // Close the file
    printf("Data saved successfully to %s.\n", filename); // Display success message
}

void loadData(const char* filename) {
    FILE* file = fopen(filename, "r"); // Open the specified file in read mode
    if (file == NULL) { // Check if the file opening was successful
        printf("Error opening file for reading.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) { // Read each line from the file
        int slotNumber;
        char carNumber[20];
        char ownerName[50];
        time_t timestamp;

        sscanf(line, "%d,%[^,],%[^,],%ld\n", &slotNumber, carNumber, ownerName, &timestamp); // Parse the line to extract the car details

        struct Car* newCar = (struct Car*)malloc(sizeof(struct Car)); // Allocate memory for a new Car struct
        newCar->slotNumber = slotNumber; // Assign the slot number
        strncpy(newCar->carNumber, carNumber, sizeof(newCar->carNumber)); // Copy the car number
        strncpy(newCar->ownerName, ownerName, sizeof(newCar->ownerName)); // Copy the owner's name
        newCar->timestamp = timestamp; // Assign the timestamp
        newCar->next = NULL; // Set the next pointer to NULL

        if (head == NULL) { // If the car park is empty
            head = newCar; // Set the new car as the head of the linked list
        } else {
            struct Car* current = head; // Start traversing the linked list from the head
            while (current->next != NULL) { // Find the last car in the linked list
                current = current->next;
            }
            current->next = newCar; // Set the next pointer of the last car to the new car
        }
    }

    fclose(file); // Close the file
    printf("Data loaded successfully from %s.\n", filename); // Display success message
}
