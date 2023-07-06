//The code defines a function parkCar that adds a new car to a car park linked list. 
It creates a new car node, assigns it a slot number, car number, owner name, and timestamp. 
Then it adds the new car to the end of the linked list. The function returns the newly added car node.//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carpark.h"

struct Car* head = NULL;
int currentSlotNumber = 1;

struct Car* parkCar(const char* carNumber, const char* ownerName) {
    struct Car* newCar = (struct Car*)malloc(sizeof(struct Car));
    newCar->slotNumber = currentSlotNumber++;
    strncpy(newCar->carNumber, carNumber, sizeof(newCar->carNumber));
    strncpy(newCar->ownerName, ownerName, sizeof(newCar->ownerName));
    newCar->timestamp = time(NULL);
    newCar->next = NULL;

    if (head == NULL) {
        head = newCar;
    } else {
        struct Car* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newCar;
    }

    return newCar;
}
