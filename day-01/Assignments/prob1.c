#include <stdio.h>

int main() {
    int status;

    printf("Enter order choice (1-4): ");
    scanf("%d", &status);

    switch (status) {
        case 1:
            printf("Order Placed\n");
            break;
        case 2:
            printf("Your food is being prepared.\n");
            break;
        case 3:
            printf("Out for Delivery\n");
            break;
        case 4:
            printf("Your order has been delivered. Enjoy your meal!\n");
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
            break;
    }

    return 0;
}
