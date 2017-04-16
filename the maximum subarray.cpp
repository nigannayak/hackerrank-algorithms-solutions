#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main()
{
    long t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long arr[n];
        for(long i = 0 ; i<n ; i++)
            cin>>arr[i];

        long ncsarr(0),csarr(0),tsum(0);
        long ind(0);

        for(long i = 0 ; i<n ; i++)
        {
            if(arr[i]>0)
            {
                ncsarr += arr[i];
                ind = 1;
            }

            csarr += arr[i];
            if(csarr<0)
                csarr = 0;

            else
                tsum = max(tsum,csarr);
        }

        if(ind==0)
        {
            long *ans = max_element(arr,arr+n);
            cout<<*ans<<" "<<*ans<<endl;
        }

        else
            cout<<tsum<<" "<<ncsarr<<endl;
    }
    return 0;
}

/*

input ::

2
4
1 2 3 4
6
2 -1 2 3 4 -5

output ::

10 10
10 11

*/