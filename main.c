#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
void print_list_recursively(struct Node* headNode){

    struct Node* current = headNode;
   if (current == NULL){return;}
     printf("value=%d\n", current->data);
    current= current->next;
    print_list_recursively(current);
   // printf("value=%d\n", current->data);
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

    // reverse_list(&nodeHead);

    print_list(nodeHead);
    printf("= = = = =\n");
     printf("= = = = =\n");
    print_list_recursively(nodeHead);

    return 0;
}
