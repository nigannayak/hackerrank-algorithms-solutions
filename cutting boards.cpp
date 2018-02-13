#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef unsigned long long int nnn;
#define M 1000000007

class node
{
public:
    nnn val;
    char valType;
    node *left;
    node *right;

    void insert1(node **, nnn, char);
    void getVal(node *, nnn &, nnn &, nnn &);
};

void node::insert1(node **root, nnn x, char c)
{
    node *newnode = new node();
    newnode ->left = NULL;
    newnode ->right = NULL;
    newnode ->val = x;
    newnode ->valType = c;

    if(*root == NULL)
    {
        *root = newnode;
        return;
    }

    node *temp,*t;
    temp = *root;
    bool isLeft = false;
    while(temp)
    {
        t = temp;
        if(temp ->val > x)
        {
            temp = temp ->left;
            isLeft = true;
        }

        else
        {
            temp = temp ->right;
            isLeft = false;
        }
    }

    if(isLeft)
        t ->left = newnode;

    else
        t ->right = newnode;
}

void node::getVal(node *temp, nnn &mulx, nnn &muly, nnn &totalAns)
{
    if(temp)
    {
        getVal(temp ->right,mulx,muly,totalAns);

        if(temp ->valType == 'x')
        {
            totalAns += ((temp ->val%M)*(mulx%M))%M;
            muly++;
        }

        else
        {
            totalAns += ((temp ->val%M)*(muly%M))%M;
            mulx++;
        }

        getVal(temp ->left,mulx,muly,totalAns);
    }
}

int main ()
{
    nnn q;
    cin>>q;

    while(q--)
    {
        node obj;
        node *root = NULL;

        nnn m,n,x;
        cin>>m>>n;
        m--;
        n--;
        for(nnn i = 0 ; i < m ; i++)
        {
            cin>>x;
            obj.insert1(&root,x,'y');
        }

        for(nnn i = 0 ; i < n ; i++)
        {
            cin>>x;
            obj.insert1(&root,x,'x');
        }

        nnn mulx(1);
        nnn muly(1);

        nnn totalAns(0);
        obj.getVal(root,mulx,muly,totalAns);

        cout<<(totalAns%M)<<endl;
    }

    return 0;
}