#include <stdio.h>

int main() {
    char Name[100];  
    int id;
    float unit;
    float base_bill = 100; // Fixed charge
    float t_bill; // Total bill
    float surcharge = 0; // Surcharge if applicable

    // Input customer details
    printf("Enter Customer Name: ");
    scanf("%s", Name);

    printf("Enter Customer ID: ");
    scanf("%d", &id);

    printf("Enter Total Units Consumed: ");
    scanf("%f", &unit);

    // Calculate the base bill based on units consumed
    if (unit <= 100) {
        t_bill = base_bill + unit * 5;
    } else if (unit <= 300) {
        t_bill = base_bill + 100 * 5 + (unit - 100) * 7;
    } else {
        t_bill = base_bill + 100 * 5 + 200 * 7 + (unit - 300) * 10;
    }

    // Check for surcharge
    if (t_bill > 1000) {
        surcharge = t_bill * 0.05; // 5% surcharge
        t_bill += surcharge; // Add surcharge to total bill
    }

    // Output the results
    printf("\nCustomer Name: %s\n", Name);
    printf("Customer ID: %d\n", id);
    printf("Units Consumed: %.2f\n", unit);
    printf("Base Bill: ₹%.2f\n", t_bill - surcharge); // Base bill without surcharge
    if (surcharge > 0) {
        printf("Surcharge: ₹%.2f\n", surcharge);
    }
    printf("Total Bill: ₹%.2f\n", t_bill);

    return 0;
}
