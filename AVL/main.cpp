#include <iostream>
#include "AVL.h"
using namespace std;

int main()
{
   AvlTree b = nullptr;
   int test[] = {15, 21, 35, 67, 1, 2, 5, 7};
   for(int i = 0; i < 8; i++){
       b = Insert(test[i], b);
   }
   Delete(3, b);
   cout << b->Element << endl;
   Delete(21, b);
   cout << b->Element << endl;
}
