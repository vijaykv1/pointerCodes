/******************************************************************************
* Author:         Varun Vijaykumar
* File :          functionpointer.c
* Description :   Function pointer and their related operations.
* Dated :         02/02/2016
*******************************************************************************/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int adder(const int a ,const int b )
{
  printf("%s ",__func__);
  return (a+b);
}

int subtractor(const int a ,const int b )
{
  printf("%s ",__func__);
  int diff = 0;
  if (a>b)
  {
    diff = a-b;
  }
  else
  {
    diff = b-a;
  }
  return diff;
}

int multiply (const int a ,const int b )
{
  printf("%s ",__func__);
  return (a*b);
}

int divide(const int a ,const int b )
{
  printf("%s ",__func__);

  if (b != 0 )
  {
    return (a/b);
  }

  return -1;
}

int operationRunner(const int a ,const int b ,int (*func) (const int ,const int ))
{
  return ((*func)(a,b));
}

void selectionMetric(const int a ,const int b ,char *operChoice )
{
  int (*p) (const int ,const int); // Function pointer

  printf("function received : %s",operChoice);

  if (strcmp(operChoice,"add") == 0)
  {
    printf("Adding \n" );
    p = adder;
  }
  else if (strcmp(operChoice,"sub")== 0)
  {
    printf("subtractor \n" );
    p = subtractor;
  }
  else if (strcmp(operChoice,"mult")== 0)
  {
    printf("multiply \n" );
    p = multiply;
  }
  else if (strcmp(operChoice,"div")== 0)
  {
    printf("Division \n" );
    p = divide;
  }
  else
  {
    printf("Wrong choice !! \n");
  }

  int res = operationRunner(a,b,p);

  if (res != -1)
  {
    printf("Result : %d \n",res);
  }
  else
  {
    printf("Wrong result !! \n");
  }

}

int main(void)
{
  int Arg1,Arg2;
  char *operChoice;
  // Malloc some value (say 20) for string value on heap.
  operChoice = malloc(sizeof(char)*20);
  if (!operChoice)
  {
    exit(1); // returned NULL from malloc !! means that the heap is filled up.
  }

  printf("Enter the numbers please : ");
  scanf("%d %d",&Arg1,&Arg2);

  printf("Enter the choice for operation -- (add/sub/div/mult) : ");
  scanf("%s",operChoice); // we can use gets(operChoice)

  printf("operation selected : %s ",operChoice);

  selectionMetric(Arg1, Arg2, operChoice);

  // everything is done... lets free memory please !
  free(operChoice);

  return 0;
}
