#include <bits/stdc++.h>
using namespace std;

struct stack1
{
    int nodes[3000];
};
struct stack1 st;
int top=-1,val1,a[3000][3000],visit[3000],maxvalue,val,n,s;

void push()
{
    st.nodes[++top]=s;
}

void maximum()
{
    int j;
    for(j=0;j<n;j++)
    {
        if(a[val-1][j]!=999999 && visit[j]==0 && maxvalue>a[val-1][j])
        {
            maxvalue=a[val-1][j];
            //cout<<maxvalue<<endl;
            s=j;
        }
    }
}

int main()
{
    int m,i,x,y,ind=0,w,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        visit[i]=0;
        for(j=0;j<n;j++)
            a[i][j]=999999;
    }
    for(i=0;i<m;i++)
    {
        cin>>x>>y>>w;
        a[x-1][y-1]=a[y-1][x-1]=w;
    }
    cin>>s;
    visit[s-1]=1;
    int totalweight=0;
    while(ind==0)
    {
        ind=1;
        push();
        maxvalue=999999;
        for(i=0;i<top+1;i++)
        {
            val=st.nodes[i];
            //cout<<val<<" ";
            maximum();
        }
        //cout<<endl;
        //cout<<maxvalue<<endl;
        visit[s]=1;
        s++;
        totalweight+=maxvalue;
        for(i=0;i<n;i++)
        {
            if(visit[i]==0)
                ind=0;
        }
    }
    cout<<totalweight<<endl;
    return 0;
}