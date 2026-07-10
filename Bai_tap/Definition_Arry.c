
#define Maxlength 100
typedef struct {
    int Elements [Maxlength];
    int Last;
} List;

void makenullList(List *L) {
    L->Last = 0;
}

int locate1(int x, List L) { // Tra ve tri chi chu khong phai chi so
    int i;
    for(i = L.Last; i >= 0; i--) {
        if(L.Elements[i] == x) {
            return i + 1;
        }
    }
    return L.Last + 1;
}


void insertList(int x, int p, List *L) { //p la vi tri tương đương chỉ số + 1
    int i;
    for (i = L->Last; i > p - 1; i--) {
        L->Elements[i] = L->Elements[i - 1];       
    }
    L->Elements[p - 1] = x;
    L->Last++;
}

void deleteList(int p, List* L) {
    if(p > L->Last) {
        printf("Vi tri khong hop le\n");
    }
    else {
        int i;
        for(i = p - 1; i < L->Last; i++) {
            L->Elements[i] = L->Elements[i + 1];
        }
        L->Last--;
    }
}

int locate(int x, List L) {
    int i;
    for (i = L.Last - 1; i >= 0; i--) {
        if(L.Elements[i] == x) return i + 1;
    }
    return L.Last + 1;
}

void erase(int x, List* L) {
    deleteList(locate(x, *L), L);
    return;
}

void removeAll(int x, List* L) {
    while(locate(x, *L) != L->Last + 1) {
        deleteList(locate(x, *L), L);
    }
}   

void printList(List L) {
    int i;
    for(i = 0; i < L.Last; i++) {
        printf("%d ", L.Elements[i]);
    }
    printf("\n");
}

void readList(List *L) {
    scanf("%d", &(L->Last));
    int i;
    for(i = 0; i < L->Last; i++) {
        scanf("%d", &(L->Elements[i]));
    }
}

int member(int x, List L) {
    int i = 0;
    while(L.Elements[i] != x) {
        if(i + 1 == L.Last){
            return 0;
        }
        i++;
    }
    return 1;
}

void insertSet(int x, List* L) {
    L->Elements[L->Last] = x;
    L->Last++;
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
        return  -10000.0000;
    }
}

void unionSet(List L1, List L2, List* L) {
    makenullList(L);
    int i;
    *L = L1;
    for (i = 0; i < L2.Last; i++) {
        if(member(L2.Elements[i], *L) == 0) {
            insertSet(L2.Elements[i], L);
        }
    }
}

void difference(List L1, List L2, List* L) {
    makenullList(L);
    int i;
    for (i = 0; i < L1.Last; i++) {
        if(member(L1.Elements[i], L2) == 0) { // 1
            insertSet(L1.Elements[i], L);
        }
    }    
}


void sort(List* L) {
    int i, j;
    for(i = 0; i < L->Last; i++) {
        for(j = i + 1; j < L->Last; j++) {
            if(L->Elements[i] >= L->Elements[j]) {
                int temp = L->Elements[j];
                L->Elements[j] = L->Elements[i];
                L->Elements[i] = temp;
            }
        }
    }
}

void normalize(List* L) { //Xoa xong se co khau doi phtu nen j co the bo sot
    int i, j;
    for (i = 0; i < L->Last; i++) {
        for(j = i + 1; j < L->Last; j++) {
            if(L->Elements[i] == L->Elements[j]) {
                deleteList(j+1, L);
                j--;
            }
        }
    }
}

void printOddNumbers(List L) {
    int i;
    for(i = 0; i < L.Last; i++) {
        if(L.Elements[i] % 2 != 0) {
            printf("%d ", L.Elements[i]);
        }
    }
}

void copyEvenNumbers(List L1, List* L2) {
    makenullList(L2);
    int count = 1;
    int i;
    for(i = 0; i < L1.Last; i++) {
        if (L1.Elements[i] % 2 == 0) {
            insertList(L1.Elements[i], count, L2);
            count++;
        }
    }
}

void readSet(List* L) {
    makenullList(L);
    int size; scanf("%d", &size);
    for(int i = 0; i < size; i++) {
        int temp;
        scanf("%d", &temp);
        if(member(temp, *L) == 0) {
            insertSet(temp, L);
        }
    }
}

void intersection(List L1, List L2, List* L) {
    makenullList(L);
    int i;
    for (i = 0; i < L1.Last; i++) {
        if(member(L1.Elements[i], L2)) {
            insertSet(L1.Elements[i], L);
        }
    }    
}
