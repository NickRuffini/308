/**************************************************
 * Name: Nick Ruffini
 * Date: 8/25/2020
 * Assignment: Project 1: Integer Operations
 * ************************************************
 * This program takes input from a user, storing the integer values entered into an array. There is then
 * the option to "flip" an integer value, or reverse it, and return the sum of the individual numbers in the
 * larger number.
 * ***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reverseAsInt(int);
int reverseAsStr(char[], int, int);
int sumAllDigits(int);

int sum;
int numToAdd;

int main() {
    int n = 0;
    int i;
    int chosenIndex;
    char numAsString[12];

    while (n != -1) {
        sum = 0;
        printf("Enter number of integers to store [-1 to quit]: ");
        scanf("%d", &n);

        if (n > -2) {
            int array[n];
            if (n != -1) {
                for (i = 0; i < n; i++) {
                    int thisNum;
                    printf("Enter number %d: ", i + 1);
                    scanf("%d", &thisNum);

                    array[i] = thisNum;
                }
                printf("Enter index of array to process: ");
                scanf("%d", &chosenIndex);

                reverseAsInt(array[chosenIndex - 1]);

                sprintf(numAsString, "%d", array[chosenIndex - 1]);

                reverseAsStr(numAsString, 0, strlen(numAsString) - 1);

                printf("Sum of all digits in num: %d\n\n", sumAllDigits(array[chosenIndex - 1]));
            }
        }
        else {
            printf("Error; number entered was out of bounds");
            break;
        }
    }
    return 0;
}

/**************************************************
 * Input: Int value that will be reversed
 * Output: A 0 if the reverse failed, a 1 if the reverse succeeded
 * Pre-Condition: Parameter must have more than 0 digits (actually reversable)
 * Post-Condition: Will return the reversed value of num as an integer
 * ***********************************************/
int reverseAsInt(int num) {
    int reverse = 0;

    while (num != 0)
    {
        reverse = reverse * 10;
        reverse = reverse + num%10;
        num = num/10;
    }
    printf("Reverse number (as Int): %d\n", reverse);
    return 1;
}

/**************************************************
 * Input: String value that will be reversed
 * Output: A 0 if the reverse failed, a 1 if the reverse succeeded
 * Pre-Condition: Valid parameters are passed in (String in char[] form, index and size are valid entries for the string)
 * Post-Condition: Will print out the reversed number in string form
 * ***********************************************/
int reverseAsStr(char num[], int index, int size) {
    if (index >= size) {
        printf("Reverse number (as Str): %s\n\n", num);
        return 1;
    }
    else if (num[index] == '-'){
        reverseAsStr(num, index + 1, size);
    }
    else {
        char temp = num[index];
        num[index] = num[size];
        num[size] = temp;

        reverseAsStr(num, index + 1, size - 1);
    }
}

/**************************************************
 * Input: Number that we are summing the digits of
 * Output: The sum of all the digits
 * Pre-Condition:
 * Post-Condition:
 * ***********************************************/
int sumAllDigits(int num) {
    if (num < 0) {
        sumAllDigits(abs(num));
    }
    if (num == 0) {
        return sum;
    }
    else {
        numToAdd = num % 10;
        sum += numToAdd;
        sumAllDigits(num / 10);
    }
}