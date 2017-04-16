#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int nnn;

int main()
{
    nnn n,q,a,b,k;
    cin>>n>>q;
    vector <nnn> arr(n);

    for(nnn i = 0 ; i < n ; i++)
        arr[i] = 0;

    for(nnn i = 0 ; i < q ; i++)
    {
        cin>>a>>b>>k;
        arr[a-1] += k;

        if(b != n)
            arr[b] -= k;
    }

    for(nnn i = 1 ; i < n ; i++)
        arr[i] += arr[i-1];

    vector <nnn> :: iterator ans = max_element(arr.begin(),arr.end());
    cout<<*ans;
    return 0;
}