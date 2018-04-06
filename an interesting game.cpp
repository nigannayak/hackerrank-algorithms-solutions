#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>
using namespace std;

int main()
{
    long n,x,q;
    cin>>q;

    while(q--)
    {
        cin>>n;
        vector <long> vec;
        vector <long> maxPosSoFar;
        long maxSoFar(0);
        for(long i = 0 ; i < n ; i++)
        {
            cin>>x;
            vec.push_back(x);

            if(maxSoFar < x)
            {
                maxSoFar = x;
                maxPosSoFar.push_back(i);
            }

            else
                maxPosSoFar.push_back(maxPosSoFar[i-1]);
        }

        long ans(0);
        long cursorPos = n-1;
        while(!(cursorPos == 0 && maxPosSoFar[cursorPos] == 0))
        {
            cursorPos = maxPosSoFar[cursorPos];
            if(cursorPos != 0)
            {
                cursorPos--;
                ans++;
            }
        }

        if(ans%2 == 0)
            cout<<"BOB\n";

        else
            cout<<"ANDY\n";
    }
    return 0;
}

/*

2
5
2 5 6 3 4
0 1 2 2 2

5
5 2 6 3 4
0 0 2 2 2

*/