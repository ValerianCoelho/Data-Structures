#include <stdio.h>
#include <stdlib.h>
#define newline printf("\n");

struct node{
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct node *insert(struct node *ptr, int data){
    // If the tree is empty or the ptr is a leaf node
    if(ptr == NULL){
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp -> lchild = NULL;
        temp -> rchild = NULL;
        temp -> data = data;
        return temp;
    }

    // If the element to be inserted is smaller than the node
    if(data < ptr -> data){
        ptr -> lchild = insert(ptr -> lchild, data);
    }

    // If the element to be inserted is greater than the node
    else if(data > ptr -> data){
        ptr -> rchild = insert(ptr -> rchild, data);
    }

    // If all the case are false, then we have encountered a node that has the same value as data
    else{
        printf("%d is already present in the tree, Hence insertion not possible", data);
    }

    return ptr;
}

struct node *case_a(struct node *root, struct node *par, struct node *ptr){
    // This means that ptr is the root node, that has no children
    if(par == NULL){
        root == NULL;
    }
    // Deleting ptr by replacing par -> lchild or par -> rchild by NULL
    else if(ptr == par -> lchild){
        par -> lchild = NULL;
    }
    else if(ptr == par -> rchild){
        par -> rchild = NULL;
    }
    free(ptr);
    return root;
}

struct node *case_b(struct node *root, struct node *par, struct node *ptr){
    struct node *child;

    // Since the node has either left or right child, this child pointer will be used to referer to that child
    if(ptr -> lchild != NULL){
        child = ptr -> lchild;
    }
    else if(ptr -> rchild != NULL){
        child = ptr -> rchild;
    }

    // This means that ptr is the root node, the child of the root node will become the new root node
    if(par == NULL){
        root = child;
    }
    // Updating the value of ptr (par -> lchild / par -> rchild) by child
    else if(ptr == par -> lchild){
        par -> lchild = child;
    }
    else if(ptr == par -> rchild){
        par -> rchild = child;
    }
    free(ptr);
    return root;
}

struct node *case_c(struct node *root, struct node *par, struct node *ptr){ // ptr is the node to be deleted
    struct node *parsucc = ptr; // parsucc will be used to refer to the parent of succ
    struct node *succ = ptr -> rchild; // succ = ptr -> rchild, since the inorder sucessor of ptr will always be its right child
    // NOTE: ptr -> rchild is not the inorder sucessor of ptr, this is the possible inorder sucessor. The actuall inoder sucessor is calculated below

    // Calculating the exact inorder sucessor of ptr
    while(succ -> lchild != NULL){
        parsucc = succ;
        succ = succ -> lchild;
    }

    // moving the value stored in the succ node to ptr node
    ptr -> data = succ -> data;

    // Deleting the succ node
    if(succ -> lchild == NULL && succ -> rchild == NULL){
        root = case_a(root, parsucc, succ);
    }
    else{
        root = case_b(root, parsucc, succ);
    }
    return root;
}

struct node *delete(struct node *root, int data){
    struct node *ptr = root;
    struct node *par = NULL; // par will be used to refer to the parent of ptr

    // Searching for the node to be deleted, the node to be deleted will be stored in ptr
    while(ptr != NULL){

        // Element found
        if(data == ptr -> data){
            break;
        }
        par = ptr;

        if(data < ptr -> data){
            ptr = ptr -> lchild;
        }
        if(data > ptr -> data){
            ptr = ptr -> rchild;
        }
    }

    if(ptr == NULL){
        printf("Element doesn't exist\n");
    }
    // Node has 0 children
    else if(ptr -> lchild == NULL && ptr -> rchild == NULL){
        root = case_a(root, par, ptr);
    }
    // Node has 1 child
    else if(ptr -> lchild == NULL || ptr -> rchild == NULL){
        root = case_b(root, par, ptr);
    }
    // Node has 2 children
    else{
        root = case_c(root, par, ptr);
    }
    return root;

}

void inorder(struct node *ptr){
    if(ptr){
        inorder(ptr -> lchild);
        printf("%d ", ptr -> data);
        inorder(ptr -> rchild);
    }
}

void preorder(struct node *ptr){
    if(ptr){
        printf("%d ", ptr -> data);
        preorder(ptr -> lchild);
        preorder(ptr -> rchild);
    }
}

void postorder(struct node *ptr){
    if(ptr){
        postorder(ptr -> lchild);
        postorder(ptr -> rchild);
        printf("%d ", ptr -> data);
    }
}

void minimum(struct node *ptr){
    while(ptr -> lchild != NULL){
        ptr = ptr -> lchild;
    }
    printf("Minimum : %d\n", ptr -> data);
}

void maximum(struct node *ptr){
    while(ptr -> rchild != NULL){
        ptr = ptr -> rchild;
    }
    printf("Maximum : %d\n", ptr -> data);
}

void search(struct node *ptr, int data){
    if(ptr -> data == data){
        printf("%d is present in the tree\n");
    }
    else if(data < ptr -> data){
        search(ptr -> lchild, data);
    }
    else if(data > ptr -> data){
        search(ptr -> rchild, data);
    }
    else{
        printf("Element not present in the tree");
    }
}

void printTree(struct node *ptr, int child, int depth){
    // child:
    // 0 - not a left or a right child
    //-1 - Left child
    // 1 - right child

    int i;
    for(i=0; i<depth; i++)
        printf("³    ");

    if(child == 1){
        printf("ÃÄÄ ");
    }
    else if(child == -1){
        printf("ÀÄÄ ");
    }

    if(ptr == NULL){
        printf("NULL\n");
        return;
    }
    else{
        printf("%d\n", ptr -> data);
    }

    if(ptr -> lchild == NULL && ptr -> rchild == NULL){
        return;
    }
    printTree(ptr -> rchild, 1, depth+1);
    printTree(ptr -> lchild, -1, depth+1);
}

int main()
{
    struct node * root = NULL;
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 5);

    // inorder(root); newline
    
    // root = delete(root, 5);

    // inorder(root); newline

    // minimum(root);
    // maximum(root);
    // search(root, 4);

    printTree(root, 0, -1);
    return 0;
}
