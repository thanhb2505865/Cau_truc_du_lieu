//#include <PListLib.c>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int Element;
    struct Node* Next;
};

typedef struct Node* List;

void makenullList(List *L) {
    *L = (struct Node*)malloc(sizeof(struct Node));
    (*L)->Next = NULL;
}

int emptyList(List L) {
    return L->Next == NULL;
}

void insertList(int X, struct Node* Q, List *L) {
    struct Node* T = (struct Node*)malloc(sizeof(struct Node));
    T->Element = X;
    T->Next = Q->Next;
    Q->Next = T;
}

void insertFirst(int x, List* L) {
    struct Node* T = (struct Node*)malloc(sizeof(struct Node));
    T->Element = x;
    T->Next = (*L)->Next;
    (*L)->Next = T;
}

List readList() {
    int n;
    int i;
    scanf("%d", &n);
    List L;
    makenullList(&L);
    struct Node* Q = L;
    for (i = 0; i < n; i++){
        int temp;
        scanf("%d", &temp);
        insertList(temp, Q, &L);
        Q = Q->Next;
    }
    return L;
}

void printList(List L) {
    struct Node* Q = L->Next;
    while (Q != NULL) {
        printf("%d ", Q->Element);
        Q = Q->Next;
    }
    printf("\n"); 
}


int retrieve(struct Node* Q ,List L) {
    if (Q->Next != NULL) {
        return Q->Next->Element;
    }
    else return 0;
}

float average(List L) {
    float result = 0;
    float count = 0;
    struct Node* Q = L->Next;
    while(Q != NULL) {
        result += Q->Element;
        count++;
        Q = Q->Next;
    }
    return result / count;
}

struct Node* locate(int x, List L) {
    struct Node* Q = L;
    while(Q->Next != NULL) {
        if(Q->Next->Element == x) {
            return Q;
        }
        Q = Q->Next;
    }
    return Q;
}

void delete(struct Node* Q, List* L) { // Xoa Q->Next va nhay Q
    if (Q->Next != NULL) {
        struct Node* T;
        T = Q->Next;
        Q->Next = T->Next;
        free(T);
    }
    else return;
}

void deleteList(int x, List* L) {// Xoa di toan x trong List
    struct Node* Q = *L;
    while(Q->Next != NULL) { 
        if (Q->Next->Element == x) {
            delete(Q, L); //Luu y sao khi xoa xong Q se nhay len nen khi da thuc hiem ham detele thi khong can Q = Q->Next tranh nhay phan tu
        }
        else {
            Q = Q->Next;
        }
        
    }
}

void delete_strucNode(struct Node* Q, List* L) {// Xoa di Q
    struct Node* P = *L;
    while(P->Next != Q) {
        P = P->Next;
    }
    P->Next = Q->Next;
}

int append(int X, List* L) { // Viet ham de chen x vao ds L neu x da co trong ds L tra ve 0 khong co them x cuoi ds L tra ve 1 
    struct Node* Q = locate(X, *L); // locate tra ve vị trí Q->Next = x khong thi tra ve Q->Next == NULL;
    struct Node* P = (struct Node*)malloc(sizeof(struct Node));
    P->Element = X;
    P->Next = NULL;
    if(Q->Next != NULL) {
        free(P);
        return 0;
    }
    else {
        Q->Next = P; //Do khong co nen Q = NULL va cuoi cua ds L rui nen noi vo la dep
        return 1;
    }
}

List read() {
    int n;
    int i;
    scanf("%d", &n);
    List L;
    makenullList(&L);
    struct Node* Q = L;
    for (i = 0; i < n; i++){
        int temp;
        scanf("%d", &temp);
        if (locate(temp, L)->Next == NULL) { //Luu y ham locate phai tra ve struct Node P->Next nhe 
            insertList(temp, L, &L);
        } 
    }
    return L;
}

