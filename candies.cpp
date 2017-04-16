#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long getans(vector <long > arr)
{
    long len = arr.size();
    vector <long > left(len,1);
    vector <long > right(len,1);
    
    for(long i = 1 ; i < len ; i++)
    {
        if(arr[i] > arr[i-1])
            left[i] = left[i-1] + 1;
    }
    
    for(long i = len-2 ; i > -1 ; i--)
    {
        if(arr[i] > arr[i+1])
            right[i] = right[i+1] + 1;
    }
    
    long ans = 0;
    for(long i = 0 ; i < len ; i++)
        ans += max(left[i],right[i]);
    
    return ans;
}

int main() 
{
    long n,x;
    cin>>n;
    vector <long > arr;
    
    for(long i = 0 ; i < n ; i++)
    {
        cin>>x;
        arr.push_back(x);
    }
    
    cout<<getans(arr);
    return 0;
}