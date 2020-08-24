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

// Sum of all the digits in the number
int sum;
// Tracks the number we need to add to the sum of digits
int numToAdd;

int main() {
    // Used to store how many integers the user wants to store
    int n = 0;
    // Used to increment through a for loop
    int i;
    // Index of the integer the user wants to reverse
    int chosenIndex;
    // string version of the number we are reversing
    char numAsString[12];

    // while the user hasn't quit
    while (n != -1) {
        // used to reset the sum of the digits to 0 for every loop
        sum = 0;
        printf("Enter number of integers to store [-1 to quit]: ");
        scanf("%d", &n);

        // if the user hasn't entered a invalid number
        if (n > -2) {
            // array the size of however many entries the user wants to enter
            int array[n];
            // if the user didn't wan't to quit,
            if (n != -1) {
                // Prompt the user for however many integers they indicated before, and store them in an array
                for (i = 0; i < n; i++) {
                    int thisNum;
                    printf("Enter number %d: ", i + 1);
                    scanf("%d", &thisNum);

                    array[i] = thisNum;
                }
                printf("Enter index of array to process: ");
                scanf("%d", &chosenIndex);

                // Check if the index array they entered is valid
                if (chosenIndex > 0 && chosenIndex <= n) {
                    // Call the reverseAsInt method, which prints inside the method
                    reverseAsInt(array[chosenIndex - 1]);

                    // Converts the integer we are reversing into string form, storing it into numAsString
                    sprintf(numAsString, "%d", array[chosenIndex - 1]);

                    // Call the reverseAsStr method on the new string we created, printing inside the method
                    reverseAsStr(numAsString, 0, strlen(numAsString) - 1);

                    // Calls the sumAllDigits method, and prints out the result
                    printf("Sum of all digits in num: %d\n\n", sumAllDigits(array[chosenIndex - 1]));
                }
                // Throws error if the index array isn't valid
                else {
                    printf("Error; number entered was out of bounds");
                    break;
                }
            }
        }
        // If an invalid number was entered, throw an error
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
 * Pre-Condition: The parameter num is a valid integer
 * Post-Condition: Will return the int value of the sum of all the digits!
 * ***********************************************/
int sumAllDigits(int num) {
    if (num < 0) {
        sumAllDigits(abs(num));
    }
    else if (num == 0) {
        return sum;
    }
    else {
        numToAdd = num % 10;
        sum += numToAdd;
        sumAllDigits(num / 10);
    }
}