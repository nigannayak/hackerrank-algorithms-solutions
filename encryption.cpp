#include <bits/stdc++.h>
using namespace std;

int main()
{
    int len,slen,i,j,m,n,val;
    char s[82],a[100][100],news[82];
    gets(s);
    len=strlen(s);
    slen=0;
    for(i=0;i<len;i++)
    {
        val=s[i];
        if((val<123 && val>96)||(val<91 && val>64))
        {
            news[slen]=s[i];
            slen++;
        }
    }
    n=ceil(sqrt(slen));
    m=floor(sqrt(slen));
    if(m*n<slen)
        m++;
    int k=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            a[i][j]=48;
    }
    for(i=0;i<m;i++)
    {
        j=0;
        while(j<n && k<slen)
        {
            a[i][j]=news[k];
            //cout<<a[i][j];
            k++;
            j++;
        }
        //cout<<endl;
    }
    k=0;
    for(i=0;i<n;i++)
    {
        j=0;
        while(j<m)
        {
            if(a[j][i]!=48)
                cout<<a[j][i];
            j++;
        }
        cout<<"\t";
    }
    return 0;
}