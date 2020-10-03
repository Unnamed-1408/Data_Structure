#include <iostream>

using namespace std;
int* Merge(int lista[] , int listb[] , int left ,int Center ,int right);
int* Mergesort(int list[]  , int left ,int right);
int* Start(int list[],int num);
void output(int list[] , int num);

int main()
{
    int list[8] = {1,13,24,26,2,15,27,38};

    output(Start(list , 8),8);
}

int* Start(int list[],int num){

    return Mergesort(list , 0 ,num-1);
}

int* Mergesort(int list[] , int left ,int right){

     int Center = (left+right)/2;

     if(left < right){

        int* tempa=Mergesort(list , left ,Center);
        int* tempb=Mergesort(&list[Center+1] , Center+1 ,right);
        return Merge(tempa , tempb ,left ,Center ,right);
     }
     return list;
}

int* Merge(int lista[] , int listb[] , int left ,int Center ,int right){

    const int lengtha = Center - left+1;
    const int lengthb = right -Center;
    int Aptr = 0;
    int Bptr = 0;
    int Cptr = 0;
    int C[right-left+1];

    while(Cptr != right-left+1){

        if(Aptr != lengtha || Bptr != lengthb){

            if(lista[Aptr] < listb[Bptr]){
                C[Cptr] = lista[Aptr];
                 Aptr++;
                 Cptr++;
            }
            else{
                C[Cptr] = listb[Bptr];
                 Bptr++;
                Cptr++;
            }
        }//when no list over

        if(Aptr == lengtha){
            C[Cptr] = listb[Bptr];
            Bptr++;
            Cptr++;
        }//Alist over

       if(Bptr == lengthb){
          C[Cptr] = lista[Aptr];
          Aptr++;
          Cptr++;
      }//Blist over

    }
    return C;
}


void output(int list[] , int num){
    int temp = 0;
    while(temp != num){

        cout<<list[temp]<<" ";

        temp++;

    }
    cout<<endl;
}


















