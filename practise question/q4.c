#include <stdio.h>
#include <string.h>

#define MAX_FLIGHTS 100

struct Flight {
    int flightNumber;
    char departureCity[50];
    char arrivalCity[50];
    char departureTime[50];
    char arrivalTime[50];
    int availableSeats;
};

void bookSeat(struct Flight flights[], int count) {
    int flightNumber;
    printf("Enter flight number to book a seat: ");
    scanf("%d", &flightNumber);

    for (int i = 0; i < count; i++) {
        if (flights[i].flightNumber == flightNumber) {
            if (flights[i].availableSeats > 0) {
                flights[i].availableSeats--;
                printf("Seat booked successfully! Remaining seats: %d\n", flights[i].availableSeats);
                return;
            } else {
                printf("No seats available on this flight.\n");
                return;
            }
        }
    }
    printf("Flight not found.\n");
}

void displayFlights(struct Flight flights[], int count, char depCity[], char arrCity[]) {
    int found = 0;
    printf("\nAvailable flights from %s to %s:\n", depCity, arrCity);
    for (int i = 0; i < count; i++) {
        if (strcasecmp(flights[i].departureCity, depCity) == 0 && strcasecmp(flights[i].arrivalCity, arrCity) == 0) {
            printf("Flight Number: %d\n", flights[i].flightNumber);
            printf("Departure Time: %s\n", flights[i].departureTime);
            printf("Arrival Time: %s\n", flights[i].arrivalTime);
            printf("Available Seats: %d\n\n", flights[i].availableSeats);
            found = 1;
        }
    }
    if (!found) {
        printf("No flights found between %s and %s.\n", depCity, arrCity);
    }
}

void updateFlightDetails(struct Flight flights[], int count) {
    int flightNumber;
    printf("Enter flight number to update: ");
    scanf("%d", &flightNumber);

    for (int i = 0; i < count; i++) {
        if (flights[i].flightNumber == flightNumber) {
            printf("Enter new departure city: ");
            scanf("%s", flights[i].departureCity);
            printf("Enter new arrival city: ");
            scanf("%s", flights[i].arrivalCity);
            printf("Enter new departure time: ");
            scanf("%s", flights[i].departureTime);
            printf("Enter new arrival time: ");
            scanf("%s", flights[i].arrivalTime);
            printf("Enter new number of available seats: ");
            scanf("%d", &flights[i].availableSeats);

            printf("Flight details updated successfully!\n");
            return;
        }
    }
    printf("Flight not found.\n");
}

int main() {
    struct Flight flights[MAX_FLIGHTS];
    int flightCount = 0;
    int choice;

    // Adding some initial flights manually
    flights[flightCount++] = (struct Flight){101, "NewYork", "LosAngeles", "08:00 AM", "11:00 AM", 50};
    flights[flightCount++] = (struct Flight){102, "NewYork", "LosAngeles", "02:00 PM", "05:00 PM", 30};
    flights[flightCount++] = (struct Flight){103, "SanFrancisco", "Chicago", "09:00 AM", "12:00 PM", 40};

    while (1) {
        printf("\nFlight Booking System\n");
        printf("1. Book a seat\n");
        printf("2. Display available flights\n");
        printf("3. Update flight details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            bookSeat(flights, flightCount);
        } else if (choice == 2) {
            char depCity[50], arrCity[50];
            printf("Enter departure city: ");
            scanf("%s", depCity);
            printf("Enter arrival city: ");
            scanf("%s", arrCity);
            displayFlights(flights, flightCount, depCity, arrCity);
        } else if (choice == 3) {
            updateFlightDetails(flights, flightCount);
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

