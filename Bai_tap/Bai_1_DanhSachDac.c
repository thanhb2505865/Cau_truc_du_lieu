#include <stdio.h>
#include <stdlib.h>

#define Maxlength 100

typedef struct {
    int Elements [Maxlength];
    int Last;
} List;

int locate(int n, List L) {
    int i;
    for (i = L.Last - 1; i >= 0; i--) {
        if(L.Elements[i] == n) return i + 1;
    }
    return L.Last + 1;
}

void deleteList(int p, List* L) {
    int i;
    if (locate(p, *L)) {
        for (i = p - 1; i < L->Last; i++) {
        L->Elements[i] = L->Elements[i + 1];
        L->Last--;
        }
    }
    else {
        return;
    }
}

void erase(int x, List* L) { // Ham xoa ki tu dau tien cua x trong List 
    deleteList(locate(x, *L), L);
    return;
}

void removeAll(int x, List* L) { 
    while(locate(x, *L) != L->Last + 1) {
        deleteList(locate(x, *L), L);
    }
}

void insertList(int x, int p, List *L) { //p la vi tri tương đương chỉ số + 1
    int i;
    for (i = L->Last; i > p - 1; i--) {
        L->Elements[i] = L->Elements[i - 1];       
    }
    L->Elements[p - 1] = x;
    L->Last++;
}

void printList(List L) { // Ham xoa x trong List 
    int i = 0;
    while(i < L.Last) {
        printf("%d ", L.Elements[i]);
        i++;
    }
}

void readList(List *L) {
    int total; // Han che sd L->Last de tranh loi sai khi sd ham insert
    scanf("%d", &total);
    int i = 0;
    int n;
    L->Last = 0;
    while(i < L->Last) {
        scanf("%d", &n);
        insertList(n, i + 1, L); 
        i++;
    }
}

void member(int x, List L) {
    int i = 0;
    while(L.Elements[i] != x) {
        if(i + 1 == L.Last) return 0;
        i++;
    }
    return 1;
}

void insertSet(int x, List* L) { //Ham chen vao cuoi List
    L->Elements[L->Last] = x;
    L->Last++;
    //insertList(x, L->Last + 1, L); Co the viet nhu vay nhung thuat toan no se nhieu hon
}

float getAvg(List L) {
    if (L.Last) {
        int total = 0;
    int i = 0;
    while(i < L.Last) {
        total += L.Elements[i];
        i++;
    }
    return total / L.Last;
    }
    else {
        return -1000000;
    }
}

int main() {
}