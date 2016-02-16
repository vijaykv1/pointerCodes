#ifndef __PERSONAL_DATABASE__
#define __PERSONAL_DATABASE__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///////////////////////////////////////////////
/// Structure to maintain the details required
///////////////////////////////////////////////
struct details {

  char *nameOfPerson; // name of person
  int roll; // roll number of person
  int NoSub;  // Number of subjects
  char **subjects; // list of subjects by person.

};

struct details personalDatabase[100]; // Creating a database
int NOPS; //to maintain the number of people in database

/////////////////////////////////////////////////
/// Get details from user
/////////////////////////////////////////////////
int populateDetails(void);

/////////////////////////////////////////////////
/// Show details that was required from the user
/////////////////////////////////////////////////
void ShowDetails(char *Name);

#endif /*__PERSONAL_DATABASE__*/
