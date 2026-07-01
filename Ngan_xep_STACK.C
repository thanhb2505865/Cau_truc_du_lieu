#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Thu vien Stack 
typedef char ElementType;
#define Maxlength 100

typedef struct {
    ElementType Elements[Maxlength];
    int Top_index;
}Stack; // La truong hop dac biet cua danh sach dac duoc sap xep theo kieu xep chong 

void MAKENULL_STACK(Stack *S) { // Khoi tao mot Stack rong 
    S->Top_index = Maxlength;
}

int EMPTLY_STACK(Stack S) { // Kiem tra Stack rong hay khong
    return S.Top_index == Maxlength;
}

int FULL_STACK(Stack S) { // Kiem tra coi Stack co full chua
    return S.Top_index == 0;
}

void PUSH(ElementType X, Stack* S) { //Them phan tu vao Stack
    S->Top_index--;
    S->Elements[S->Top_index] = X;
}

void POP(Stack* S) { //Xoa phan tu dau trong Stack
    if(EMPTLY_STACK(*S)) { // *S dua gia tri ben trong cua con tro 
        return;
    }
    else {
        S->Top_index++;
    }
}

ElementType TOP(Stack S) { //Lay phan tu dau tien trong Stack 
    if(EMPTLY_STACK(S)) {
        return 0;
    }
    else {
        return S.Elements[S.Top_index];
    }
}

void inThaplucphan(int n) { // Doi gia tri thap luc phan sang luc phan
    char chu[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'E', 'F'};
    Stack* S = (Stack*)malloc(sizeof(Stack));
    MAKENULL_STACK(S);
    while(n > 0) { 
        PUSH(chu[n % 16], S);
        n /= 16;
    }
    while(!EMPTLY_STACK(*S)) {
        TOP(*S);
        POP(S);
    }
}

int main() {
    inThaplucphan(50);
    return 0;
}
