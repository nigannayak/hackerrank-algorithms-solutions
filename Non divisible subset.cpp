#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    long n,k;
    cin>>n>>k;
    long arr[n], rem[k];
    
    for(long i = 0 ; i < k ; i++)
        rem[i] = 0;
    
    for(long i = 0 ; i < n ; i++)
    {
        cin>>arr[i];
        rem[arr[i]%k]++;
    }
    
    long ans(0);
    ans += min(rem[0],1L);
    
    if(k%2 != 0)
    {
        for(long i = 1 ; i < k/2+1 ; i++)
            ans += max(rem[i],rem[k-i]);
    }
    
    else
    {
        for(long i = 1 ; i < k/2 ; i++)
            ans += max(rem[i],rem[k-i]);
        
        ans += min(rem[k/2],1L);
    }
    
    cout<<ans;
    return 0;
}