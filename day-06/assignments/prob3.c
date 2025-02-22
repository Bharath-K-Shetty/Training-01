#include <stdio.h>
void selectionSort(int arr[], int n) {
 int i, j, min_idx, temp;
 for (i = 0; i < n - 1; i++) {
 min_idx = i;
 for (j = i + 1; j < n; j++) {
 if (arr[j] < arr[min_idx]) {
 min_idx = j;
 }
 }
 temp = arr[min_idx];
 arr[min_idx] = arr[i];
 arr[i] = temp;
 }
}
int main() {
 int distances[] = {10, 3, 7, 1, 5};
 int numAmbulances = sizeof(distances) /
sizeof(distances[0]);
 printf("Ambulances (Distance in km): ");
 for (int i = 0; i < numAmbulances; i++) {
 printf("%d ", distances[i]);
 }
 printf("\n");
 selectionSort(distances, numAmbulances);
 printf("Sorted: ");
 for (int i = 0; i < numAmbulances; i++) {
 printf("%d ", distances[i]);
 }
 printf("\n");
 printf("Nearest Ambulance Assigned: Distance %d
km\n", distances[0]);
 return 0;
}
