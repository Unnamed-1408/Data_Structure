#include <iostream>

using namespace std;
void Merge(int lista[] , int listb[] , int left ,int Center ,int right);
void Mergesort(int list[]  ,int temp[], int left ,int right);
int* Start(int list[],int num);
void output(int list[] , int num);

int main()
{
    int list[16] = {1,9,2,10,3,11,4,12,5,13,6,14,7,15,8,16};

    output(Start(list , 16),16);
}

int* Start(int list[],int num){
    int temp[num];
    Mergesort(list,temp,0,num-1);
    return list;
}

void Mergesort(int list[] , int temp[],int left ,int right){

     int Center = (left+right)/2;

     if(left < right){

        Mergesort(list ,temp, left ,Center);
        Mergesort(list ,temp, Center+1 ,right);
        Merge(list , temp ,left ,Center ,right);

     }

}

void Merge(int list[] , int temp[] , int left ,int Center ,int right){
    int Aptr = left;
    int Bptr = Center+1;
    int Cptr = left;
    while(Cptr != right+1){
        if(Aptr != Center+1 && Bptr != right +1){
            if(list[Aptr] < list[Bptr]){
                temp[Cptr] = list[Aptr];
                Cptr ++;
                Aptr ++;
            }
            else{
                temp[Cptr] = list[Bptr];
                Cptr ++;
                Bptr ++;
            }
       }

        else if(Aptr == Center +1){
            temp[Cptr] = list[Bptr];
            Cptr ++;
            Bptr ++;
        }
        else if(Bptr == right+1){
            temp[Cptr] = list[Aptr];
            Cptr ++;
            Aptr ++;
        }
    }
        int tempnum = left;
        while(tempnum != right+1){
            list[tempnum] = temp[tempnum];
//            cout<<list[tempnum]<<endl;
            tempnum++;
        }
}


void output(int list[] , int num){
    int temp = 0;
    while(temp != num){

        cout<<list[temp]<<" ";

        temp++;

    }
    cout<<endl;
}
