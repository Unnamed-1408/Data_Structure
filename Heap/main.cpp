#include <iostream>
#include "Priority_queue.h"

using namespace std;

int main()
{
    HeapStruct *H;
    H = Initialize(10, H);
    int list[] = {5, 6, 3, 8, 10, 2, 7};
    for(int i = 0; i < 7; i++){
        Insert(list[i], H);
    }
    for(int i = 0; i < 7; i++)
        cout << DeleteMin(H) << " ";
}
