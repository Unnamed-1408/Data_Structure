#include <iostream>
#include "AVL.h"
using namespace std ;

int getHeight(AvlTree T){
    if(T == nullptr){
        return -1;
    }
    else{
        return T->Height;
    }
}

AvlTree RR_Rotation(AvlTree k2){
    AvlTree k1 = k2->Left;
    k2->Left = k1->Right;
    k1->Right = k2;
    k2->Height = max(getHeight(k2->Left), getHeight(k2->Right)) + 1;
    k1->Height = max(getHeight(k1->Left), k2->Height) + 1;
    return k1;
}

AvlTree LL_Rotation(AvlTree k2){
    AvlTree k1 = k2->Right;
    k2->Right = k1->Left;
    k1->Left = k2;
    k2->Height = max(getHeight(k2->Left), getHeight(k2->Right)) + 1;
    k1->Height = max(getHeight(k1->Right), k2->Height) + 1;
    return k1;
}

AvlTree LR_Rotation(AvlTree k3){
    k3->Left = LL_Rotation(k3->Left);
    return RR_Rotation(k3);
}

AvlTree RL_Rotation(AvlTree k3){
    k3->Right = RR_Rotation(k3->Right);
    return LL_Rotation(k3);
}

AvlTree Insert(ElementType X, AvlTree T){
    if(T == nullptr){
        T = new AvlNode;
        T->Element = X;
        T->Height = 0;
        T->Right = T->Left = nullptr;
    }
    else{
        if(X > T->Element){
            T->Right = Insert(X, T->Right);
            if(getHeight(T->Right) - getHeight(T->Left) == 2){
                if(X > T->Right->Element){
                    T = LL_Rotation(T);
                }
                else{
                    T = RL_Rotation(T);
                }
            }
        }
        else{
            T->Left = Insert(X, T->Left);
            if(getHeight(T->Left) - getHeight(T->Right) == 2){
                if(X < T->Left->Element){
                    T = RR_Rotation(T);
                }
                else{
                    T = LR_Rotation(T);
                }
            }
        }
    }
    T->Height = max(getHeight(T->Left), getHeight(T->Right)) + 1;
    return T;
}

Position Find(ElementType X, AvlTree T){
    if(T == nullptr){
        return nullptr;
    }
    if(T->Element == X){
        return T;
    }
    if(T->Element > X){
        return Find(X, T->Left);
    }
    else{
        return Find(X, T->Right);
    }
}

AvlTree Delete(ElementType X, AvlTree T){
    if(T == nullptr){
        cout << "Not found!" << endl;
        return T;
    }
    if(T->Element == X){
        if(T->Right == nullptr){
            Position tmp = T;
            T = T->Left;
            delete tmp;
            return T;
        }
        else{
            Position tmp = T->Right;
            while(tmp->Left != nullptr){
                tmp = tmp->Left;
            }
            T->Element = tmp->Element;
            T->Right = Delete(tmp->Element, T->Right);
        }
    }
    else if(T->Element > X){
        T->Left = Delete(X, T->Left);
    }
    else if(T->Element < X){
        T->Right =  Delete(X, T->Right);
    }

    T->Height = max(getHeight(T->Right), getHeight(T->Left)) + 1;
    if(getHeight(T->Right) - getHeight(T->Left) == 2){
        if(getHeight(T->Right->Right) >= getHeight(T->Right->Left)){
            T = LL_Rotation(T);
        }
        else{
            T = RL_Rotation(T);
        }
    }
    else if(getHeight(T->Left) - getHeight(T->Right) == 2){
        if(getHeight(T->Left->Left) >= getHeight(T->Left->Right)){
            T = RR_Rotation(T);
        }
        else{
            T = LR_Rotation(T);
        }
    }
    return T;
}


void InOrder(AvlTree root)
{
    if(root)
    {
        InOrder(root->Left);
        printf("key: %d height: %d ", root->Element, root->Height);
        if(root->Left)
            printf("left child: %d ", root->Left->Element);
        if(root->Right)
            printf("right child: %d ", root->Right->Element);
        printf("\n");
        InOrder(root->Right);
    }
}
