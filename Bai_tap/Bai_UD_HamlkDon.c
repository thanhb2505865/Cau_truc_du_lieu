//#include <PListLib.c>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int Element;
    struct Node* Next;
};

typedef struct Node* List;

void makenullList(List *L) {
    *L = (struct Node*)malloc(sizeof(struct Node));
    (*L)->Next = NULL;
}

int emptyList(List L) {
    return L->Next == NULL;
}

void insertList(int X, struct Node* Q, List *L) {
    struct Node* T = (struct Node*)malloc(sizeof(struct Node));
    T->Element = X;
    T->Next = Q->Next;
    Q->Next = T;
}

List readList() {
    int n;
    int i;
    scanf("%d", &n);
    List L;
    makenullList(&L);
    struct Node* Q = L;
    for (i = 0; i < n; i++){
        int temp;
        scanf("%d", &temp);
        insertList(temp, Q, &L);
        Q = Q->Next;
    }
    return L;
}

void printList(List L) {
    struct Node* Q = L->Next;
    while (Q != NULL) {
        printf("%d ", Q->Element);
        Q = Q->Next;
    }
    printf("\n"); 
}


int retrieve(struct Node* Q ,List L) {
    if (Q->Next != NULL) {
        return Q->Next->Element;
    }
    else return 0;
}

float average(List L) {
    float result = 0;
    float count = 0;
    struct Node* Q = L->Next;
    while(Q != NULL) {
        result += Q->Element;
        count++;
        Q = Q->Next;
    }
    return result / count;
}

struct Node* locate(int x, List L) {
    struct Node* Q = L;
    while(Q->Next != NULL) {
        if(Q->Next->Element == x) {
            return Q;
        }
        Q = Q->Next;
    }
    return Q;
}

void delete(struct Node* Q, List* L) { // Xoa Q->Next va nhay Q
    if (Q->Next != NULL) {
        struct Node* T;
        T = Q->Next;
        Q->Next = T->Next;
        free(T);
    }
    else return;
}

void deleteList(int x, List* L) {
    struct Node* Q = *L;
    while(Q->Next != NULL) { 
        if (Q->Next->Element == x) {
            delete(Q, L); //Luu y sao khi xoa xong Q se nhay len nen khi da thuc hiem ham detele thi khong can Q = Q->Next tranh nhay phan tu
        }
        else {
            Q = Q->Next;
        }
        
    }
}


int main() {
    
    return 0;
}