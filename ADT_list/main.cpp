#include <iostream>

struct Node;
struct Linked_list;
void Insert(Node* to_insert , Linked_list L , int count);
void initialization_list(Linked_list a);
int Find(int target , Linked_list L);
bool Delete(int target , Linked_list L);
bool is_empty(Linked_list L);
void Add(Node *a , Linked_list L);

using namespace std;

struct Node{
    int Num = 0;
    Node* Next = nullptr;
};

struct Linked_list{
    Node nothing;
    Node* head = &nothing;
};


int main()
{
    Linked_list list ;
    Node a;
    a.Num = 2;
    Node b;
    b.Num = 5;
    a.Next = &b;
    Add(&a,list);

    Add(&b,list);
    Node c;
    c.Num = 3;
    Insert(&c , list ,1);
    cout << Find(5,list) <<endl;
    Delete(3,list);
    cout << Find(5,list) <<endl;
}



void Insert(Node* to_insert , Linked_list L , int count){
    int temp = 0;
    Node* temp_node = (L.head);

    while(temp != count){
        temp_node = ((*temp_node).Next);
        temp++;
    }

    Node* temp_Next = ((*temp_node).Next);
    (*temp_node).Next = to_insert;
    (*to_insert).Next = temp_Next;
}


int Find(int target , Linked_list L){

    Node *temp_node = (L.head);
    int out = 1;
    while((*temp_node).Next != nullptr && (*temp_node).Next->Num != target){
        temp_node = ((*temp_node).Next);

        out++;
    }
    if((*temp_node).Next == nullptr){
        return -1;
    }
    else {
        return out;
    }

}

bool Delete(int target , Linked_list L){
    Node* temp_node = (L.head);

    while((*temp_node).Next != nullptr && (*temp_node).Next->Num != target){
        temp_node = ((*temp_node).Next);
    }

    if((*temp_node).Next == nullptr){
        return false;
    }
    else{
        Node* next = ((*temp_node).Next->Next);
        Node* to_free = ((*temp_node).Next);
//        free(to_free);
        (*temp_node).Next = next;
        return true;
    }

}

bool is_empty(Linked_list L){
    return L.head->Next == nullptr;
}

void Add(Node* temp , Linked_list L){
    Node *temp_node = (L.head);

    while((*temp_node).Next != nullptr){
        temp_node = ((*temp_node).Next);
    }

    (*temp_node).Next = temp;
}










