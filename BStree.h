#ifndef BSTREE_H_INCLUDED
#define BSTREE_H_INCLUDED

typedef  struct node {
    int data;
    struct node* leftNode;
    struct node* rightNode;
} BStree;

BStree* createBStreeNode(int data){
    BStree* tempBStree = (BStree*)malloc(sizeof(BStree));
    tempBStree->data = data;
    tempBStree->leftNode = NULL;
    tempBStree->rightNode = NULL;
    return tempBStree;
}

BStree* insertBSTnode(BStree* root, int data){
    if (root == NULL){
        root = createBStreeNode(data);
       }
    else if (data <= root->data){
        root->leftNode = insertBSTnode(root->leftNode, data);
       }
    else {
        root->rightNode = insertBSTnode(root->rightNode, data);
       }
       return root;
}


int searchBT(BStree* root, int data){
    if (root == NULL)return -1;
    else if (data == root->data)return 1;
    else if (data <= root->data){

        return searchBT(root->leftNode, data);
    }
    else {

        return searchBT(root->rightNode, data);
    }
}

int findMin(BStree* root){
    if(root == NULL)printf("Empty binary tree\n");
    else if (root->leftNode == NULL)return root->data;
    else findMin(root->leftNode);
}

// number of edges from root to longest leaf path
int findHeightBStree(BStree* root){
    if(root == NULL)return - 1;
    int leftHeight = findHeightBStree(root->leftNode);
    int rightHeight = findHeightBStree(root->rightNode);

    if (leftHeight >= rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

#endif // BSTREE_H_INCLUDED
