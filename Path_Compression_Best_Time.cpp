#include <bits/stdc++.h>
using ll = long long;
#define ln '\n'
using namespace std;

const ll n = 10;
ll parent[n], ranker[n];

/* 
Time Complexity With Union By Rank And Path Compression
For m operations on n element

For m operation on n elements;
    O{m α(n)} => amortised
    where α(n) is inverse Ackerman Function
    α(n) <=4;
*/
void initailizeDSU()
{

    for (ll i = 0; i < n; i++)
    {
        parent[i] = i;
        ranker[i] = 0;
        // suruat mein sabki height 0 hoti hai
    }
}

////**** PATH COMPRESSION *****////
ll findDSU(ll x)
{
    // It reduces the height of TREE
    // Infact all the node between x and root is become direct child
    // of their parents
    if (parent[x] == x)
    {
        return x;
    }

    parent[x] = findDSU(parent[x]);
    return (parent[x]);
}
void unionDSU(ll x, ll y)
{
    /* time Complexity ==> M*O(Log(N))
    M operation

    */
    // jiski height chotti wahe baccha banega
    ll x_rep = findDSU(x);
    ll y_rep = findDSU(y);
    if (x_rep == y_rep)
    {
        return;
        // We don't have to do nothing
        // because they are in the same set
    }
    // now ranker compare
    if (ranker[x_rep] < ranker[y_rep])
    {
        parent[x_rep] = y_rep;
        // We simply make parent of smaller height
    }
    else if (ranker[x_rep] > ranker[y_rep])
    {
        parent[y_rep] = x_rep;
    }
    else
    {
        // agar dono equal hain
        // toh kisi ek ki height badegi
        // dono pe lagene pe
        parent[y_rep] = x_rep;
        ranker[x_rep]++;
    }
}

int main()
{
    return 0;
}
