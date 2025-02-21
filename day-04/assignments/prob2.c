#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARS 100
#define MAX_MODEL_LEN 50

typedef union {
    float daily_rent;
    float total_rent;
} Rent;


typedef struct {
    int car_id;
    char model[MAX_MODEL_LEN];
    Rent rent;
    int is_daily_rent; // Flag: 1 for daily, 0 for total
} Car;

int main() {
    int num_cars;
    Car cars[MAX_CARS];

    printf("Enter number of cars: ");
    scanf("%d", &num_cars);

    if (num_cars > MAX_CARS) {
        printf("Too many cars. Maximum is %d.\n", MAX_CARS);
        return 1;
    }


    for (int i = 0; i < num_cars; i++) {
        printf("Car %d: ", i + 1);
        char rent_type[10]; // To store "/day" or "/total" temporarily
        scanf("%d, %[^,], ₹%f/%s", &cars[i].car_id, cars[i].model, &cars[i].rent.daily_rent, rent_type);  //Initialize to daily rent first.

        if (strcmp(rent_type, "day") == 0) {
            cars[i].is_daily_rent = 1;
        } else if (strcmp(rent_type, "total") == 0) {
            cars[i].is_daily_rent = 0;
            
            cars[i].rent.total_rent = cars[i].rent.daily_rent; // Assuming input is still in daily format if total is given.
        } else {
            printf("Invalid rent type. Assuming daily rent.\n");
            cars[i].is_daily_rent = 1;
        }
    }

 
    printf("\nCars Available:\n");
    for (int i = 0; i < num_cars; i++) {
        printf("%d. %s - ₹%.2f/%s\n", i + 1, cars[i].model, 
               cars[i].rent.daily_rent, cars[i].is_daily_rent ? "day" : "total"); // ternary operator for output
    }

    
    FILE *fp = fopen("car_rentals.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    for (int i = 0; i < num_cars; i++) {
        fprintf(fp, "%d,%s,%.2f,%d\n", cars[i].car_id, cars[i].model, cars[i].rent.daily_rent, cars[i].is_daily_rent);
    }
    fclose(fp);

    printf("\nData saved in \"car_rentals.txt\"\n");

    

    return 0;
}
