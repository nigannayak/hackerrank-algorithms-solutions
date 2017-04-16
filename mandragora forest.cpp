#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
    unsigned long long int t;
    cin>>t;
    while(t--)
    {
        unsigned long long int n;
        cin>>n;
        unsigned long long int arr[n];
        unsigned long long int sum(0);
        for(unsigned long long int i = 0 ; i < n ; i++)
        {
            cin>>arr[i];
            sum += arr[i];
        }

        unsigned long long int s(1);
        unsigned long long int p = s*sum;

        sort(arr,arr+n);
        for(unsigned long long int i = 0 ; i < n-1 ; i++)
        {
            unsigned long long int ans = 0;
            s++;
            sum -= arr[i];
            ans = s*sum;
            p = max(ans,p);
        }

        cout<<p<<endl;
    }
    return 0;
}