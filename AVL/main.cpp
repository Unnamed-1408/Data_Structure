#include <iostream>
#include "AVL.h"
using namespace std;

int main()
{
   AvlTree b = nullptr;
   int test[] = {15, 21, 35, 67, 1, 2, 5, 7};
   for(int i = 0; i < 8; i++){
       b = Insert(test[i], b);
       InOrder(b);
       cout << endl;
       if(i >= 3){
           b = Delete(test[i-3], b);
           cout << "kill" << endl;
           InOrder(b);
       }
       cout << endl;
   }
   Delete(3, b);
   cout << b->Element << endl;
   Delete(5, b);
   cout << b->Element << endl;
}
