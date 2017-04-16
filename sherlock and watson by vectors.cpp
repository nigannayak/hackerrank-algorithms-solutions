#include <bits/stdc++.h> // std::vector
using namespace std;

int main ()
{
    vector<long int> v;
    long int n,k,q,x,i;
    cin>>n>>k>>q;
    for(i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }

    k%=n;
    x = n-k;
    rotate(v.begin(),v.begin()+x,v.end());
    for(i=0;i<q;i++)
    {
        cin>>x;
        cout<<v[x]<<endl;
    }
    return 0;
}