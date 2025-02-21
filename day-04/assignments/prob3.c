#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_NAME_LEN 50


typedef struct {
    int emp_id;
    char name[MAX_NAME_LEN];
    float basic_salary;
    float allowances;
    float gross_salary;
} Employee;

int main() {
    int num_employees;
    Employee employees[MAX_EMPLOYEES];

    printf("Enter number of employees: ");
    scanf("%d", &num_employees);

    if (num_employees > MAX_EMPLOYEES) {
        printf("Too many employees. Maximum is %d.\n", MAX_EMPLOYEES);
        return 1;
    }

    
    for (int i = 0; i < num_employees; i++) {
        printf("Employee %d: ", i + 1);
        scanf("%d, %[^,], ₹%f, ₹%f", &employees[i].emp_id, employees[i].name, &employees[i].basic_salary, &employees[i].allowances);
        employees[i].gross_salary = employees[i].basic_salary + employees[i].allowances;
    }


    FILE *fp = fopen("payroll.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    for (int i = 0; i < num_employees; i++) {
        fprintf(fp, "%d,%s,%.2f,%.2f,%.2f\n", employees[i].emp_id, employees[i].name, employees[i].basic_salary, employees[i].allowances, employees[i].gross_salary);
    }
    fclose(fp);

    printf("\nRecord saved in \"payroll.txt\"\n");


    int search_id;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &search_id);

    for (int i = 0; i < num_employees; i++) {
        if (employees[i].emp_id == search_id) {
            printf("\nEmployee: %s\n", employees[i].name);
            printf("Gross Salary: ₹%.2f\n", employees[i].gross_salary);
            return 0; // Employee found, exit the loop
        }
    }

    printf("\nEmployee with ID %d not found.\n", search_id);

    return 0;
}
