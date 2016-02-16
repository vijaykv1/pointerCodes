/******************************************************************************
* Author:       Varun Vijaykumar
* File :        pointerOperations.c
* Description : experimentations with pointers
* Dated :       01/02/2016
*******************************************************************************/

#include <stdio.h>

int main(void)
{
  // Pointer Assignments
  int a = 10, b = 20 ;
  int *Aptr = &a; // can be directly assigned.
  int *Bptr;
  Bptr = &b;

  // Does both the implementations work ?
  printf("A pointer value : %d \n",*Aptr); // we are still giving the * here
  printf("B pointer value : %d \n",*Bptr);

  //Addresses that are used here are
  printf("A pointer address value : %p \n",Aptr); // we are still giving the * here
  printf("B pointer address value : %p \n",Bptr);

  // pointer transfers
  int *b_bkup_ptr;
  b_bkup_ptr = Bptr;

  int *a_bkup_ptr = Aptr; // this works too !!

  // Does both the implementations work ?
  printf("A pointer backup value : %d \n",*a_bkup_ptr); // we are still giving the * here
  printf("B pointer backup value : %d \n",*b_bkup_ptr);

  // pointer type cast mechanisms
/*
  void *m; // void pointer

  double x = 100.001,y;
  m = &x;

  // void pointer test (generic pointer)
  printf("void pointer value : %f \n",(double)*m); // we are still giving the * here
  printf("void pointer address value : %p \n",m);

  int *p = &x;
  printf("X pointer value : %d \n",*p); // we are still giving the * here
  printf("X pointer address value : %p \n",p);

  // We might need to typecast this
  int *q = (int*) &x;
  printf("X pointer typecasted value : %f \n",*q); // we are still giving the * here
  printf("X pointer typecasted address value : %p \n",q);
*/

  int N;
  double D;
  char C;

  printf("The size of int in this machine is : %lu \n",sizeof(N));
  printf("The size of double in this machine is : %lu \n",sizeof(D));
  printf("The size of char in this machine is : %lu \n",sizeof(C));

  // lets try the case where we will access using the pointer type.
  int A[10] = {10,20,30};
  int *arrayPointer = &A[0]; // point to the first address in the code

  printf("Array value for 1 is %d \n",*arrayPointer );
  arrayPointer++; // Increment by 4 bytes for int here
  printf("Array value for 2 is %d \n",*arrayPointer );
  arrayPointer++;
  printf("Array value for 3 is %d \n",*arrayPointer );

  // alternative
  printf("Array Indexing based values for 1 : %d \n",*A );
  arrayPointer++; // Increment by 4 bytes for int here
  printf("Array Indexing based values for 2 : %d \n",*(A+1) );
  arrayPointer++;
  printf("Array Indexing based values for 3 : %d \n",*(A+2) );

  return 0;
}
