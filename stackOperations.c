/******************************************************************************
* Author:         Varun Vijaykumar
* File :          stackOperations.c
* Description :   Pointer for stack access and failures.
* Dated :         01/02/2016
*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define Stack_size 50
#define SUCCESS 0
#define FAILURE -1

int *currentPointer; // to push and pull the values
int *TopOfStack; // to point to top of the stack (administration)
int dataStack[Stack_size]; // overall stack

int push(int dataToPush)
{
  if (currentPointer > (TopOfStack+Stack_size))
  {
    printf("Out of bounds access!! \n" );
    return FAILURE;
  }

  *currentPointer = dataToPush;
  currentPointer++; // increment and be ready
  return SUCCESS;
}

int pop(int positionToPop)
{
  int valueToReturn = FAILURE;

  if (((TopOfStack+positionToPop) > (TopOfStack+Stack_size)) ||
      (currentPointer < TopOfStack))
  {
    printf("Out of bounds access!! \n" );
    return valueToReturn; // out of bounds
  }

  valueToReturn = *(TopOfStack+positionToPop);
  currentPointer--;
  return valueToReturn;
}

int main(void)
{
  int Input_counter = 0 ;

  // Mark the start of the stack
  currentPointer = &dataStack[0];
  TopOfStack = &dataStack[0];

  while( Input_counter < 10) {
    //Push all the values from got from the user
    int valueToPush;
    printf("\n Enter the values : ");
    scanf("%d",&valueToPush );

    if (valueToPush != 0)
    {
      push(valueToPush);
      Input_counter++;
    }
  }

  // lets print all the values that we have inputted in the stack till now
  printf("Values on the stack are : \n" );

  for (int i = 0 ; i < 10 ; i++)
  {
    printf("%d \n",*(dataStack+i));
  }

  // lets selectively push out the values based on the index
  while(1) {

    char *popStat;
    int popValue,popedValue;

    printf("Enter the value to be pop :");
    scanf("%d",&popValue);

    popedValue = pop(popValue);

    if (popedValue != -1 )
    {
      printf("Poped Value = %d \n",popedValue);
    }
    else
    {
      return FAILURE;
    }

    char *ContinueStat;
    // Allocate some value for ContinueStat on heap
    ContinueStat = malloc (sizeof(char) * 10);
    printf("Continue ? Y or N : " );
    scanf ("%s",ContinueStat);

    if ((strcmp(ContinueStat,"n") == 0 ) || (strcmp(ContinueStat,"N") == 0))
    {
      printf(" OKI !! BYE !! \n ");
      exit(1); // exit program
    }
  }

  return SUCCESS;
}
