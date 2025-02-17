#include<stdio.h>
int main(){
    int choice;
    int distance;
    int base_charge;

    printf("Enter the choice \n1.Car\n2.Truck\n3.Bus\n");
    scanf("%d",&choice);
    
    printf("Enter the distance\n");
    scanf("%d",&distance);


    if(choice==1){
       base_charge=distance*5;
    }
    
    else if(choice==2){
        base_charge=distance*10;
    }
    else if(choice==3){
        base_charge=distance*8;
    }else{
        printf("Invalid Choice");
    }
    
    if(choice==2&&distance>500){
        base_charge=base_charge-base_charge*0.1;
    }
    if(choice==3&&distance>300){
        base_charge=base_charge-base_charge*0.05;
    }


printf("Total toll_tax:%d",base_charge);


    return 1;
}
