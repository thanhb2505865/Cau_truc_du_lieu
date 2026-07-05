#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Thu vien List_Lien_Ket
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

struct Node* END_LIST(List L) {
    return NULL;
}

void INSERT_LIST(int x, struct Node*P, List *L) { // chen x vao vi tri P trong ds L;
    struct Node* T = (struct Node*)malloc(sizeof(struct Node));
    T->Element = x;
    T->Next = P->Next;
    P->Next = T;
}


void DELETE_LIST(struct Node* P, List *L) { // Xoa phtu tai vi tri P trong ds L    
    //P->Next = P->Next->Next
    struct Node* T;
    if (P->Next != NULL) {
        T = P->Next;
        P->Next = T->Next;
        free(T);
    }
}

struct Node* LOCATE(int x, List L) { // Xuat dia chi cua x trong ds L hay la trong bo nho q->Next se khac q 
    struct Node* q = L;
    while (q->Next != NULL) {
        if (q->Next->Element == x) { //
            return q;
        }
        q = q->Next;
    }
    return q; // Neu TH L rong thi se tra ve L ma L->Next = NUll nen ham dung 
}

int APPEND(int X, List* L) { // Them x vao List L neu khong co x thi them vao tra ve 1 con co x thi tra ve 0 va khong them x;
    struct Node* Q = (struct Node*)malloc(sizeof(struct Node));
    Q->Next = NULL;
    Q->Element = X;
    struct Node* p = LOCATE(X, *L);
    if (p->Next != NULL) {
        free(Q);
    }
    else {
        p->Next = Q;
    }
    
}
void INSERT_LIST_LAST(int x, List* L) { // Ham chen x vao cuoi danh sach lien ket don L
    struct Node* Q = (struct Node*)malloc(sizeof(struct Node));
    Q->Element = x;
    Q->Next = NULL;
    struct Node* q = *L;
    while(q->Next != NULL) {
        q = q->Next;
    }
    q->Next = Q;
}
int RETRIEVE(struct Node* P, List L) { // Lay gia tri cua P trong ds l dia chi cua P dung hon la gia tri P->Next (O truoc P)
    if(P->Next !=NULL) {
        return P->Next->Element;
    }
    else {
        return 0;
    }
}

List READ_LIST() { // Khong dung INSERT
    List L;
    MAKENULL_LIST(&L);
    int n;
    scanf("%d", &n);
    struct Node* Q = L;
    int i;
    for (i = 0; i < n; i++) {
        int temp;
        struct Node* p = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &temp);
        p->Element = temp;
        p->Next = NULL;
        Q->Next = p;
        Q = Q->Next;
    }
    return L;
}

List READ() {
    List L;
    MAKENULL_LIST(&L);
    int n;
    scanf("%d", &n);
    struct Node* Q = L;
    int i;
    for (i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        INSERT_LIST(temp, Q, &L); // Q->Next = T1
        Q = Q->Next;
    }
    return L;
}

void PRINT_LIST(List L) {
    struct Node* Q = L->Next;
    while (Q != END_LIST(L)) {
        printf("%d ", Q->Element);
        Q = Q->Next;
    }
}

int main() {
    List L;
    L = READ();
    PRINT_LIST(L);
    return 0;
}
