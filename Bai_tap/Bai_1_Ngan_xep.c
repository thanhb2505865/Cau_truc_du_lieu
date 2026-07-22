#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char ElementType;
#define Maxlength 100
#define M 100

typedef struct {
    ElementType DuLieu[M];
    int Dinh;
} NganXep;


void khoitao(NganXep *S) {
    S->Dinh = M;
}

int ktRong(NganXep S) { // Neu danh sach rong tra ve 1, danh sach k rong tra ve 0;
    return S.Dinh == M; 
}

ElementType ktDay(NganXep S) {
    return S.Dinh == 0;
}

void them(ElementType x, NganXep* S) {
    if (ktDay(*S)) {
        return;
    }
    else {
        S->Dinh--;
        S->DuLieu[S->Dinh] = x;
    }
}

void xoa(NganXep *S) {
    if(ktRong(*S)) {
        return;
    }
    else{
        S->Dinh++;
    }
}

ElementType giatriDinh(NganXep S) {
    return S.DuLieu[S.Dinh];
}

void hienthi(NganXep* S) {
    NganXep *P = (NganXep*)malloc(sizeof(NganXep));
    *P = *S; // Tao ra tro P chua du lieu ss voi NganXep S hoac C2 NganXep P = *S; khi nay sẽ tao ra 1 biến P chưa dữ liệu của con trỏ S 
    while(!ktRong(*P)) {
        printf("%c", P->DuLieu[P->Dinh]);
        xoa(P);     // C2 k cần
    }
    free(P);
}

void doiNhiPhan(int n, NganXep* S) {
    khoitao(S);
    while(n > 0) { 
        them(n % 2, S);
        n /= 2;
    }
}
// 

void inThaplucphan(int n) {
    char chu[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    NganXep* S = (NganXep*)malloc(sizeof(NganXep));
    khoitao(S);
    while(n > 0) { 
        push(chu[n % 16], S);
        n /= 16;
    }
    while(!ktRong(*S)) {
        printf("%c", giatriDinh(*S));
        xoa(S);
    }
}

int ktChuoi() { // Ngoac dung tra ve 1; khong dung tra ve 0
    char x[100];
    fgets(x, sizeof(x), stdin);
    Stack S;
    makenullStack(&S);
    int i = 0;
    while(x[i] != '\0') {
        if(x[i] == '(') {
            push(x[i], &S);
        }
        else if(x[i] == ')') {
            if (emptyStack(S)) { //emptyStack(S) == 1
                return 0;
            }
            else {
                pop(&S);
            }
        }
        i++;
    }
    // Danh sach no phai rong moi dung 
    return emptyStack(S); //Tre ve 1 
}

float change_digit(char x) {
    char digit[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    float i;
    while(strcmp(digit[i], x) != 0) {
        i++
    }
    return i;
}

float tinhGiatri(char x[]) {
    int i = 0;
    Stack S;
    makenullStack(&S);
    while(x[i] != '\0') {
        push(x[i], &S);
        if(x[i] == '*') {
            float number1 = change_digit(top(S));
            pop(&S);
            float number2 = change_digit(top(S));
            pop(&S);
            push(number1 * number2, &S);
        }
        else if(x[i] == '/') {
            float number1 = change_digit(top(S));
            pop(&S);
            float number2 = change_digit(top(S));
            pop(&S);
            push(number1 / number2, &S);
        }
        else if(x[i] == '+') {
            float number1 = change_digit(top(S));
            pop(&S);
            float number2 = change_digit(top(S));
            pop(&S);
            push(number1 + number2, &S);
        }
        else if(x[i] == '-') {
            float number1 = change_digit(top(S));
            pop(&S);
            float number2 = change_digit(top(S));
            pop(&S);
            push(number1 - number2, &S);
        }
        i++;
    }
    return top(S);
} 
int main() {
    int n;
    scanf("%d",&n);
    inThaplucphan(n);
    return 0;
}