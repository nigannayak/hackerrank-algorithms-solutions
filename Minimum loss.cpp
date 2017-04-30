#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define boost ios_base::sync_with_stdio(false)
typedef unsigned long long int nnn;

int main()
{
    nnn n,val;
    map <nnn,nnn> mp;
    cin>>n;

    nnn max_val = 0;
    for(nnn i = 0 ; i < n ; i++)
    {
        cin>>val;
        mp.insert(make_pair(val,i));
        max_val = max(max_val,val);
    }

    nnn ans = max_val;
    nnn i = 0;
    for(map <nnn,nnn> ::iterator it = mp.begin() ; it!=mp.end() ; it++)
    {
        map <nnn,nnn> ::iterator it1 = it;
        nnn max_so_far = max_val;
        nnn j = i;
        while(j > 0)
        {
            if(it->first > it1->first && it1->second > it->second)
            {
                max_so_far = it->first - it1->first;
                break;
            }

            j--;
            it1--;
        }

        if(it->first > it1->first && it1->second > it->second)
            max_so_far = it->first - it1->first;

        ans = min(ans,max_so_far);
        i++;
    }

    cout<<ans;
    return 0;
}