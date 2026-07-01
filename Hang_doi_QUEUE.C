#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Maxlength 1000
typedef int ElementType;

typedef struct {
    ElementType Elements[Maxlength];
    int Front, Rear;
}Queue;


void MAKENULL_QUEUE(Queue *Q) { //HAM tao queue rong 
    Q->Front = -1; // Đây trừ -1 vì khi có 1 ptu đâu tiên vào chỉ cần cho front và rear ++ Xong sao đó cho rear tăng lên là đươc
    Q->Rear = -1;
}

int EMPTLY_QUEUE(Queue Q) { //Dua lam MAKENULL_QUEUE de bic
    return Q.Front == -1 && Q.Rear == -1;
}

int FULL_QUEUE(Queue Q) { //Khi hang doi day => Mang day
    return (Q.Rear - Q.Front + 1) == Maxlength; //(Q.Rear - Q.Front + 1) == Maxlength chưa tối ưa
}

int FRONT(Queue Q) { //Lay phan tu dau tien trong hang doi
    return Q.Elements[Q.Front];
}

void ENQUEUE(ElementType X, Queue *Q) {
    if(FULL_QUEUE(*Q)) {
        return;
    }
    else {
        Q->Rear++;
        Q->Elements[Q->Rear] = X;
    }
}

void DEQUEUE(Queue *Q) {
    if(FULL_QUEUE(*Q)) {
        return;
    }
    else {
        Q->Front++;

    }
}


int main() {
    return 0;
}