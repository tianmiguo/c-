#include<iostream>
using namespace std;

void headadjust(int arr[],int m,int n ){
    int i,j,temp;
    temp=arr[m];
    for(i=2*m+1;i<=n;i=i*2)
    {
        if(i+1<=n && arr[i]>arr[i+1])
            i++;
        if(arr[i]>temp)
           break;
        arr[m]=arr[i];
        m=i;
    }
    arr[m]=temp;
}
void setup(int arr[],int n )
{
    int i,t;
    for(i=n/2;i>=0;i--)
    {
        headadjust(arr,i,n);
    }
    for(i=n;i>0;i--)
    {
        t=arr[0];
        arr[0]=arr[i-1];
        arr[i-1]=t;
        headadjust(arr,0,i-2);
    }
}
int main()
{
    int i;
    int arr[6]={1,7,3,4,5,6};
    setup(arr,6);
    for(i=0;i<6;i++)
    cout<<arr[i];
    return 0;
}
