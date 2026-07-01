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

ElementType ktRong(NganXep S) {
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



int main() {
    int n;
    scanf("%d",&n);
    inThaplucphan(n);
    return 0;
}