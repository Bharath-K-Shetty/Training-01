#include <stdio.h>

struct Employee_t{
    int id;
    char name[255];
    float salary;
    char department[50];
};

typedef struct Employee_t Employee;
void readEmployee(Employee emp[],int n){
    printf("Enter the employee details \n");
    for(int i=1;i<=n;i++){
        printf("Enter the employee %d details:\n",i);
       scanf("%d%s%f%s", &emp[i].id, emp[i].name, &emp[i].salary, emp[i].department);
    }
    
}
void displayEmployee(Employee emp[],int n){
      for(int i=1;i<=n;i++){
        printf("Employee %d data:\n %d\n %s \n %f \n %s\n",i,
        emp[i].id,
        emp[i].name,
    emp[i].salary,
    emp[i].department);
    }
    
}
Employee findHighestSalary(Employee emp[],int n){
    Employee higehstSalriedPerson;
    for(int i=1;i<=n;i++){
        if(emp[i].salary<emp[i+1].salary){
            higehstSalriedPerson=emp[i+1];
        }
    }
    return higehstSalriedPerson;
}
int main() {
    int employeeCount;
    printf("Enter the employeeCount \n");
    scanf("%d",&employeeCount);
    Employee employees[1000];
    readEmployee(employees,employeeCount);
    displayEmployee(employees,employeeCount);
    Employee highestSalariedEmployee=findHighestSalary(employees,employeeCount);
    printf("Employee with Highest salary:\n %d \n %s \n %f \n %s\n",highestSalariedEmployee.id,highestSalariedEmployee.name,
    highestSalariedEmployee.salary,
    highestSalariedEmployee.department);
    return 0;
}
