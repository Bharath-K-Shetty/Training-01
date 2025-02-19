#include<stdio.h>
float calculateFinalAmount(float bill)
 {
    float discount = 0;
    if (bill >= 500 && bill <= 1000)
 {
        discount = 0.10;  
    } 
else if (bill > 1000)
 {
        discount = 0.20;  
    }
    return bill - (bill * discount);
}

int main() 
{
    float bill;
    printf("Enter total bill amount: ");
    scanf("%f", &bill);
    float finalAmount = calculateFinalAmount(bill);
    printf("Final Payable Amount: %.2f\n", finalAmount);
   
    return 0;
}
