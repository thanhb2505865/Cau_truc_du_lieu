typedef struct {
    int Elements [Maxlength];
    int Last;
} List;

int locate1(int n, List L) {
    int i;
    for (i = L.Last - 1; i >= 0; i--) {
        if(L.Elements[i] == n) return i + 1;
    }
    return L.Last + 1;
}

void deleteList(int p, List* L) {
    int i;
    if (locate1(p, *L)) {
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

