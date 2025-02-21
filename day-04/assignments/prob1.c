#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LEN 50


typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    char expiry_date[11]; // YYYY-MM-DD
    float price;
} Medicine;


int compare_by_expiry(const void *a, const void *b) {
    return strcmp(((Medicine *)a)->expiry_date, ((Medicine *)b)->expiry_date);
}

int main() {
    int num_medicines;
    Medicine medicines[MAX_MEDICINES];

    printf("Enter number of medicines: ");
    scanf("%d", &num_medicines);

    if (num_medicines > MAX_MEDICINES) {
        printf("Too many medicines. Maximum is %d.\n", MAX_MEDICINES);
        return 1;
    }


    for (int i = 0; i < num_medicines; i++) {
        printf("Medicine %d: ", i + 1);
        scanf("%d, %[^,], %[^,], ₹%f", &medicines[i].id, medicines[i].name, medicines[i].expiry_date, &medicines[i].price);
    }

    qsort(medicines, num_medicines, sizeof(Medicine), compare_by_expiry);

    
    printf("\nSorted Medicines (by Expiry Date):\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("%d. %s - %s\n", i + 1, medicines[i].name, medicines[i].expiry_date);
    }

    // Save data to file
    FILE *fp = fopen("medicine_inventory.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    for (int i = 0; i < num_medicines; i++) {
        fprintf(fp, "%d,%s,%s,%.2f\n", medicines[i].id, medicines[i].name, medicines[i].expiry_date, medicines[i].price);
    }
    fclose(fp);

    printf("\nRecords saved in \"medicine_inventory.txt\"\n");

    return 0;
}
