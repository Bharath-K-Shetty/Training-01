#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
 int rollNo;
 char name[50];
 int marks;
} Student;
int compareStudents(const void *a, const void *b) {
 return ((Student *)b)->marks - ((Student *)a)->marks;
}
int binarySearch(Student arr[], int left, int right, int
rollNo) {
 while (left <= right) {
 int mid = left + (right - left) / 2;
 if (arr[mid].rollNo == rollNo) {
 return mid;
 }
 if (arr[mid].rollNo < rollNo) {
 left = mid + 1;
 } else {
 right = mid - 1;
 }
 }
 return -1;
}
void displayStudent(Student student) {
 printf("(%s, Marks: %d)\n", student.name,
student.marks);
}
int main() {
 Student students[] = {
 {101, "Alice", 85},
 {102, "Bob", 90},
 {103, "Charlie", 75},
 {104, "David", 95},
 {105, "Eve", 80}
 };
 int numStudents = sizeof(students) /
sizeof(students[0]);
 // Sort by marks (descending)
 qsort(students, numStudents, sizeof(Student),
compareStudents);
 printf("Sorted by Marks: ");
 for (int i = 0; i < numStudents; i++) {
 printf("%s (%d)", students[i].name,
students[i].marks);
 if(i < numStudents -1) printf(", ");
 }
 printf("\n");
 // Display top 3 students
 printf("Top 3 Students:\n");
 for (int i = 0; i < 3 && i < numStudents; i++) {
 displayStudent(students[i]);
 }
 // Binary search by roll number
 int searchRollNo = 102;
 int searchResult = binarySearch(students, 0,
numStudents - 1, searchRollNo);
 if (searchResult != -1) {
 printf("Search Roll No %d: Found ", searchRollNo);
 displayStudent(students[searchResult]);
 } else {
 printf("Search Roll No %d: Not Found\n",
searchRollNo);
 }
 searchRollNo = 106;
 searchResult = binarySearch(students, 0, numStudents
- 1, searchRollNo);
 if (searchResult != -1) {
 printf("Search Roll No %d: Found ", searchRollNo);
 displayStudent(students[searchResult]);
 } else {
 printf("Search Roll No %d: Not Found\n",
searchRollNo);
 }
 return 0;
}
