#include <iostream>

using namespace std;
void output(int list[] , int num);
void Shell_sort(int list[] , int num);

int main()
{
    int list[7] = {34,8,64,51,32,21,1};

    Shell_sort(list , 7);

}
void Shell_sort(int list[] , int num){
   int hk = num;
   int move = 0;
   int temp = 0;

   while(hk != 1){
       hk /= 2;
       move = 0;
       temp = 0;
       while(move != num){
            int tempnum = 0;
            temp = move;
           while(temp - hk >= 0){
                if(list[temp] < list[temp-hk]){
                        tempnum = list[temp];
                        list[temp] = list[temp-hk];
                        list[temp-hk] = tempnum;
                }
              temp = temp - hk;
           }
           move++;
       }

   }
    output(list , num);
}

void output(int list[] , int num){
    int temp = 0;
    while(temp != num){

        cout<<list[temp]<<" ";

        temp++;

    }
    cout<<endl;
}
