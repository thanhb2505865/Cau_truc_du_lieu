#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//
typedef int ElementType;

typedef struct {
    ElementType Elements;
    Node* LeftChild;
    Node* RightSibling;
}Node;

typedef Node* Tree;

void MAKE_NULL(Tree* T) { // Co the goi la ham ktra la
    (*T) = (Node*)malloc(sizeof(Node));
    (*T)->LeftChild = NULL;
    (*T)->RightSibling = NULL;
}

int EMPTY(Tree T) {
    return T->LeftChild == NULL && T->RightSibling == NULL;
}

ElementType ROOT(Tree T) { // tra ve gia tri cua parents 
    return T->Elements;
}

Tree Right(Tree T) {
    return T->LeftChild->RightSibling;
}

Tree CREAT_NODE(ElementType X) {
    Tree T;
    MAKE_NULL(T);
    T->Elements = X;
    return T;
}

void PREORDER(Tree T) {
    Node* q = Right(T);
    ROOT(T);
    if (EMPTY(T)) {
        return;
    }
    else {
        PREORDER(T->LeftChild);
        while (q != NULL) {
            PREORDER(q);
            q = q->RightSibling;
        }

    }
}

Tree FIND_NODE(ElementType X, Tree L) {


}
int main() {

    return 0;
}