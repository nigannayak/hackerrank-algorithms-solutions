#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
using namespace std;

unsigned long long int max_div(unsigned long long int start,unsigned long long int final1,unsigned long long int sum,unsigned long long int arr[],unsigned long long int c)
{
    if(final1-start>1 && sum%2 == 0)
    {
        unsigned long long int ans(0),pivot,ind(0);
        for(unsigned long long int i = start ; i < final1 ; i++)
        {
            ans += arr[i];
            if(ans == sum/2)
            {
                pivot = i;
                ind = 1;
                break;
            }
        }

        if(ind == 0)
            return c;

        else
        {
            c++;
            return max(max_div(start,pivot+1,ans,arr,c),max_div(pivot+1,final1,ans,arr,c));
        }
    }

    else
        return c;
}

int main()
{
    unsigned long long int t;
    cin>>t;
    while(t--)
    {
        unsigned long long int n,pivot;
        cin>>n;
        unsigned long long int ans(0),ind(0),arr[n];
        for(unsigned long long int i = 0 ; i < n ; i++)
        {
            cin>>arr[i];
            ans += arr[i];
        }

        if(ans%2 == 0)
        {
            unsigned long long int sum(0);
            for(unsigned long long int i = 0 ; i < n ; i++)
            {
                sum += arr[i];
                if(sum == ans/2)
                {
                    pivot = i;
                    ind = 1;
                    break;
                }
            }

            if(ind == 1)
            {
                unsigned long long int c(1);
                cout<<max(max_div(0,pivot+1,sum,arr,c),max_div(pivot+1,n,sum,arr,c))<<endl;
            }

            else
                cout<<"0\n";
        }

        else
            cout<<"0\n";
    }
    return 0;
}