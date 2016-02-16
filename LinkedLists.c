/******************************************************************************
* Author:         Varun Vijaykumar
* File :          LinkedLists.c
* Description :   Linked List based Operation(s)
* Dated :         08/02/2016
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Linked List structure
typedef struct node {
  char *name;
  int data;
  struct node *next;
}node_t;

int nodeCounter; // global LL count maintainer ... 

void printLinklst(node_t *head)
{
  node_t *currentNode = head;

  while (1)
  {
    printf("Node Name : %s \t",currentNode->name);
    printf("Node data : %d \n",currentNode->data);

    if (currentNode->next != NULL)
    {
      currentNode = currentNode->next;
    }
    else
    {
      break;
    }
  }
  printf("\n");
}

node_t* addNode(node_t *head,node_t *newNode)
{
  node_t *currentNode = head;

  while (currentNode->next != NULL){
    currentNode = currentNode->next;
  }

  currentNode->next = newNode;

  if (currentNode->next == NULL)
  {
    printf("Executing add failed ! ");
    return head;
  }

  nodeCounter++;
  return head;
}

node_t* deleteNode(node_t *head, int nodeNumber)
{
  node_t *currentNode = head;
  node_t *previousNode = NULL;

  int currentNodeNumber = 0;

  while (currentNode != NULL)
  {
    currentNodeNumber++;

    if (nodeNumber == currentNodeNumber)
    {
      if (strcmp(currentNode->name,"head") == 0)
      {
        printf("*****************************\n");
        printf("Reached the head deletion part !\n" );
        printf("Node Name : %s \n",currentNode->name );
        printf("Node data : %d \n",currentNode->data );
        printf("*****************************\n");

        currentNode->next->name = "head"; // renaming the next node as the
        printLinklst(currentNode);
        node_t *newHead = currentNode->next;
        currentNode->next = NULL ; // done with work ... lets disconnect
        free(currentNode); // free memory for the current Node.
        nodeCounter--; // updating the node metric
        return newHead; // SUCCESS
      }
      else
      {
        //re-router code
        printf("*****************************\n");
        printf("Deleting the node with: \n" );
        printf("Node Name : %s \n",currentNode->name );
        printf("Node data : %d \n",currentNode->data );
        printf("*****************************\n");

        previousNode->next = currentNode->next; // pushed the re-route to the node mentioned
        currentNode->next = NULL; // disconnect and then delete the node please
        free(currentNode); // free the current node...
        nodeCounter--; // updating the node metric
        return head; // SUCCESS
      }
    }

    if (strcmp(currentNode->name,"head") != 0 )
    {
      previousNode = currentNode;
    }
    currentNode = currentNode->next;
  }

  return head; // didn work out ... lets push the head back on the main call
}

node_t* insertNode(node_t *head, node_t *newNode,int position)
{
  node_t *currentNode = head; // parser pointer
  node_t *nextNode = NULL; // for pushing in a value !
  int currentNodeNumber = 0; // will increment in the first entry into the codeset

  // parser to the required position set via the function
  while(currentNode != NULL)
  {
    currentNodeNumber++;

    if (currentNodeNumber == position)
    {
      printf("Position of %d reached , adding !\n",currentNodeNumber);
      nextNode = currentNode->next; // old next value
      currentNode->next = newNode; // new node
      newNode->next = nextNode; // updating the map !
      nodeCounter++; // overall node metric
      return head;
    }
  }

  // if none of the Position was found , we will just send an error message and pass the head as necessary
  printf("ERROR !! Didnt find the position specified !! \n");

  return head;
}

node_t* linkedLstfuncrunner(node_t *head , int choice)
{
  printf("Calling %s\n",__func__);
  switch (choice) {
    case 1:
    {
      //Adding Node call
      int noNodes = 0 ;
      printf("Adding Node manager:\n" );
      printf("Please specify the number of nodes to add :\n" );
      scanf("%d",&noNodes);
      for (int i = 0 ; i < noNodes;i++)
      {
        int nodeLocation = 0;
        node_t *insertNodeValues = malloc(sizeof(node_t)); // assign some values
        insertNodeValues->name = malloc(sizeof(char)*30);
        insertNodeValues->next = NULL; // will be updated in the function ...

        printf("\n Enter the node name for Node %d : ",i+1);
        scanf("%s",insertNodeValues->name);
        printf("\n Enter the node value for Node %d : ",i+1);
        scanf("%d",&insertNodeValues->data);
        printf("\n Specify location for adding node (0 for adding next & other values till %d ) : ",nodeCounter);
        scanf("%d",&nodeLocation );

        if (nodeLocation == 0)
        {
          return(addNode(head,insertNodeValues));
        }
        else if (nodeLocation <= nodeCounter)
        {
          return(insertNode(head,insertNodeValues,nodeLocation));
        }
        else
        {
          printf("Illegal Access requested/ specified ... terminating this session ,,, \n" );
          return head;
        }
      }
    }

    case 2:
    {
      // for removing node
      int nodeLocation = 0;
      printf("\n Specify location for removing  node (1 to %d)  : ",nodeCounter);
      scanf("%d",&nodeLocation );

      if (nodeLocation <= nodeCounter)
      {
          return (deleteNode(head, nodeLocation));
      }
      else
      {
          printf("Illegal Access requested/ specified ... terminating this session ,,, \n" );
          return head;
      }
    }

    default:
    {
      printf("ERROR in selection provided ! \n");
      return head; // none of them !! return original head itself
    }

  }
}

int main(void)
{
  // creating the head for the linked list

  int choice;
  bool continuePrompt = true;

  node_t *head = malloc(sizeof(node_t));
  if (!head){
    printf("Error in creating head ! \n" );
    exit(-1);
  }

  head->name = malloc(sizeof(char)*40);
  if(head->name != NULL )
  {
    head->name = "head";
  }

  head->data = 1;
  head->next = NULL;
  nodeCounter++;

  printf("Welcome to the Link List management module ! \n" );
  printf("**************************\n" );
  printf("Current Link List Status : \n" );
  printLinklst(head);
  printf("**************************\n" );

  while (continuePrompt) {

    char *continueStr = malloc(sizeof(char));

    printf("Please enter a requirement as shown below \n (1) Add Node(s) \n (2) deleteNode(s) \n : " );
    scanf("%d",&choice);

    head = linkedLstfuncrunner(head, choice);

    printf("**************************\n" );
    printf("After operation  Link List Status : \n" );
    printLinklst(head);
    printf("**************************\n" );

    printf("Do u want to continue ? Y or N :");
    scanf("%c",continueStr);

    if ((strcmp(continueStr,"N") == 0) || (strcmp(continueStr,"n") == 0))
    {
      continuePrompt = false;
    }
  }

  printf("End of management prompt !! \n" );
  return 0;
}
