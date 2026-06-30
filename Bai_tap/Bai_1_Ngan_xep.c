#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int ElementType;
#define Maxlength 100
#define M 100

typedef struct {
    int DuLieu[M];
    int Dinh;
}NganXep;

void khoitao(NganXep *S) {
    S->Dinh = M;
}

int ktRong(NganXep S) {
    return S.Dinh == M;
}

int ktDay(NganXep S) {
    return S.Dinh == 0;
}

void them(int x, NganXep* S) {
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

int giatriDinh(NganXep S) {
    return S.DuLieu[S.Dinh];
}

void hienthi(NganXep* S) {
    NganXep *P = (NganXep*)malloc(sizeof(NganXep));
    *P = *S; // Tao ra tro P chua du lieu ss voi NganXep S hoac C2 NganXep P = *S; khi nay sẽ tao ra 1 biến P chưa dữ liệu của con trỏ S 
    while(!ktRong(*P)) {
        printf("%d", P->DuLieu[P->Dinh]);
        xoa(P);     // C2 k cần
    }
    free(P);
}



int main() {
    return 0;
}