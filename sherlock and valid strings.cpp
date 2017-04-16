#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    long val[1000]={},ascii,maxval=0,len,i,lessval=0,greaterval=0,ansg,ansl;
    cin>>s;
    len=s.size();
    for(i=0;i<len;i++)
    {
        ascii=s[i];
        val[ascii]++;
        maxval=max(maxval,val[ascii]);
    }
    for(i=97;i<123;i++)
    {
        if(val[i]!=0 && val[i]<maxval)
        {
            lessval++;
            ansl=i;
        }
        else if(val[i]!=0 && val[i]==maxval)
        {
            greaterval++;
            ansg=i;
        }
    }
    long ind=0;
    if(lessval==0)
        ind=1;
    else if(lessval<2 && lessval!=0)
    {
        if(greaterval==1)
        {
            if(val[ansg]-1==val[ansl])
                ind=1;
        }
        else
        {
            if(val[ansl]-1==0)
                ind=1;
        }
    }
    else if(lessval>1)
    {
        if(greaterval==1)
        {
            if(val[ansg]-1==val[ansl])
                ind=1;
        }
    }
    if(ind==0)
        cout<<"NO\n";
    else
        cout<<"YES\n";
    return 0;
}