#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

void fn(int i,int j,int uval[],int arr[])
{
    arr[j] = max(arr[j],(uval[i]+arr[j-uval[i]]));
}

int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;

        int uval[n];
        int arr[k+1];
        for(int i = 0 ; i<k+1 ; i++)
            arr[i] = 0;

        for(int i = 0 ; i<n ; i++)
            cin>>uval[i];

        sort(uval,uval+n);

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 1 ; j<k+1 ; j++)
            {
                if(j>uval[i]-1)
                    fn(i,j,uval,arr);   //arr[j] = max(arr[j],(uval[i]+arr[j-uval[i]]));
            }
        }

        cout<<arr[k]<<endl;
    }
    return 0;
}


/*

input::

2
3 12
1 6 9
5 9
3 4 4 4 8

output::

12
9

*/