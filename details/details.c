#include "details.h"

int populateDetails(void)
{
  for (int i = 0 ; i < NOPS ; i++)
  {
    printf("\n Name please:" );
    // Allocate some memory for this
    personalDatabase[i].nameOfPerson = malloc(sizeof(char)*(100)); // Equivalent to nameOfPerson[100]
    scanf("%s",personalDatabase[i].nameOfPerson );

    printf("\n Roll Number Please : " );
    scanf("%d", &personalDatabase[i].roll );

    printf("\n Number of subjects please :");
    scanf("%d",&personalDatabase[i].NoSub);

    // lets malloc
    personalDatabase[i].subjects = malloc(sizeof(char)*10);

    for (int j = 0 ; j < personalDatabase[i].NoSub ; j++)
    {
      // Allocate and then transfer
      personalDatabase[i].subjects[j] = malloc(100); // hundred characters
      printf("Subject :");
      scanf("%s",personalDatabase[i].subjects[j]);
    }

  }
  return 0; // marked as success
}

void ShowDetails(char *Name)
{
  if ( (strcmp(Name,"All") == 0) ||
       (strcmp(Name,"ALL") == 0) ||
       (strcmp(Name,"all") == 0) )
  {
    char *agreementString;
    printf("Total Number of people present are : %d \n", NOPS);

    for (int i = 0 ; i < NOPS ; i++)
    {
      // print the details
      printf("\n ****************************************** \n");

      printf("Name : %s\n",personalDatabase[i].nameOfPerson );
      printf("Roll Number: %d\n",personalDatabase[i].roll);

      printf("Subjects taken : \n");
      for (int j = 0 ; j < personalDatabase[i].NoSub ; j++ )
      {
        printf ("%d -- %s \n ",j,personalDatabase[i].subjects[j]);
      }

      printf("****************************************** \n");

    }
  }
  else // other cases
  {
    for (int i = 0 ; i < NOPS ; i++)
    {
      char *currentName = personalDatabase[i].nameOfPerson;

      if (strcmp(currentName , Name ) == 0)
      {

        printf("\n ****************************************** \n");

        printf("Name : %s\n",personalDatabase[i].nameOfPerson );
        printf("Roll Number: %d\n",personalDatabase[i].roll);

        printf("Subjects taken : \n");
        for (int j = 0 ; j < personalDatabase[i].NoSub ; j++ )
        {
          printf ("%d -- %s \n ",j,personalDatabase[i].subjects[j]);
        }

        printf("****************************************** \n");
      }
    }
  }
}

int main(void)
{
  // get the details
  char *nameOfPerson;
  printf("Enter the number of persons: " );
  scanf("%d",&NOPS);
  int populateStatus = populateDetails();

  // Which user's details do you want ?
  printf("\n Please enter name of person for getting details:" );
  nameOfPerson = malloc(sizeof(char)*100);
  scanf("%s", nameOfPerson);

  // Extract the required details !
  ShowDetails(nameOfPerson);

  return 0; // always success
}
