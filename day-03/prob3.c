#include<stdio.h>
#include<stdlib.h>
struct Student{
    char name[255];
    int marks;
};
typedef struct Student Student_t;
void readStudents(Student_t* students, int length){
    for(int i=0;i<length;i++){
        printf("student %d name:",i+1);
        scanf("%s",students[i].name);
        printf("student marks:");
        scanf("%d",&students[i].marks);
    }
}
void printStudents(Student_t* students, int length){
    printf("Studnet Records:\n");
    for(int i=0;i<length;i++){
        printf("%s - %d\n",students[i].name,students[i].marks);
    }
}
int main(){
    
    int studentsCount;
    printf("enter number of students:");
    scanf("%d",&studentsCount);
    Student_t* students = (Student_t*)malloc(sizeof(Student_t)*studentsCount);
    readStudents(students,studentsCount);
    printStudents(students, studentsCount);
    free(students);
    students=NULL;
    return 0;
}
