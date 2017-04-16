#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main()
{
    long sum,n;
    cin>>sum>>n;
    long arr[100000],a[n];
    for(long i = 0 ; i<n ; i++)
        cin>>a[i];

    sort(a,a+n);
    arr[0] = 1;
    for(long i = 1 ; i<sum+1 ; i++)
        arr[i] = 0;

    for(long i = 0 ; i<n ; i++)
    {
        for(long j = a[i] ; j<sum+1 ; j++)
        {
            if(a[i]<j+1)
                arr[j] += arr[j-a[i]];
        }
    }

    cout<<arr[sum];
    return 0;
}

/*

input ::

10 4
2 5 3 6

output ::

5

*/