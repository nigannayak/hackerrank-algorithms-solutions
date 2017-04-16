#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

struct node
{
    long pa;
    long da;

    node * left, * right;
};

void insert1(node * &root, long parr[], long darr[], long i)
{
    node * head, * temp, *t1;
    temp = root;
    head = new node();
    head ->pa = parr[i];
    head ->da = darr[i];

    if(root == NULL)
        root = head;

    else
    {
        long ind = 0;
        while(temp != NULL)
        {
            t1 = temp;
            if(parr[i] + darr[i] > temp ->da + temp ->pa)
            {
                temp = temp ->right;
                ind = 2;
            }

            else
            {
                temp = temp ->left;
                ind = 1;
            }
        }

        if(ind == 1)
            t1 ->left = head;

        else
            t1 ->right = head;
    }
}

void find_val(node * temp, long &total, long &k)
{
    if(temp != NULL)
    {
        find_val(temp ->right, total, k);

        if(k > 0)
        {
            total += temp ->pa;
            k --;
        }

        else
            total -= temp ->da;

        find_val(temp ->left, total, k);
    }
}

int main()
{
    long n,k;
    cin>>n>>k;
    node * root = NULL;

    long parr[n], darr[n], ind[n];
    for(long i = 0 ; i < n ; i++)
    {
        cin>>parr[i]>>darr[i];
        ind[i] = 0;
    }

    long no = 0, total = 0;
    k = min(k,n);

    for(long i = 0 ; i < n ; i++)
        insert1(root, parr, darr, i);

    find_val(root, total, k);

    if(total < 0)
        cout<<"0";

    else
        cout<<total;

    return 0;
}