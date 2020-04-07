#ifndef QUEUEINT_H_INCLUDED
#define QUEUEINT_H_INCLUDED

struct Node* front_int = NULL;
struct Node* rear_int = NULL;


void Enqueue_int(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if(front_int == NULL && rear_int == NULL){
        front_int = rear_int = temp;
        return;
    }
    rear_int->next = temp;
    rear_int = rear_int->next;
}

void Dequeue_int(){
    struct Node* temp = front_int;
    if (front_int == NULL){
            printf("Empty Queue!\n\n");
        return;
    }
    else {
        front_int = front_int->next;
    }
    free(temp);
}

#endif // QUEUEINT_H_INCLUDED
