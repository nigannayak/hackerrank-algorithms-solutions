#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long int nnn;

nnn power(nnn x, nnn n)
{
    if(n == 0)
        return 1;

    if(n%2 == 0)
        return power(x*x,n/2);

    else
        return x*power(x*x,(n-1)/2);
}

int main()
{
    nnn n,ans(0);
    cin>>n;

    while(n>0)
    {
        if(n%2 == 0)
            ans++;

        n/=2;
    }

    cout<<power(2,ans);
    return 0;
}