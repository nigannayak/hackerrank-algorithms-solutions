#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

long power(long x , long n)
{
    if(n == 0)
        return 1;

    if(n%2 == 0)
        return power(x*x,n/2);

    else
        return x*power(x*x,(n-1)/2);
}

vector <long> getFlippedBinary(long x)
{
    vector <long> ret;
    while(x > 0)
    {
        ret.push_back(x%2);
        x /= 2;
    }

    reverse(ret.begin(),ret.end());
    vector <long> retA;
    for(long i = 1 ; i < ret.size() ; i++)
        retA.push_back(ret[i] == 1 ? 0 : 1);

    return retA;
}

long getAns(vector <long> vec)
{
    long ans(0);
    long n = vec.size();
    for(long i = 0 ; i < n ; i++)
    {
        if(vec[i] == 1)
            ans += power(2,n-i-1);
    }

    return ans;
}

int main ()
{
    long q;
    cin>>q;

    while(q--)
    {
        long x;
        cin>>x;

        vector <long> vec = getFlippedBinary(x);
        long ans = getAns(vec);
        cout<<ans<<endl;
    }
    return 0;
}