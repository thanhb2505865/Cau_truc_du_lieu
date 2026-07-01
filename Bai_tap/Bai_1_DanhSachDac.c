
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
    L = (List*)malloc(sizeof(List));
    scanf("%d", &L->Last);
    int i = 0;
    int n;
    while(i < L->Last) {
        scanf("%d", &n);
        insertList(n, i, L);
        i++;
    }
}