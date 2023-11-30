#include<iostream>

using namespace std;
#define arrsize 10
template<class T>

T nth_max(T arr[],int n)
{
    T funarr[arrsize];
    for(int i = 0; i< arrsize;i++)
    {
        funarr[i] = arr[i];
    }
    for(int i = 0; i< arrsize-1;i++)
    {
        for(int j= 0; j  < arrsize-1; j++)
        {
            if(funarr[j] < funarr[j+1])
            {
                T temp = funarr[j];
                funarr[j]  = funarr[j+1];
                funarr[j+1] = temp;
            }
        }
    }
    n--;
    return funarr[n];
}


int main()
{
    int arr[arrsize];
    for(int i = 0; i< arrsize; i++)
    {
        arr[i] = i+1;
    }
    int n = 1;
    cout << n << " th largest element is " << nth_max(arr,n) << endl;
    n++;
    cout << n << " th largest element is " << nth_max(arr,n) << endl;
    n++;
    cout << n << " th largest element is " << nth_max(arr,n) << endl;

    char arr2[arrsize];
    for(int i = 0; i< arrsize; i++)
    {
        arr2[i] = i +1+ 'a';
    }
    n = 1;
    cout << n << " th largest element is " << nth_max(arr2,n) << endl;
    n++;
    cout << n << " th largest element is " << nth_max(arr2,n) << endl;
    n++;
    cout << n << " th largest element is " << nth_max(arr2,n) << endl;

    return 0;
}