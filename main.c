//The code implements a simple car park management system. 
It allows users to park cars, remove cars, display parked cars, and save/load car park data.
It presents a menu to the user and performs the corresponding actions based on their choices. 
The code aims to provide basic functionality for managing a car park.//

  #include "carpark.h" // Include header file for car park functionality
#include <stdio.h> // Include standard input/output library
#include <stdlib.h> // Include standard library
#include <string.h> // Include string manipulation functions
#include "displaycar.c" // Include function for displaying parked cars
#include "parkcar.c" // Include function for parking a car
#include "removecar.c" // Include function for removing a car
#include "savedata.c" // Include function for saving data

int main() {
    int choice;
    char carNumber[20];
    char ownerName[50];

    loadData("car_park_data.txt"); // Load car park data from a file

    while (1) {
        printf("1. Park a car\n");
        printf("2. Remove a car\n");
        printf("3. Display parked cars\n");
        printf("4. Save data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read user's choice from input

        if (choice == 5) { // If the choice is 5, exit the program
            printf("Exiting the program.\n");
            break;
        } else if (choice < 1 || choice > 5) { // If the choice is invalid, ask for input again
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        switch (choice) {//switch is used to take control of a particular case
            case 1:
                printf("Enter the car number: ");
                scanf("%s", carNumber); // Read the car number from input

                if (atoi(carNumber) < 0) { // Check if the car number is valid
                    printf("Invalid car number. Please try again.\n");
                    break;
                }

                printf("Enter the owner's name: ");
                getchar();
                fgets(ownerName, sizeof(ownerName), stdin); // Read the owner's name from input
                ownerName[strcspn(ownerName, "\n")] = '\0'; // Remove the newline character

                int validCarNumber = 1;
                for (int i = 0; i < strlen(carNumber); i++) {
                    if (!isalnum(carNumber[i])) { // Check if the car number contains only alphanumeric characters
                        validCarNumber = 0;
                        break;
                    }
                }

                int validOwnerName = 1;
                for (int i = 0; i < strlen(ownerName); i++) {
                    if (!isalpha(ownerName[i]) && ownerName[i] != ' ') { // Check if the owner's name contains only alphabetic characters and spaces
                        validOwnerName = 0;
                        break;
                    }
                }

                if (!validCarNumber || !validOwnerName) { // If the input is invalid, display an error message
                    printf("Invalid input. Please try again.\n");
                } else {
                    struct Car* parkedCar = parkCar(carNumber, ownerName); // Park the car
                    printf("Car parked successfully in slot number %d.\n", parkedCar->slotNumber);
                }

                break;
            case 2:
                printf("Enter the slot number: ");
                int slotNumber;
                scanf("%d", &slotNumber); // Read the slot number from input

                int removalStatus = removeCar(slotNumber); // Remove the car from the specified slot number
                if (removalStatus == 0) {
                    printf("No cars parked in the car park.\n");
                } else if (removalStatus == -1) {
                    printf("Car not found in the specified slot number.\n");
                }

                break;
            case 3:
                displayCars(); // Display the parked cars
                break;
            case 4:
                saveData("car_park_data.txt"); // Save the car park data to a file
                break;
            default:
                break;
        }
    }

    return 0;
}
      
               