//Hinh thanh y tuong dung Thuat toan sap xep noi
// Dung 2 vong for 
// i = L
// j = i; tranh truong hop j = (*L)->Next->Next vi j k doi
// Rui ss lay i dau tien so sanh (kha tu o day)
void Interchangeshort(List* L) { //C1
    struct Node* i;
    struct Node* j;
    for (i = (*L)->Next; i != NULL; i = i->Next) {
        for(j = i->Next; j != NULL; j = j->Next) {
            if(i->Element > j->Element) {
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
void InsertionSort(List L) { // C2
    struct Node* sorted = NULL; // Danh sách mới đã sắp xếp
    struct Node* current = L->Next; // Con trỏ duyệt danh sách cũ.
    
    while (current != NULL) {
        struct Node* next = current->Next; // Luu gia tri tiep theo cua toa de truong minh thao lap k mat may toa sao
        
        // Tìm vị trí chèn current vào danh sách sorted
        if (sorted == NULL || sorted->Element >= current->Element) {
            current->Next = sorted; 
            sorted = current; 
        } else {
            struct Node* p = sorted;
            while (p->Next != NULL && p->Next->Element < current->Element) {
                p = p->Next;
            }
            current->Next = p->Next;
            p->Next = current;
        }
        current = next; // Tiến tới toa tiếp theo của danh sách cũ. current = 2. current = 9.
    }
    L->Next = sorted; // Cập nhật lại đầu tàu chính
}

//C3 chưa hiểu 8/7 coi
void splitList(struct Node* source, struct Node** frontRef, struct Node** backRef) {
    struct Node* fast;
    struct Node* slow;
    slow = source;
    fast = source->Next;

    // Thỏ đi nhanh gấp đôi Rùa
    while (fast != NULL) {
        fast = fast->Next;
        if (fast != NULL) {
            slow = slow->Next;
            fast = fast->Next;
        }
    }

    // Rùa chính là điểm giữa, chặt đôi tàu ra!
    *frontRef = source;
    *backRef = slow->Next;
    slow->Next = NULL; // Tháo xích để tách làm 2 danh sách độc lập
}

struct Node* sortedMerge(struct Node* a, struct Node* b) {
    struct Node* result = NULL;

    // Trường hợp cơ bản: 1 trong 2 danh sách bị rỗng
    if (a == NULL) return b;
    if (b == NULL) return a;

    // So sánh Element để chọn toa nhỏ hơn cho vào kết quả
    if (a->Element <= b->Element) {
        result = a;
        result->Next = sortedMerge(a->Next, b); // Đệ quy trộn phần còn lại
    } else {
        result = b;
        result->Next = sortedMerge(a, b->Next); // Đệ quy trộn phần còn lại
    }
    return result;
}

void mergeSortRecursive(struct Node** headRef) {
    struct Node* head = *headRef;
    struct Node* a;
    struct Node* b;

    // Nếu tàu chỉ có 0 hoặc 1 toa thì không cần xếp nữa
    if ((head == NULL) || (head->Next == NULL)) {
        return;
    }

    // 1. Chia tàu thành 2 nửa 'a' và 'b'
    splitList(head, &a, &b);

    // 2. Đệ quy sắp xếp cho từng nửa
    mergeSortRecursive(&a);
    mergeSortRecursive(&b);

    // 3. Trộn 2 nửa đã xếp xong lại với nhau
    *headRef = sortedMerge(a, b);
}


List Intersection(List L_1, List L_2) {
    List Giao;
    makenullList(&Giao);
    if (L_1->Next == NULL || L_2->Next == NULL) {
        return Giao;
    }
    struct Node* L = Giao;
    struct Node* Q = L_1;
    while (Q->Next != NULL) {
        if(locate(Q->Next->Element, L_2)->Next != NULL) {
            insertList(Q->Next->Element, L, &Giao);
            L = L->Next;
        }
        Q = Q->Next;
    }
    return Giao;
}

List Union(List L_1, List L_2) {
    if (L_1->Next == NULL) {
        return L_2;
    }
    if (L_2->Next == NULL) {
        return L_1;
    }
    struct Node* Q = L_2;
    while (Q->Next != NULL) {
        if(locate(Q->Next->Element, L_1)->Next == NULL) {
            insertList(Q->Next->Element,locate(Q->Next->Element, L_1) , &L_1);
        }
        Q = Q->Next;
    }
    return L_1;
}

List Difference(List L_1, List L_2) {
    if(L_1->Next == NULL || L_2->Next == NULL) {
        return L_1;
    }
    struct Node* Q = L_1;
    while (Q->Next != NULL) {
        if(locate(Q->Next->Element, L_2)->Next != NULL) {
            deleteList(Q->Next->Element, &L_1);
        }
    }
    return L_1;
}

int main() {
    return 0;
}