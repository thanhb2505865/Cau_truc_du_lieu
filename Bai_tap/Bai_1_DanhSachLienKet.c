#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElementType;

typedef struct {
    char Name[50];
    char ID[10];
    float R1, R2, R3;
}Student;

    /*scanf(" "); //skip some characters  // Code mau nhap du lieu vao 
	fgets(st,10,stdin);
	if (st[strlen(st)-1] == '\n')
		st[strlen(st)-1] = '\0';
	strcpy(s.ID, st);
	fgets(st,50,stdin);
	if (st[strlen(st)-1] == '\n')
		st[strlen(st)-1] = '\0';
	strcpy(s.Name, st);
	scanf("%f%f%f",&s.R1,&s.R2,&s.R3);
    */    

struct Node{
    Student Element;
    struct Node* Next;
};
typedef struct Node* List;

struct Node* locate(char x[], List L) { // Tra ve P->Next->Element == x, k tra ve P
    struct Node* q = L;
    while(q->Next != NULL) {
        if(strcmp(x, q->Next->Element.ID) == 0) {
            return q; 
        }
        q = q->Next;
    }
    return q;
}

List getList() {
    List L = (struct Node*)malloc(sizeof(struct Node));
    L->Next = NULL;
    return L;
} 


int append(Student s, List* L) {
    struct Node* Q = (struct Node*)malloc(sizeof(struct Node));
    Q->Next = NULL;
    Q->Element = s;
    struct Node* p = locate(s.ID, *L);
    if (Q->Next != NULL) { 
            free(Q);
        return 0;
    }
    else {
        p->Next = Q;
    }
}

void showPassedList(List L) {
    struct Node* p = L;
    int count = 1;
    while(p->Next != NULL) {
        if(((p->Element.R1 + p->Element.R2 + p->Element.R3) / 3.0) >= 4.0) {
            printf("%2d - %10s - %50s - %.3f - %.3f - %.3f - %.3f\n", count,  p->Element.Name, p->Element.R1, p->Element.R2, p->Element.R3, (p->Element.R1 + p->Element.R2 + p->Element.R3) / 3.0);
            count++;
        }
    }
    printf("%d students in total", count - 1);
}

List readList()
{
	int n,i;
	Student s;
	char st[50];
	List L = getList(); // Khởi tạo danh sách rỗng
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf(" "); //skip some characters
		fgets(st,10,stdin);
		if (st[strlen(st)-1] == '\n')
			st[strlen(st)-1] = '\0';
		strcpy(s.ID, st);
		fgets(st,50,stdin);
		if (st[strlen(st)-1] == '\n')
			st[strlen(st)-1] = '\0';
		strcpy(s.Name, st);
		scanf("%f%f%f",&s.R1,&s.R2,&s.R3);
		append(s, &L);
	}
	return L;
}

void printList(List L) {
    int k = 1;
    struct Node* p = L;
    while (p->Next != NULL) {
        printf("%2d - %10s - %50s - %.3f - %.3f - %.3f - %.3f\n", k, p->Next->Element.ID, 
				p->Next->Element.Name, p->Next->Element.R1, p->Next->Element.R2,
				p->Next->Element.R3, (p->Next->Element.R1 + p->Next->Element.R2 + p->Next->Element.R3) / 3);
		p = p->Next;
		k++;
    }
}

int main() {

    return 0;
}