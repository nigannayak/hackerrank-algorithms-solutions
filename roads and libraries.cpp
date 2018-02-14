#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main ()
{
    long q;
    cin>>q;

    while(q--)
    {
        long n,m,costLib,costRoad,ui,vi;
        cin>>n>>m>>costLib>>costRoad;
        vector <long> v;
        vector <vector <long> > vec(n+1,v);
        for(long i = 0 ; i < m ; i++)
        {
            cin>>ui>>vi;
            vec[ui].push_back(vi);
            vec[vi].push_back(ui);
        }

        long totalAns(0);

        if(costRoad >= costLib)
            totalAns = n*costLib;

        else
        {
            vector <bool> inStack(n+1,false);
            long totalUsed(0);

            long i;
            long from(0);
            queue <long> q;
            while(totalUsed < n)
            {
                if(q.empty())
                {
                    for(long k = from+1 ; k < n+1 ; k++)
                    {
                        if(!inStack[k])
                        {
                            i = k;
                            from = k;
                            break;
                        }
                    }

                    q.push(i);
                    inStack[i] = true;
                    totalAns += costLib;

                    totalUsed++;

                    for(long k = 0 ; k < vec[i].size() ; k++)
                    {
                        if(!inStack[vec[i][k]])
                        {
                            inStack[vec[i][k]] = true;
                            q.push(vec[i][k]);
                            totalAns += costRoad;
                            totalUsed++;
                        }
                    }

                    q.pop();
                }

                else
                {
                    i = q.front();
                    for(long k = 0 ; k < vec[i].size() ; k++)
                    {
                        if(!inStack[vec[i][k]])
                        {
                            inStack[vec[i][k]] = true;
                            q.push(vec[i][k]);
                            totalAns += costRoad;
                            totalUsed++;
                        }
                    }

                    q.pop();
                }
            }
        }

        cout<<totalAns<<endl;
    }

    return 0;
}