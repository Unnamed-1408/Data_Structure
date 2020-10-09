#include <iostream>

using namespace std;
void Qsort(int list[],int num);

void Quick_Sort(int list[] , int left ,int right);
void Swap(int *first , int *second);
int middle(int list[] , int left , int right);
void output(int list[] , int num);

int main()
{
    int list[9] = {0,0,0,0,0,0,0,1,0};

    Qsort(list , 9);
    output(list , 9);
}

void Qsort(int list[],int num){

    Quick_Sort(list , 0 , num-1);

}

void Quick_Sort(int list[] , int left ,int right){

    if(right - left >=2){

    int piviot = middle(list , left , right);

    int Aptr = left;
    int Bptr = right-1;

    while(Aptr <= Bptr){

        while(list[Aptr] <= piviot){
           Aptr ++;
           if(Aptr > (left+right+1)/2){
               break;
           }
        }
        while(list[Bptr] >= piviot){
            Bptr--;
            if(Bptr < (left+right)/2){
                break;
            }
        }
        if(Aptr <= Bptr){
            Swap(&list[Aptr] , &list[Bptr]);
        }
        else{
            break;
        }
    }

    Swap(&list[Aptr] , &list[right]);
    Quick_Sort(list , left , Aptr - 1);
    Quick_Sort(list , Aptr + 1 , right);

    }

}

void Swap(int *first , int *second){
    int temp = 0;
    temp = *first;
    *first = *second;
    *second = temp;
}

int middle(int list[] , int left , int right){

    int Center = (left + right)/2;

    if(list[left] > list[Center])
        Swap(&list[left] , &list[left]);

    if(list[left] > list[right])
        Swap(&list[left] , &list[right]);
    if(list[Center] > list[right])
        Swap(&list[Center] , &list[right]);

    Swap(&list[Center] , &list[right]);

    return list[right];
}

void output(int list[] , int num){
    int temp = 0;
    while(temp != num){

        cout<<list[temp]<<" ";

        temp++;

    }
    cout<<endl;
}

