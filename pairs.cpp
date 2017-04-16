#include<bits/stdc++.h>
using namespace std;

int main()
{
    long n,k;
    cin>>n>>k;
    long arr[n];

    for(long i = 0 ; i<n ; i++)
        cin>>arr[i];

    sort(arr,arr+n);
    long i(0);
    long j(i+1);
    long total(0);

    while(i<n-1)
    {
        if((arr[j]-arr[i])==k)
            total++;

        else if((arr[j]-arr[i])>k)
        {
            i++;
            j=i;
        }

        j++;
    }

    cout<<total;

    return 0;
}