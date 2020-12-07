#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;
typedef int ElementType;

struct HeapStruct{
    int Capacity;
    int size;
    ElementType *Elements;
};

PriorityQueue Initialize(int MaxElements, PriorityQueue H);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);
#endif // PRIORITY_QUEUE_H
