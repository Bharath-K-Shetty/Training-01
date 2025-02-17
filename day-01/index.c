#include<stdio.h>
#include<string.h>
int main(){
    int id;
    char name[255];
    float salary;
    int attendence;
    
    printf("Enter the id");
    scanf("%d",&id);
    
    printf("Enter the name");
    scanf("%s",name);

    printf("Enter the salary");
    scanf("%f",&salary);

    printf("Enter the attendence");
    scanf("%d",&attendence);

    float bonus=0.0f;
    float gross_salary=0.0f;
    char category[50]="Good"; 
//calculate bonus 
 if(attendence>25) { 
  bonus=(bonus / 100.0f) * 5.0f; 
}
else if(attendence < 10){ 
bonus =(-1.0f*((bonus/100.0f)*50.0f));
} 
 
//final salary
gross_salary=(salary+bonus);

//categorie employee

if(attendence>25){
    strcpy(category,"Excellent");
}else if(attendence<15){
    strcpy(category,"Need Improvement");
}

//display payload details
printf("id:%d",&id);
printf("id:%s",name);

if(bonus>0){
    printf("Bonus :%.2f\n",bonus);
}

printf("Final Salary: %.2f\n",gross_salary);

printf("Employee Performance Category:%s",category);

return 0;
}