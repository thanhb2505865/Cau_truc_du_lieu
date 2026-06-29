#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    int Element;
    struct Node* Next;
};
typedef struct Node* Position;
typedef Position List; // List là kiểu dữ liệu con trỏ Node;

typedef struct {
    char ID[10];
    char Name[50];
    float R1, R2, R3;
}Student;

// Thiết kế thư viện liên kết đơn 

void MAKENULL_LIST(List *L) {
    *L = (struct Node*)malloc(sizeof(struct Node));
    (*L)->Next = NULL;
}

int EMPTY_LIST(List L) {
    return L->Next == NULL;
}

void INSERT_LIST(int x, Position P, List *L) { // chen x vao vi tri P trong ds L;
    Position T = (Position)malloc(sizeof(struct Node));
    T->Element = x;
    T->Next = P->Next;
    P->Next = T;
}

void DELETE_LIST(Position P, List *L) { // Xoa phtu tai vi tri P trong ds L    
    Position T = P;

}

Position LOCATE(int x, List L) { // Xuat dia chi cua x trong ds L hay la trong bo nho q->Next se khac q 
    Position q = L;
    while (q->Next != NULL) {
        if (q->Next->Element == x) { //
            return q;
        }
        q = q->Next;
    }
    return q;
}

int RETRIEVE(Position P, List L) { // Lay gia tri cua P trong ds l dia chi cua P 
    if(P->Next !=NULL) {
        return P->Next->Element;
    }
    else return;
}
int main() {
    return 0;
}
