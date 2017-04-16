#include <iostream>
#include <vector>
using namespace std;

bool check(vector <int> flag)
{
    for(int i = 1 ; i < 101 ; i++)
    {
        if(flag[i] == 0)
            return true;
    }

    return false;
}

int find_pos(vector <int> curr , vector <int> flag , int perm_pos , int &dist)
{
    int pos = 1000;
    dist = 1005;
    for(int i = 1 ; i < 101 ; i++)
    {
        if(flag[i] == 0 && dist > curr[i])
        {
            dist = curr[i];
            pos = i;
        }
    }

    if(dist == 1000)
        return -1;

    return pos;
}

int check_1(vector <vector <int> > board)
{
    int ind;
    for(int i = 93 ; i < 100 ; i++)
    {
        ind = 0;
        for(int j = 1 ; j < 90 ; j++)
        {
            if(board[i][j] == 0)
            {
                ind = 1;
                break;
            }
        }
        
        if(ind == 0)
            return 1;
    }
    
    return -1;
}

int dijkstra(vector <vector <int> > board, vector <int> curr , vector <int> flag)
{
    int dist = 1005;
    int perm_pos = -1;

    perm_pos = check_1(board);

    if(perm_pos == -1)
        return -1;

    while(check(flag))
    {
        int perm_pos = find_pos(curr,flag,perm_pos,dist);
        if(perm_pos == -1)
            return -1;

        flag[perm_pos] = 1;
        for(int i = 1 ; i < 101 ; i++)
        {
            if(flag[i] == 0)
                curr[i] = min(dist+board[perm_pos][i] , curr[i]);
        }
    }

    return curr[100];
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        vector <int> v(101,0);
        vector <vector <int> > board(101,v);

        for(int i = 1 ; i < 101 ; i++)
        {
            for(int j = 1 ; j < 101 ; j++)
            {
                if(i >= j || j-i > 6)
                    board[i][j] = 1000;

                else
                    board[i][j] = 1;
            }
        }

        int ladders,snakes,s_p,d_p;
        cin>>ladders;
        for(int i = 0 ; i < ladders ; i++)
        {
            cin>>s_p>>d_p;
            board[s_p][d_p] = 0;
        }

        cin>>snakes;
        for(int i = 0 ; i < snakes ; i++)
        {
            cin>>s_p>>d_p;
            board[s_p][d_p] = 0;
        }

        vector <int> flag(101,0);
        flag[0] = flag[1] = 1;

        vector <int> curr = board[1];
        int ans = dijkstra(board,curr,flag);

        cout<<ans<<endl;
    }
    return 0;
}