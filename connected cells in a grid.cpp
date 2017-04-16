#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define boost ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

void DFS(int x,int y,int m,int n,vector <vector <bool> > &visited,int &ans)
{
    if(x >= m || y >= n)
        return;

    if(x < 0 || y < 0)
        return;

    if(visited[x][y])
        return;

    visited[x][y] = true;
    ans++;

    DFS(x+1,y,m,n,visited,ans);
    DFS(x+1,y+1,m,n,visited,ans);
    DFS(x+1,y-1,m,n,visited,ans);
    DFS(x,y+1,m,n,visited,ans);
    DFS(x,y-1,m,n,visited,ans);
    DFS(x-1,y,m,n,visited,ans);
    DFS(x-1,y+1,m,n,visited,ans);
    DFS(x-1,y-1,m,n,visited,ans);
}

int main()
{
    int n,m,x;
    cin>>m>>n;
    vector <int> v(n,0);
    vector <vector <int> > board(m,v);

    vector <bool> v1(n,false);
    vector <vector <bool> > visited(m,v1);
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin>>x;
            board[i][j] = x;
            if(x == 0)
                visited[i][j] = true;
        }
    }

    int ans;
    int actual_ans(0);
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(visited[i][j] == false)
            {
                ans = 0;
                DFS(i,j,m,n,visited,ans);
                actual_ans = max(ans,actual_ans);
            }
        }
    }

    cout<<actual_ans;
    return 0;
}