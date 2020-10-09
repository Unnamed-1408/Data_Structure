#include <iostream>

using namespace std;
void Merge(long long lista[] , long long listb[] , long long left ,long long Center ,long long right);
void Mergesort(long long list[]  ,long long temp[], long long left ,long long right);
long long* Start(long long list[],long long num);
void output(long long list[] , long long num);

int main()
{
    long long list[16] = {1,9,2,10,3,11,4,12,5,13,6,14,7,15,8,16};

    output(Start(list , 16),16);
}

long long* Start(long long list[],long long num){
    long long temp[num];
    Mergesort(list,temp,0,num-1);
    return list;
}

void Mergesort(long long list[] , long long temp[],long long left ,long long right){

     long long Center = (left+right)/2;

     if(left < right){

        Mergesort(list ,temp, left ,Center);
        Mergesort(list ,temp, Center+1 ,right);
        Merge(list , temp ,left ,Center ,right);

     }

}

void Merge(long long list[] , long long temp[] , long long left ,long long Center ,long long right){
    long long Aptr = left;
    long long Bptr = Center+1;
    long long Cptr = left;
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
        long long tempnum = left;
        while(tempnum != right+1){
            list[tempnum] = temp[tempnum];
//            cout<<list[tempnum]<<endl;
            tempnum++;
        }
}


void output(long long list[] , long long num){
    long long temp = 0;
    while(temp != num){

        cout<<list[temp]<<" ";

        temp++;

    }
    cout<<endl;
}
