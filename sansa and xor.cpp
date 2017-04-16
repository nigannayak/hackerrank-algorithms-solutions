#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
using namespace std;

int rec(int n,int arr[])
{
    if(n%2==0)
        return 0;
    
    else
    {
        int val(0);
        for(int i = 0 ; i < n ; i+=2)
            val ^= arr[i];
            
        return val;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n],ind(1),val(0),ans;
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i];

        ans = rec(n,arr);
        cout<<ans<<endl;
    }
    return 0;
}

/*

input::

2
3
1 2 3
4
4 5 7 5

output::

2
0

*/