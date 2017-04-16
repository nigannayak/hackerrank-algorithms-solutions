#include <bits/stdc++.h>
using namespace std;

int main()
{
    long i,val1[10002],val2[10002],a[1000010],b[1000010],n,m;
    for(i=0;i<10001;i++)
    {
        val1[i]=0;
        val2[i]=0;
    }
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        val1[a[i]]++;
    }
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>b[i];
        val2[b[i]]++;
    }
    for(i=0;i<10001;i++)
    {
        if(val1[i]!=val2[i])
            cout<<i<<"\t";
    }
    return 0;
}