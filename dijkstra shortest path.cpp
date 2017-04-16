#include <bits/stdc++.h>
using namespace std;

int findmindist(int node,int totdist[],int &x,int visit[])
{
    int minval=999,ans;
    for(int i=0;i<node;i++)
    {
        if(visit[i]==0)
        {
            minval=min(minval,totdist[i]);
            if(minval==totdist[i])
                ans=i;
        }
    }
    visit[ans]=1;
    x=ans;
    return minval;
}

void dispans(int start,int totdist[],int node)
{
    for(int i=0;i<node;i++)
    {
        if(totdist[i]==999 && i!=start)
            cout<<"-1"<<"\t";
        else if(i!=start && totdist[i]!=999)
            cout<<totdist[i]<<"\t";
    }
}

int main()
{
    int t,node,edge,start;
    cin>>t;
    while(t--)
    {
        cin>>node>>edge;
        int dist[node][node],x,y,i,j,totdist[node],ind=0,mindist;
        int visit[3000]={};
        for(i=0;i<node;i++)
        {
            for(j=0;j<node;j++)
                dist[i][j]=999;
        }

        for(i=0;i<edge;i++)
        {
            cin>>x>>y;
            dist[x-1][y-1]=6;
            dist[y-1][x-1]=6;
        }
        cin>>x;
        x--;
        start=x;
        visit[x]=1;
        for(i=0;i<node;i++)
            totdist[i]=dist[x][i];
        while(ind==0)
        {
            ind=1;
            mindist=findmindist(node,totdist,x,visit);
            for(i=0;i<node;i++)
            {
                if(visit[i]==0)
                    totdist[i]=min(totdist[i],(mindist+dist[x][i]));
            }
            for(i=0;i<node;i++)
            {
                if(visit[i]==0)
                    ind=0;
            }
        }
        dispans(start,totdist,node);
        cout<<endl;
    }
    return 0;
}