#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


// Convert number to binary and return as int array
// Thanks: javapoint.com/return-an-array-in-c
int *toBinary(int input)
{
    // digits will be entered from right to left, but they might not always fill the array
    // lets enter then from left to right, then reverse, but leave out the null
    int binaryResult [20];
    int position = 0; 

    // extract the digits by deviding by 2 and put the remainder into the array
    while(input != 0)
    {
        binaryResult[position] = input % 2; // should be 1 or 0
        printf("Putting %d into location %d\n", binaryResult[position], position);
        input = input / 2;
        printf("input is now: %d\n", input);
        position++;
    }

    // now flip the array but leave out the NULLS
    // I can start at the end using position 
    // from the last while loop
    int higherPointer = position-1; // points to the last digit of old array
    int insertPointer = 0; // points to the first digit of new returnArray
    // swap binaryResult array at higherPointer(end) with lowerPointer(beginning)
    // by putting the end into temp, beginning into end, then temp
    // into beginning. Then move the pointers closer together until they meet
    printf("now reversing...\n");
    int *returnArray = malloc(sizeof(position)); // define size array in memory
    
    while(higherPointer >= 0)
    {
        returnArray[insertPointer] = binaryResult[higherPointer];
        insertPointer++;
        higherPointer--;
    }

    // Print the binary number
    printf("Print array in toBinary:\n");
    for(int i = 0; i < position; i++)
    {
        printf("%d", returnArray[i]);
    }
    printf("\n");

    return returnArray;
}

// Convert number to hexadecimal


// Shift number 10 bits to the left


// mask out the lower 10 bits to 0


// logically OR the number of 0x3FF


int main ()
{
    printf("Enter a number between 0-1000: \n");
    int input;
    scanf("%d", &input);

    // I tried to get this to return an array, but I didn't
    // feel like spending more time figuring out how to 
    // print the array because the sizeof() doesn't work on pointer
    int *binaryArray = toBinary(input);
}