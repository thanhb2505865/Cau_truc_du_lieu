#include<stdio.h>
#include<stdlib.h>


typedef int DataType; 

struct Node {
    DataType Data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node* Tree;


void MAKENULL_TREE(Tree* T) {
    *T = NULL;
}

int EMPTY_TREE(Tree T) {
    return T == NULL; // Rong tra ve 1; Khong rong tra ve 0;
}

Tree RIGHTCHILD(Tree n) {
    if (EMPTY_TREE(n)){ //Rong => 1 != 0 tra ve NULL;
        return NULL;
    }
    else {
        return n->right;
    }
}

Tree LEFTCHILDTREE(Tree n) {
    if (EMPTY_TREE(n)){ //Rong => 1 != 0 tra ve NULL;
        return NULL;
    }
    else {
        return n->left; 
    }
}

int ISLEAF(Tree n) {//Nếu là lá thì trả về 1 không trả về 0;
    if (n != NULL) return (n->left == NULL) && (n->right == NULL); // return LEFTCHILD(n) == NULL && RIGHTCHILD(n) == NULL;
    else return 0;
}

int NB_NODES(Tree T) {
    if(EMPTY_TREE(T)) return 0; // Tai Leaf se tra ve 0
    else return 1 + NB_NODES(LEFTCHILDTREE(T)) + NB_NODES(RIGHTCHILD(T));
}

Tree Creat2(DataType x, Tree l, Tree r) {
    Tree T = (Tree)malloc(sizeof(struct Node));
    T->Data = x;
    T->left = l;
    T->right = r;
    return T;
}

void PreOrder(Tree T) {
    if(EMPTY_TREE(T)) return;
    else {
        printf("%d ", T->Data);
        PreOrder(LEFTCHILDTREE(T));
        PreOrder(RIGHTCHILD(T));
    }
}

void InOrder(Tree T) {
    if(T == NULL) return;
    else {
        InOrder(LEFTCHILDTREE(T));
        printf("%d ", T->Data);
        InOrder(RIGHTCHILD(T));
    }
}

void PosOrder(Tree T) {
    if (T != NULL) {
        PosOrder(LEFTCHILDTREE(T));
        PosOrder(RIGHTCHILD(T));
        printf("%d ", T->Data);
    }
}

Tree Search(DataType x, Tree Root) { //Khong thay tra ve NULL; Tra ve Tree // Minh chua hieu ham search
    if (Root == NULL) return NULL; // Truong hop tim khong thay x
    else {
        if(Root->Data == x) {
            return Root;
        }
        else {
            if(x > Root->Data) {
                return Search(x, RIGHTCHILD(Root));
            }
            else {
                return Search(x, LEFTCHILDTREE(Root));
            }
        }
    }
}

//Ý tưởng đọc theo giao trình dài vl
void Insertnode(DataType x, Tree* Root) { //Tree* = struct Node**
    if(*Root == NULL) {
        Tree New = (Tree)malloc(sizeof(struct Node));
        New->Data = x;
        New->left = NULL;
        New->right = NULL;
        *Root = New;
    }
    else {
        if((*Root)->Data == x) {
            return;
        }
        else {
            if((*Root)->Data < x) {
                InsertNode(x, &(*Root)->right);
            }
            else{
                InsertNode(x, &(*Root)->left);
            }
        }
    }
}


// Theo giao trinh
void insertnode(DataType x, Tree* Root) {
    if(*Root = NULL) {
        *Root = (Tree)malloc(sizeof(struct Node));
        (*Root)->Data = x;
        (*Root)->left = NULL;
        (*Root)->right = NULL;
    }
    else {
        if(x < (*Root)->Data) InsertNode(x, &(*Root)->left);
        else if(x > (*Root)->Data) InsertNode(x, &(*Root)->right);
    }
}

Tree InsertNode(DataType x, Tree Root) {
    if(Root == NULL) {
        Root = (Tree)malloc(sizeof(struct Node));
        Root->Data = x;
        Root->left = NULL;
        Root->right = NULL;
    }
    else {
        if(Root->Data > x) {
            Root->left = InsertNode(x, Root->left);
        }
        else if(Root->Data < x) {
            Root->right = InsertNode(x, Root->right);
        }
    }
    return Root;
}

DataType DeleteMin(Tree* Root) { //Ham tra ve Data nho nhat cua Cay va xoa no
    DataType temp;
    if((*Root)->left == NULL) {
        temp = (*Root)->Data;
        Tree F = *Root;
        *Root = (*Root)->right;
        free(F);
        return temp;
    }
    else return DeleteMin(&(*Root)->left);
}

/*
Tree Search(DataType x, Tree Root) { //Khong thay tra ve NULL; Tra ve Tree 
    if (Root == NULL) return NULL; // Truong hop tim khong thay x
    else {
        if(Root->Data == x) {
            return Root;
        }
        else {
            if(x > Root->Data) {
                return Search(x, RIGHTCHILD(Root));
            }
            else {
                return Search(x, LEFTCHILDTREE(Root));
            }
        }
    }
}
*/
//Y tuong 

void DeleteNode(DataType x, Tree* Root) {
    if (*Root == NULL) return; // Cây rỗng hoặc không tìm thấy x

    // 1. Đi tìm nút chứa x trước
    if (x < (*Root)->Data) {
        DeleteNode(x, &(*Root)->left);
    } 
    else if (x > (*Root)->Data) {
        DeleteNode(x, &(*Root)->right);
    } 
    else {//Truong hop nay la luc Root->Data = x;
        // 2. Đã tìm thấy nút cần xóa (*Root)
        Tree F = *Root; //F->Data == x;
        
        // Trường hợp 1 & 2: Khuyết con trái HOẶC khuyết con phải (bao gồm cả nút lá)
        if ((*Root)->left == NULL) {
            *Root = (*Root)->right; // Nối thẳng con phải lên (cha của *Root sẽ nhận liên kết này)
            free(F);
        } 
        else if ((*Root)->right == NULL) {
            *Root = (*Root)->left;  // Nối thẳng con trái lên
            free(F);
        } 
        // Trường hợp 3: Có đầy đủ cả 2 con
        else {
            // Dùng hàm DeleteMin thần thánh của ní để lấy giá trị thế mạng và xóa nút thế mạng đó đi
            (*Root)->Data = DeleteMin(&(*Root)->right); 
        }
    }
}

int main() {

    return 0;
}
/*
    Tree T1 = Creat2(15, NULL, NULL);
    Tree T2 = Creat2(17, T1, NULL);
    Tree T3 = Creat2(5, NULL, NULL);
    Tree T4 = Creat2(10, T3, T2);
    Tree T5 = Creat2(37, NULL, NULL);
    Tree T6 = Creat2(42, T5, NULL);
    Tree T7 = Creat2(22, NULL, NULL);
    Tree T8 = Creat2(35, T7, T6);
    Tree T9 = Creat2(20, T4, T8);
    PosOrder(T9);
*/