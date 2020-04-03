#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* nodeTempPointer = (struct Node*)malloc(sizeof(struct Node));
    nodeTempPointer->data = data;
    nodeTempPointer->next = NULL;
    return nodeTempPointer;
}

void print_list(struct Node* headofList){
    int order = 1;
    struct Node* tempPointer = headofList;

    if(headofList == NULL){
            printf("Empty List!\n");
            return;
    }

    while(tempPointer != NULL){
         printf("node-%d-data=%d\n", order, tempPointer->data);
         tempPointer = tempPointer->next;
         order++;
    }

}

void addNodeToBegginingOfList(struct Node** headOfList, struct Node* nodeToAdd){
    nodeToAdd->next = *headOfList;
    *headOfList = nodeToAdd;
}

// Position 1 is the head node
void insertDataToNthPosition(struct Node** head, int dataToAdd, int NthPosition){
    if (NthPosition < 1){
        printf("Position %d out of range!\n", NthPosition);
        printf("Remember, Position 1 is the head node\n");
        return;
    }

    if ( NthPosition == 1 ){
        addNodeToBegginingOfList(head, createNode(dataToAdd));
        return;
    }

    if (NthPosition >1) {
            int counter = 0;
            struct Node* current = *head;

        while((counter < NthPosition -2 )){
            printf("current data= %d\n", current->data);
            current = current->next;
            counter++;
            if (current == NULL){
                printf("Position %d out of range!\n", NthPosition);
                printf("Remember, Position 1 is the head node\n");
            }
             }
        struct Node* newNode = createNode(dataToAdd);
        newNode->next = current->next;
        current->next = newNode;
    }
}

void iteratively_reverse_list(struct Node** head){
    struct Node* current = *head;
    struct Node* next = NULL;
    struct Node* previous = NULL;

    while(current != NULL){
        next = current->next;
        current->next= previous;

        previous = current;
        current = next;
    }
    *head = previous;
}

void print_reverse_list_recursively(struct Node* headNode){

    struct Node* current = headNode;
   if (current == NULL){return;}

    struct Node* nextNode = current->next;
    print_reverse_list_recursively(nextNode);
    printf("value=%d\n", current->data);

}
#endif // LINKLIST_H_INCLUDED
