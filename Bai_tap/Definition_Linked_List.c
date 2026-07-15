#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

struct Node {
    ElementType Element;
    struct Node* Next;
};

typedef struct Node* Position;
typedef Position List;

void makenullList(List* L) {
	(*L) = (struct Node*)malloc(sizeof(struct Node));
	(*L)->Next = NULL;
}

void insertList(ElementType x, Position p, List* L){
	struct Node* T = (struct Node*)malloc(sizeof(struct Node)); // kieu du
	T->Next = p->Next;
	T->Element = x;
	p->Next = T;
}

void deleteList(Position P, List* L) {
	Position Temp;
	Temp = P->Next;
	P->Next = Temp->Next;
	free(Temp);
}

Position locate(ElementType x, List L) {
	struct Node* P = L;
	while (P->Next != NULL) {
		if (P->Next->Element == x) {
			return P;
		}
		P = P->Next;
	}
	return P;
}

void append(ElementType x, List* L) {
	struct Node* Q = (struct Node*)malloc(sizeof(struct Node));
	Q->Element = x;
	Q->Next = NULL;
	struct Node* P = locate(x, *L);
	if (P->Next != NULL) {
		free(Q);
	}
	else {
		P->Next = Q;
	}
}

void addFirst(ElementType x, List* L) {
	insertList(x, *L, L);
}

void readList(List *L) {
	makenullList(L);
	int size;
	scanf("%d", &size);
	struct Node* p = *L;
	int i, temp;
	for(i = 0; i < size; i++) {
		scanf("%d", &temp);
		insertList(temp, p, L);
		p = p->Next;
	}
}

void erase(ElementType x, List* L) {
	Position Q = locate(x, *L);
	if (Q->Next == NULL) {
	    printf("Not found %d\n", x);
	    return;
	}
	deleteList(Q, L);
}

void removeAll(ElementType x, List* L) {	
	while(locate(x, *L)->Next != NULL) {
	    deleteList(locate(x, *L), L);
	}
}

void normalize(List *L) {
	struct Node* Q = (*L)->Next;
	while (Q != NULL) {
		struct Node* P = Q;
		while(P->Next != NULL) {
		    if(P->Next->Element == Q->Element) {
		        deleteList(P, L);
		    }
		    else {
		        P = P->Next;
		    }
		}
		Q = Q->Next;
    }
}

void printOddNumbers(List L) {
	struct Node* Q = L;
	while(Q->Next != NULL) {
		if (Q->Next->Element % 2 == 0) {
			printf("%d ", Q->Next->Element);
		}
		Q = Q->Next;
	}
}

void copyEvenNumbers(List L1, List* L2) {
	makenullList(L2);
	struct Node* Q = L1;
	while (Q->Next != NULL) {
		if(Q->Next->Element % 2 == 0) {
			append(Q->Next->Element, L2);
		}
		Q = Q->Next;
	}
}


float getAvg(List L) {
    if (L->Next == NULL) {
        return -10000.000;
    }
	struct Node* Q = L;
	int count = 0;
	float result = 0;
	while(Q->Next != NULL) {
		result += Q->Next->Element;
		count++;
		Q = Q->Next;
	}
	return result / count;
}

int member(ElementType x, List L) {
    return locate(x, L)->Next != NULL;
}


List readSet() {
    List* L;
    *L = (struct Node*)malloc(sizeof(struct Node));
    (*L)->Next = NULL;
    int n;
    int i;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        if(member(temp, *L) == 0) { 
            addFirst(temp, L);
        }
    }
}

List unionSet(List L1, List L2) { // Kiem tra L2 khong co gan them vao cuoi L1
    struct Node* Q = L2;
    while(Q->Next != NULL) {
        if (member(Q->Next->Element, L1) == 0) {
            append(Q->Next->Element, &L1);
        }
        Q = Q->Next;
    }
    return L1;
}

List intersection(List L1, List L2) { // Kiem tra L2 khong co gan them vao cuoi L1
    List intersection;
    makenullList(&intersection);
    struct Node* Q = L2;
    while(Q->Next != NULL) {
        if (member(Q->Next->Element, L1)) {
            append(Q->Next->Element, &intersection);
        }
        Q = Q->Next;
    }
    return intersection;
}

void sort_1(List *L) {
    Position i, j;
    for(i = (*L)->Next; i != NULL; i = i->Next) {
        for(j = i->Next; j != NULL; j = j->Next) {
            if(i->Element >= j->Element) {
                int temp = j->Element;
                j->Element = i->Element;
                i->Element = temp;
            }
        }
    }
}

// Hinh thanh y tuong ss bang dslk don (Có thể dùng hàm min va max trong ds liên kết)
// Mình sẽ tạo ra một con struct Node sao đó thiệt lặp điều kiện và nối vô cái struct Node đó sao cho nó luôn ở đầu của toa để lấy nó làm mốc đặt đk là bé hơn và nhỏ hơn nó. 
// B1: tao ra 1 ds dung hon 1 node dau cua 1 ds // struct Node* sorted = NULL;
// B2: Tao mot toa co lam dau de tranh mat du lieu toa góc // struct Node* current = L->Next;
// B3: Từ ý tưởng sẽ có 1 toa đầu làm đk ss // sorted đặt đk quanh nó
//  +TH1: sorted > toa moi thi la nó sẽ toa mới sẽ nối vô nó, xong bỏ sorted vào toa mới thêm vào. có thể nói luôn để min cua toa là sorted 
//      +TH1: Thêm lần đâu 
//      +Th2: sorted > toa moi
//  +TH2: sorted < toa moi thi ta sẽ đặt while chạy từng ptu vao toa moi sao cho nó kiếm tk lớn nhất hiện tại và nối nó vào tk mới vào 
//      +TH1: Chạy tới cuối 
//      +TH2: Chạy vừa đủ 
// B4: Nối toa tàu //L->Next = sorted; 

void sort(List *L) {
    struct Node* sorted = NULL;
    struct Node* current = (*L)->Next;
    while(current != NULL) {
        struct Node* next = current->Next;
        if(sorted == NULL || sorted->Element >= current->Element) {
            current->Next = sorted;
            sorted = current;
        }
        else {
            struct Node* p =sorted;
            while(p->Next != NULL && p->Next->Element < current->Element) { // 0 & 1 => 0
                p = p->Next;
            }
			current->Next = p->Next;
			p->Next = current;
        }
        current = next;
    (*L)->Next = sorted;
    }
}

List difference(List L1, List L2) {
    List L;
    makenullList(&L);
    struct Node* Q = L1;
    struct Node* P = L->Next;
    while(Q->Next != NULL) {
        if(locate(Q->Next->Element, L2)->Next == NULL) {
            insertList(Q->Next->Element, P, &L);
            P = P->Next;
        }
        Q = Q->Next;
    }
    return L;

}
int main() {

	return 0;
}
