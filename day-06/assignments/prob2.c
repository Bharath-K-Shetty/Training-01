#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
 char name[50];
 int price;
} Product;
int compareProducts(const void *a, const void *b) {
 return ((Product *)a)->price - ((Product *)b)->price;
}
int binarySearch(Product arr[], int left, int right, const
char *name) {
 while (left <= right) {
 int mid = left + (right - left) / 2;
 int cmp = strcmp(arr[mid].name, name);
 if (cmp == 0) {
 return mid;
 }
 if (cmp < 0) {
 left = mid + 1;
 } else {
 right = mid - 1;
 }
 }
 return -1;
}
void displayProduct(Product product) {
 printf("(Price: %d)\n", product.price);
}
int main() {
 Product products[] = {
 {"Laptop", 50000},
 {"Mobile", 20000},
 {"Headphones", 5000},
 {"Tablet", 30000},
 {"Smartwatch", 10000}
 };
 int numProducts = sizeof(products) /
sizeof(products[0]);
 // Sort by price (ascending)
 qsort(products, numProducts, sizeof(Product),
compareProducts);
 printf("Sorted by Price: ");
 for (int i = 0; i < numProducts; i++) {
 printf("%s (%d)", products[i].name,
products[i].price);
 if(i < numProducts -1) printf(", ");
 }
 printf("\n");
 // Display cheapest and most expensive
 printf("Cheapest Product: %s (Price: %d)\n",
products[0].name, products[0].price);
 printf("Most Expensive Product: %s (Price: %d)\n",
products[numProducts - 1].name,
products[numProducts - 1].price);
 // Binary search by product name
 int searchResult = binarySearch(products, 0,
numProducts - 1, "Mobile");
 if (searchResult != -1) {
 printf("Search 'Mobile': Found ");
 displayProduct(products[searchResult]);
 } else {
 printf("Search 'Mobile': Not Found\n");
 }
 searchResult = binarySearch(products, 0, numProducts
- 1, "Keyboard");
 if (searchResult != -1) {
 printf("Search 'Keyboard': Found ");
 displayProduct(products[searchResult]);
 } else {
 printf("Search 'Keyboard': Not Found\n");
 }
 return 0;
}
