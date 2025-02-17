#include <stdio.h>
#include<string.h>
void reademployee(int *p_id, char* name, float* p_salary,int* p_attendance){
//read employee
   printf("Enter Id:");
   scanf("%d",p_id);
   
   printf("Enter your name:");
   scanf("%s",name);
   
   printf("Enter the salary:");
   scanf("%f",p_salary);
   
   printf("Enter number  of days worked:");
   scanf("%d",p_attendance);
}
float calculateBonous(float salary, int attendance)
{
    float bonus = 0.0f;
     if(attendence>25){
       bonus=(salary/100.0f)*5.0f;
   }else if (attendence<10){
    //   bonus=(-1.0f*((bonus/100.0f)*50.0f));
        bonus=-(salary/2);
   }
   return bonus;
}
void categorizeemployee(char* category, int attendance){
      if(attendence >25){
       strcpy(category,"excellent");
   }else if(attendence<15){
       strcpy(category,"Need improvement");
   }
}
int main() {
    // Write C code here
   int id;
   char name[255];
   float salary;
   int attendence;
   
   //read employee
   reademployee(&id,name,&salary,&attendence);
   
   //process payroll]
   
   float gross_salary = 0.0f;
   char category[50]="Good";
   
   //calculation bonus
   
  
   //final salary
   gross_salary=(salary+bonus);
   //categorize employee
 
   //display payroll details
   printf("Id: %d\n",id);
   printf("Name: %s\n",name);
   printf("Basic salary: %.2f\n",salary);
   if(bonus>0){
       printf("Bonus:%.2f\n",bonus);
   }
   printf("FInal salary:%.2f\n",gross_salary);
   printf("Employee performace category:%s\n",category);
    return 0;
}
