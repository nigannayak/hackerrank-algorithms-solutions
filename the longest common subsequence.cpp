#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define boost ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

vector <long> fn(vector <vector <long> > &matrix , vector <long> v1 , vector <long> v2 , long n , int m)
{
    long ans(0);
    for(long i = 0 ; i < m ; i++)
    {
        for(long j = 0 ; j < n ; j++)
        {
            if(v1[j] == v2[i])
                matrix[i+1][j+1] = matrix[i][j]+1;

            else
                matrix[i+1][j+1] = max(matrix[i][j+1],matrix[i+1][j]);

            ans = max(matrix[i+1][j+1],ans);
        }
    }

    vector <long> v;
    long i = m;
    long j = n;

    while(ans!=0)
    {
        if(ans == matrix[i-1][j])
            i--;
        
        else if(ans == matrix[i][j-1])
            j--;
        
        else
        {
            v.push_back(v1[j-1]);
            ans--;
            i--;
            j--;
        }
    }

    reverse(v.begin(),v.end());
    return v;
}

int main()
{
    long n,m,x;
    cin>>n>>m;
    vector <long> v1;
    vector <long> v2;

    for(long i = 0 ; i < n ; i++)
    {
        cin>>x;
        v1.push_back(x);
    }

    for(long i = 0 ; i < m ; i++)
    {
        cin>>x;
        v2.push_back(x);
    }

    vector <long> v(n+1,0);
    vector <vector <long> > matrix(m+1,v);

    vector <long> ans = fn(matrix,v1,v2,n,m);
    for(vector <long> ::iterator it = ans.begin() ; it!=ans.end() ; it++)
        cout<<*it<<" ";

    return 0;
}