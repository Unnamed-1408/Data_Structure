#include <iostream>

using namespace std;
void Merge(int A[] , int temp[],int Lpos, int Rpos ,int RightEnd);
void MergeSort(int A[],int N);
void MSort(int A[], int temp[] , int Left ,int Right);
void output(int list[] , int num);

int main()
{
    int list[8] = {1,13,24,26,2,15,27,38};

    MergeSort(list,8);
    output(list,8);
}
void MSort(int A[], int temp[] , int Left ,int Right){
    int Center;

    if(Left<Right){
        Center = (Left + Right)/2;
        MSort(A ,temp ,Left ,Center);
        MSort(A ,temp,Center+1,Right);
        Merge(A,temp,Left,Center+1,Right);
    }

}

void MergeSort(int A[],int N){
    int *temp;
    temp = (int *)malloc(N * sizeof(int));
    if(temp != nullptr){
        MSort(A,temp,0,N-1);
        free(temp);

    }
    else{
       cout<<"No space!";
    }
}


void Merge(int A[] , int temp[],int Lpos, int Rpos ,int RightEnd){
    int i,LeftENd,NumElements,TmpPos;
    LeftENd = Rpos -1;
    TmpPos = Lpos;
    NumElements = RightEnd - Lpos+1;
    while(Lpos<=LeftENd && Rpos <=RightEnd){
        if(A[Lpos]<= A[Rpos]){
            temp[TmpPos++] = A[Lpos++];
        }
        else{
            temp[TmpPos++] = A[Rpos++];
        }
        while(Lpos<=LeftENd)
            temp[TmpPos++] = A[Lpos++];
        while(Rpos <= RightEnd)
            temp[TmpPos++] = A[Rpos++];

        for(i = 0; i< NumElements;i++, RightEnd--){

            A[RightEnd] = temp[RightEnd];
        }

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


