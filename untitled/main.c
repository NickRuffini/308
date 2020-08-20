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

int reverseAsInt(int);

/**************************************************
 * Input:
 * Output:
 * Pre-Condition:
 * Post-Condition:
 * ***********************************************/
int main() {
    int n = 0;
    int i;

    while (n != -1) {
        printf("Enter number of integers to store [-1 to quit]: ");
        scanf("%d", &n);

        if (n != -1) {
            for (i = 0; i < n; i++) {
                int thisNum;
                printf("Enter number %d: ", i + 1);
                scanf("%d", &thisNum);
            }
        }
    }
    return 0;
}

/**************************************************
 * Input: Int value that will be reversed
 * Output: A 0 if the reverse failed, a 1 if the reverse succeeded
 * Pre-Condition: Parameter must have more than 0 digits (actually reversable)
 * Post-Condition:
 * ***********************************************/
int reverseAsInt(int num) {

}
