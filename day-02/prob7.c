#include<stdio.h>
#include<string.h>

void reverseString(char *str);

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf(" %s", str);

    reverseString(str);

    printf("Reversed String: %s\n", str);

    return 0;
}

void reverseString(char *str)
 {
    int len = 0;
    char *start = str;  
    char *end = str;  
   
    while (*end != '\0')
    {
        len++;
        end++;
    }
    end--;


   
    while (start < end)
    {
       
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}
