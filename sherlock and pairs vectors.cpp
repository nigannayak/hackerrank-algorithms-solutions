#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    long t,n,i,j,x;
    cin>>t;
    while(t--)
    {
        long total=0;
        vector<long> v;
        cin>>n;
        //long size=v.size();
        for(i=0;i<n;i++)
            {
                cin>>x;
            v.push_back(x);
        }
        for(i=0;i<n;i++)
            {
            for(j=i+1;j<n;j++)
                {
                if(v[i]==v[j])
                    total+=2;
            }
        }
        cout<<total<<endl;
    }
    return 0;
}
