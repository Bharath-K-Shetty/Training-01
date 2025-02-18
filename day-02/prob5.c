#include <stdio.h>
#include <string.h>

float calculateBill(char wardType, int days);

int main()
 {
    char patientName[50];
    char wardType;
    int days;

    printf("Enter Patient Name: ");
    scanf(" %s", patientName);

    printf("Enter Ward Type (G/S/P): ");
    scanf(" %c", &wardType);

    printf("Enter Number of Days: ");
    scanf("%d", &days);

    float totalBill = calculateBill(wardType, days);
    float discount = 0.0;

    if (days > 7)
    {
        discount = 0.05 * totalBill;
    }

    float finalBill = totalBill - discount;

    printf("\nPatient Name: %s\n", patientName);
    printf("Total Bill Before Discount: %.2f\n", totalBill);
    printf("Discount Applied: %.2f\n", discount);
    printf("Final Bill Amount: %.2f\n", finalBill);

    return 0;
}

float calculateBill(char wardType, int days)
{
    int dailyCharge;

    switch (wardType) {
        case 'G':
        case 'g':
            dailyCharge = 1000;
            break;
        case 'S':
        case 's':
            dailyCharge = 2000;
            break;
        case 'P':
        case 'p':
            dailyCharge = 5000;
            break;
        default:
            printf("Invalid ward type. Assuming General Ward.\n");
            break;
    }

    return (float)dailyCharge * days;
}
