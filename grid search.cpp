#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,R,C,r,c,i,j,l,k,ind,ind1,m,n,val;
    char A[1000][1000],a[1000][1000];
    cin>>t;
    while(t--)
    {
        cin>>R>>C;
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
                cin>>A[i][j];
        }
        cin>>r>>c;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
                cin>>a[i][j];
        }
        //ind=0;
        for(i=0;i<R-r+1;i++)
        {
            for(j=0;j<C-c+1;j++)
            {
               ind=0;
               val=0;
               ind1=0;
               if(A[i][j]==a[0][0])
               {
                   ind=1;
                   k=i;
                   l=j;
                   val=1;
                   m=n=0;
               }
               while(ind==1)
               {
                   if(A[k][l]!=a[m][n])
                   {
                       ind=0;
                       val=0;
                   }
                   if(n==c-1 && m<r-1)
                   {
                       m++;
                       n=0;
                       k++;
                       l=j;
                   }
                   else if(n==c-1 && m==r-1)
                        ind=0;

                   else
                   {
                       n++;
                       l++;
                   }
               }
               if(val==1)
               {
                   cout<<"YES\n";
                   i=R;
                   j=C;
                   ind1=1;
               }
            }
        }
        if(ind1==0)
            cout<<"NO\n";
    }
    return 0;
}
