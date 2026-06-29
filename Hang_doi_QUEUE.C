#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Maxlength 1000
typedef int ElementType;


typedef struct {
    ElementType Elements[Maxlength];
    int Front, Rear;
}Queue;


void MAKENULL_QUEUE(Queue *Q) {
    Q->Front = -1;
    Q->Rear = -1;
}

int main() {
    return 0;
}