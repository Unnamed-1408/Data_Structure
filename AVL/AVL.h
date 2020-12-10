#ifndef AVL_H
#define AVL_H

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;
typedef int ElementType ;

struct AvlNode{
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
int getHeight(AvlTree T);
void InOrder(AvlTree T);
#endif // AVL_H
