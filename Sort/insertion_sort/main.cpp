#include <iostream>

using namespace std;
void insertion_sort(int list[] , int num);
void output(int list[] , int num);

int main()
{
    int list[6] = {34,8,64,51,32,21};

    insertion_sort(list , 6);
}

void insertion_sort(int list[] , int num){
    int temp = 0;
    int count = 0;
    int tempnum = 0;
    while(count != num){

        temp = count;

        while(temp != -1){

            if(list[temp] < list[temp-1]){
                tempnum = list[temp];
                list[temp] = list[temp-1];
                list[temp-1] = tempnum;
            }
            else{
               break;
            }
            temp--;
        }
        count++;
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
