#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "LinkList.h"
#include "BStree.h"
#include "QueueInt.h"

typedef struct QueueNodeBStree {
        BStree* treedata;
        struct QueueNodeBStree* next;
    } TQnode;

TQnode* frontTQ = NULL;
TQnode* rearTQ = NULL;

void Enqueue_TQnode(BStree* nodex){
    TQnode* tempTQ = (TQnode*)malloc(sizeof(TQnode));
    tempTQ->treedata = nodex;
    tempTQ->next = NULL;

    if(frontTQ == NULL && rearTQ == NULL){
        frontTQ = rearTQ = tempTQ;
        return ;
    }
    rearTQ->next = tempTQ;
    rearTQ = rearTQ->next;
}

void Dequeue_TQnode(){
    TQnode* tempy = frontTQ;
    if (tempy == NULL){
        printf("Empty Queue!\n");
        return;
    } else {
        frontTQ = frontTQ->next;
    }

    free(tempy);
}
void print_TQ(){
    if(frontTQ == NULL){
        printf("Noting Empty TQ queue..!\n");
        return;
    }

    TQnode* tempi = frontTQ;
    while(tempi != NULL){
        printf("TQ value= %d\n", tempi->treedata->data);
        tempi = tempi->next;
    }
}

void LevelOrder(BStree * root){
        if (root == NULL)return;

        Enqueue_TQnode(root);
printf("root: %d\n", root->data);
        while( frontTQ != NULL){

          if(root->leftNode != NULL){
            LevelOrder(root->leftNode);
          }
          if(root->rightNode != NULL){
            LevelOrder(root->rightNode);
          }
          Dequeue_TQnode();

        }
   }

int main()
{
    BStree* root = NULL;
    root = insertBSTnode(root, 14);
    printf("root data= %d\n", root->data);
    printf("= = = = =\n");

    root = insertBSTnode(root, 8);
    root = insertBSTnode(root, 19);
    root = insertBSTnode(root, -3);
    root = insertBSTnode(root, 0);
    root = insertBSTnode(root, -7);
root = insertBSTnode(root, 11);

printf("NOde queues +=++==++==\n");

Enqueue_TQnode(root);
Enqueue_TQnode(root->leftNode);
Enqueue_TQnode(root->rightNode);
/*
print_TQ();
Dequeue_TQnode();
Dequeue_TQnode();

print_TQ();
*/

LevelOrder(root);
    return 0;
}
