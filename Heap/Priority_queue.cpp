#include "Priority_queue.h"
#include <iostream>

using namespace std;

PriorityQueue Initialize(int MaxElements, PriorityQueue H){
    H->Capacity = MaxElements;
    H->Elements = new ElementType[MaxElements]();
    H->size = 0;
    return H;
}

void Insert(ElementType X, PriorityQueue H){
    int i;
    if(IsFull(H)){
        cout << "Full!" << endl;
        return;
    }

    for(i = ++H->size; H->Elements[i/2] > X; i/=2)
        H->Elements[i] = H->Elements[i/2];
    H->Elements[i] = X;
}

int IsEmpty(PriorityQueue H){
    return H->size == 0;
}

int IsFull(PriorityQueue H){
    return H->size == H->Capacity;
}

ElementType DeleteMin(PriorityQueue H){
    int i, Child;
    ElementType MinElement, LastElement;

    if(IsEmpty(H)){
        cout << "Empty!" << endl;
        return H->Elements[0];
    }

    MinElement = H->Elements[1];
    LastElement = H->Elements[H->size--];

    for(i = 1; i * 2 <= H->size; i = Child){
        Child = i * 2;
        if(Child != H->size && H->Elements[Child + 1] < H->Elements[Child])
            Child++;
        if(LastElement > H->Elements[Child])
            H->Elements[i] = H->Elements[Child];
        else
            break;
    }
    H->Elements[i] = LastElement;
    return MinElement;
}
