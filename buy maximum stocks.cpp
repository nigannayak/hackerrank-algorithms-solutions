#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

typedef unsigned long long int nnn;

class Node
{
public:
    nnn stock_value,position;
    Node *left;
    Node *right;

    void insert1(Node **,nnn,nnn);
    void getval(Node *,nnn &,nnn &);
};

void Node::getval(Node *temp,nnn &rem,nnn &total)
{
    if(temp)
    {
        getval(temp ->left,rem,total);
        nnn sum = temp ->stock_value * temp ->position;
        if(rem >= sum)
        {
            total += temp ->position;
            rem -= sum;
            getval(temp ->right,rem,total);
        }

        else
        {
            total += rem/(temp ->stock_value);
            rem = rem%(temp ->stock_value);
        }
    }
}

void Node::insert1(Node **root,nnn val,nnn pos)
{
    Node *newnode = new Node;
    newnode ->left = newnode ->right = NULL;
    newnode ->stock_value = val;
    newnode ->position = pos;

    if(!(*root))
    {
        *root = newnode;
        return;
    }

    Node *temp,*t;
    temp = *root;
    bool isright;

    while(temp)
    {
        isright = true;
        t = temp;
        if(val < temp ->stock_value)
        {
            temp = temp ->left;
            isright = false;
        }

        else
            temp = temp ->right;
    }

    if(isright)
        t ->right = newnode;

    else
        t ->left = newnode;
}

int main()
{
    Node nn;
    Node *root = NULL;

    nnn n,x,k;
    cin>>n;
    vector <nnn> vec;
    for(nnn i = 0 ; i < n ; i++)
    {
        cin>>x;
        vec.push_back(x);
    }

    cin>>k;
    for(nnn i = 0 ; i < n ; i++)
        nn.insert1(&root,vec[i],i+1);

    nnn rem(k),total(0);
    nn.getval(root,rem,total);

    cout<<total;
    return 0;
}

/*

input::
3
10 7 19

output::
4

*/