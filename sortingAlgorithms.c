/******************************************************************************
* Author:         Varun Vijaykumar
* File :          sortingAgorithms.c
* Description :   Implementations for Sorting Algorithms of all types.
* Dated :         07/02/2016
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FAILURE -1
#define SUCCESS 0

int unsortedArray[10] = {10,8,3,7,4,12,2,1,6,8}; // temporary

// default print function
void ArrayPrinter(int arr[10])
{
  printf(" \n ");
  for(int i = 0 ; i < 10 ; i++ )
  {
    printf("%d \t",arr[i]);
  }
  printf(" \n ");
}

// Bubble Sort Algorithm
void bubbleSortFcn(void)
{
  int temporary,duplicate[10];

  //Copy the data
  memcpy(duplicate,unsortedArray,sizeof(unsortedArray));

  printf("The Original Array : \n" );
  ArrayPrinter(duplicate);

  printf("********************************* \n");
  printf("Starting Bubble Sort Algorithm  \n ");
  printf("********************************* \n");

  int delimiter = 10;
  for (int j = 0 ; j < 10 ; j++)
  {
    for (int i = 0 ; i < (10-j) ; i++ )
    {
      if (i != (i-j)) // Except for the final part on the array.
      {
        //swapping
        if (duplicate[i] > duplicate[i+1])
        {
          temporary = duplicate[i];
          duplicate[i] = duplicate[i+1];
          duplicate[i+1] = temporary;
        }
      }
    }
    ArrayPrinter(duplicate); // print each step
  }
}

// selection Sort Algorithm
void selectionSortFcn(void)
{
  int temporary = 0,duplicate[10];

  //Copy the data
  memcpy(duplicate,unsortedArray,sizeof(unsortedArray));

  printf("The Original Array : \n" );
  ArrayPrinter(duplicate);

  printf("********************************* \n");
  printf("Starting Selection Sort Algorithm  \n ");
  printf("********************************* \n");
  for (int sortedPortion = 0 ; sortedPortion < 10 ; sortedPortion++)
  {
    int minimumNow = 0 ;
    int minimumNowPosition = 0 ;

    for(int unsortedPortion = sortedPortion ; unsortedPortion < 10 ; unsortedPortion++)
    {
      if (unsortedPortion == sortedPortion)
      {
        minimumNow = duplicate[unsortedPortion]; // marking the first one in the array as the minimum
      }

      if (duplicate[unsortedPortion] < minimumNow)
      {
        // mark new minimumNow and the its position
        minimumNow = duplicate[unsortedPortion];
        minimumNowPosition = unsortedPortion;
      }
    }

    // only change if the sortedPortion value is different from the currentPointer
    if (duplicate[sortedPortion] != minimumNow)
    {
        temporary = duplicate[sortedPortion];
        duplicate[sortedPortion] = minimumNow;
        duplicate[minimumNowPosition] = temporary;
    }
    ArrayPrinter(duplicate);
  }
}

//insertion Sort Algorithm
void insertionSortFcn(void)
{
  int temporary = 0,sortedArr[10],unsortedArr[10];

  //Copy the data
  memcpy(unsortedArr,unsortedArray,sizeof(unsortedArray));

  printf("The Original Array : \n" );
  ArrayPrinter(unsortedArr);

  printf("********************************* \n");
  printf("Starting Insertion Sort Algorithm  \n ");
  printf("********************************* \n");

  sortedArr[0] = unsortedArr[0];


  for (int unsorted = 1 ; unsorted < 10 ; unsorted++ )
  {
    for (int sorted = 0 ; sorted < 10 ; sorted++)
    {
        if (sorted != 9)
        {
            if (sortedArr[sorted] <= unsortedArr[unsorted]) && (sortedArr[sorted+1] > unsorted)
            {

            }

        }

    }

  }


}

// merge Sort Algorithm
void mergeSortFcn(void)
{
  int temporary,duplicate[10];

  //Copy the data
  memcpy(duplicate,unsortedArray,sizeof(unsortedArray));

  printf("The Original Array : \n" );
  ArrayPrinter(duplicate);

  printf("********************************* \n");
  printf("Starting Bubble Sort Algorithm  \n ");
  printf("********************************* \n");

  // Creating a splitter alogorithm first

  // divide by two and then create a set of arrays

  for (int i = 0 ; i < 10 ; )
  {


    i = i/2;
  }


}

//run Algorithms selector function
int runAlgo(char *Algo)
{
  if ((strcmp(Algo,"bubble") == 0) ||
      (strcmp(Algo,"BUBBLE") == 0) ||
      (strcmp(Algo,"Bubble") == 0))
  {
    bubbleSortFcn();
    return SUCCESS;
  }
  else if ((strcmp(Algo,"selection") == 0) ||
           (strcmp(Algo,"SELECTION") == 0) ||
           (strcmp(Algo,"Selection") == 0))
  {
    selectionSortFcn();
    return SUCCESS;
  }
  else if ((strcmp(Algo,"insertion") == 0) ||
           (strcmp(Algo,"INSERTION") == 0) ||
           (strcmp(Algo,"Insertion") == 0))
  {
    insertionSortFcn();
    return SUCCESS;
  }
  else
  {
    printf("Unknown Algo! \n");
    return FAILURE;
  }
}

int main(int argc,char *argv[])
{
  if ( argc != 2 )
  {
    printf("Please enter the required Algorithm for sorting!! \n");
    return FAILURE;
  }

  // Malloc
  char *Algo = malloc( sizeof(char) * 30);

  if (!Algo) return FAILURE;

  Algo = *(argv+1);

  printf("%s \n",Algo);

  // Select the required
  int AlgoStatus = runAlgo(Algo);
  if (AlgoStatus == FAILURE )
  {
    return FAILURE;
  }
  else
  {
    return SUCCESS;
  }
}
