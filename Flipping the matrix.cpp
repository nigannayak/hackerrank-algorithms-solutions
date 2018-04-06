#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>
using namespace std;

int main()
{
    long n,q,x;
    cin>>q;

    while(q--)
    {
        cin>>n;
        vector <vector <long> > vec;
        for(long i = 0 ; i < 2*n ; i++)
        {
            vector <long> v;
            for(long j = 0 ; j < 2*n ; j++)
            {
                cin>>x;
                v.push_back(x);
            }
            vec.push_back(v);
        }

        long ans(0);
        for(long i = 0 ; i < n ; i++)
        {
            for(long j = 0 ; j < n ; j++)
                ans += max(vec[i][j], max(vec[i][2*n-j-1], max(vec[2*n-i-1][j],vec[2*n-i-1][2*n-j-1])));
        }

        cout<<ans<<endl;
    }
    return 0;
}