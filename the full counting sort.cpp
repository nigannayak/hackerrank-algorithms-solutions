#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    vector <string> v;
    vector <vector <string> > vec(100,v);
    long n,x;
    string s;
    cin>>n;

    for(long i = 0 ; i < n/2 ; i++)
    {
        cin>>x>>s;
        s = "-";
        vec[x].push_back(s);
    }

    for(long i = 0 ; i < n/2 ; i++)
    {
        cin>>x>>s;
        vec[x].push_back(s);
    }

    for(long i = 0 ; i < 100 ; i++)
    {
        for(long j = 0 ; j < vec[i].size() ; j++)
            cout<<vec[i][j]<<" ";
    }
    return 0;
}