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

int append(ElementType x, List* L) {
	struct Node* Q = (struct Node*)malloc(sizeof(struct Node));
	Q->Element = x;
	Q->Next = NULL;
	struct Node* P = locate(x, *L);
	if (P->Next != NULL) {
		free(Q);
		return 0;
	}
	else {
		P->Next = Q;
		return 1;
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
		while(P->Next->Element != Q->Element) {
		    P = P->Next;
		}
		deleteList(P, L);
		Q = Q->Next;
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

void copyEvenNumbers
int main() {

}
