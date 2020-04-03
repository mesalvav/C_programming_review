#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"


struct Node* recursively_reverse_list(struct Node** head){

   struct Node* currentNode = (*head);
   printf("value before = %d\n", currentNode->data);
    if ((*head)->next->next == NULL){
        (*head)->next->next = (*head);
        (*head) = (*head)->next;
        (*head)->next->next = NULL;
        printf("value head = %d\n", (*head)->data);
        return (*head)->next;
    }

    (*head) = (*head)->next;

    struct Node* returnedNode = recursively_reverse_list(head);
// why ? switching this 2 lines change the result
    returnedNode->next = currentNode;
    currentNode->next = NULL;

}

int main()
{
    struct Node* nodeHead = NULL;

    nodeHead = createNode(11);
    nodeHead->next = NULL;

    struct Node* nodeTwo = createNode(22);
    nodeTwo->next = NULL;
    nodeHead->next = nodeTwo;

    struct Node* nodeThree = createNode(33);
    nodeThree->next = NULL;
    nodeTwo->next = nodeThree;

    addNodeToBegginingOfList(&nodeHead, createNode(4));
    addNodeToBegginingOfList(&nodeHead, createNode(5));

    insertDataToNthPosition(&nodeHead, 888, 1);
    printf("original list = = = = =\n");
    print_list(nodeHead);

     printf("= = = = =\n");
    printf("\n");
printf("list step by step = = = = =\n");
    recursively_reverse_list(&nodeHead);
    printf("= = = = =\n");
    printf("\n");
    printf("reversed result= = = = =\n");
    print_list(nodeHead);
   printf("= = = = =\n");
    return 0;
}
