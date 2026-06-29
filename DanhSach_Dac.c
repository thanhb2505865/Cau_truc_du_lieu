// Cac ham thuong gap cua DS Don
#include <stdio.h>
#define MaxLength 100;

typedef int Position;
typedef float ElemenType;

typedef struct {
    ElemenType Elements[MaxLength];
    Position Last; // Vi tri cua danh sach
} List;

void MAKENULL_LIST(List *L) { // Ham de tra ve mot cai danh sach rong 
    L -> Last = 0;
}

int EMPLTY_LIST(List L) {
    return L.Last == 0;
}

void INSERT_LIST(ElemenType x, Position p, List*L) {
    if (L->Last == MaxLength) {
        printf("Danh sach day khong chen duoc");
    }
    else {
        if (p < 1 || p > L->Last + 1) {
            printf("Vi tri khong hop le");
        }
        else {
            for (int i = L->Last; i > p - 1; i--) {
                L->Elements[i] = L->Elements[i - 1];
            }
        }
    }
    L->Elements[p - 1] = x;
    L->Last++;
}

void DELETE_LIST(Position p, List *L) {
    if (p < 1 || p > L->Last) {
        printf("Vi tri xoa k hop le");
    }
    else {
        for (int i = p; i < L->Last; i++) {
            L->Elements[i - 1] = L->Elements[i];
        }
        L->Last--;
    }
}

Position LOCATE(ElemenType x, List L) {
    Position i = 1;
    while(L.Elements[i - 1] != x) {
        i++;
    }
    if (i > L.Last) {
        return 0;
    }
    return i;
}

Position FIRST(List L) {
    return 1;
}

Position RETRIVE(Position p, List L) {
    if (p > L.Last) {
        return 0;
    }
    else {
        return L.Elements[p - 1];
    }
}

void READ_LIST(List *L) {
    scanf("%d", L->Last);
    for(int i = 0; i < L->Last; i++) {
        scanf("%d", L->Elements[i]);
    }
}

void PRINT_LIST(List L) {
    for(int i = 0; i < L.Last; i++) {
        printf("%d", L.Elements[i]);
    }
}

int main() {

    return 0;
}