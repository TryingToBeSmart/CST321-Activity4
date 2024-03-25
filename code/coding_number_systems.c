#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// Convert number to binary and return as int array
// Thanks: javapoint.com/return-an-array-in-c
int *toBinary(int input)
{
    // digits will be entered from right to left, but they might not always fill the array
    // lets enter then from left to right, then reverse, but leave out the null
    int binaryResult[50];
    int position = 0;

    // extract the digits by dividing by 2 and put the remainder into the array
    while (input != 0)
    {
        binaryResult[position] = input % 2; // should be 1 or 0
        input = input / 2;
        position++;
    }

    /* 
        position is +1 higher than the last element in the array
        because of the way the while loop is written above 
    */

    // now flip the array but leave out the NULLS
    // I can start at the end using position
    // from the last while loop
    int higherPointer = position - 1;            // points to the last digit of old array
    int insertPointer = 0;                       // points to the first digit of new returnArray
    int *returnArray = malloc(sizeof(int) * 50); // define size array in memory to return (size of return + finish signal 2)

    // Fill return array
    while (higherPointer >= 0)
    {
        returnArray[insertPointer] = binaryResult[higherPointer];
        insertPointer++;
        higherPointer--;
    }
    // Insert a '2' to indicate the end of the array
    returnArray[insertPointer] = 2;

    return returnArray;
}

int main()
{
    printf("Enter a number between 0-1000: \n");
    int input;
    scanf("%d", &input);

    int *binaryArray = toBinary(input);
    printf("Your number in binary:\n");
    int i = 0;
    while (binaryArray[i] != 2)
    {
        printf("%d", binaryArray[i]);
        i++;
    }
    printf("\n");
    free(binaryArray);

    printf("Your number in hexidecimal:\n0x%08X\n", input);

    printf("\nApplying shift 10 bits left, mask out lower 10 bits, and logically OR the number 0x3ff\n");

    int result = ((input << 10) & 0xFFFFFC00) | 0x03FF;

    printf("New result in decimal:\n%d\n", result);

    int *newBinaryArray = toBinary(result);
    printf("New result in binary:\n");
    i = 0;
    while (newBinaryArray[i] != 2)
    {
        printf("%d", newBinaryArray[i]);
        i++;
    }
    printf("\n");

    printf("New number in hexidecimal:\n0x%08X\n", result);
}