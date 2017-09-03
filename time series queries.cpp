#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

typedef long long int nnn;

int main()
{
    nnn n,q,x,no;
    cin>>n>>q;

    vector <nnn> time_stamp;
    vector <nnn> stock_values;
    for(nnn i = 0 ; i < n ; i++)
    {
        cin>>x;
        time_stamp.push_back(x);
    }

    for(nnn i = 0 ; i < n ; i++)
    {
        cin>>x;
        stock_values.push_back(x);
    }

    vector <nnn> firstQ(n,0);
    vector <nnn> secondQ(n,0);

    firstQ[0] = stock_values[0];
    for(nnn i = 1 ; i < n ; i++)
        firstQ[i] = max(stock_values[i],firstQ[i-1]);

    secondQ[n-1] = stock_values[n-1];
    for(nnn i = n-2 ; i >= 0 ; i--)
        secondQ[i] = max(stock_values[i],secondQ[i+1]);

    while(q--)
    {
        cin>>no>>x;
        vector <nnn> ::iterator it;
        if(no == 1)
        {
            if(x > firstQ[n-1])
                cout<<"-1\n";

            else
            {
                it = lower_bound(firstQ.begin(),firstQ.end(),x);
                cout<<time_stamp[it-firstQ.begin()]<<endl;
            }
        }

        else
        {
            if(x > time_stamp[n-1])
                cout<<"-1\n";

            else
            {
                it = lower_bound(time_stamp.begin(),time_stamp.end(),x);
                cout<<secondQ[it - time_stamp.begin()]<<endl;
            }
        }
    }
    return 0;
}