// Support Two operation Union and Find
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll no_of_element = 5;

//****"Simple Implementation"****//

ll parent[no_of_element];

void initializeDSU()
{
    for (ll i = 0; i < no_of_element; i++)
    {
        parent[i] = i;
        // shuruaat mein sab log apne baap hain
    }
}

ll findDSU(ll x)
{
    // uska parent kaun hain
    // Time Complexity => O(N);
    if (parent[x] == x)
    {
        return x;
    }
    return findDSU(parent[x]);
}

void unionDSU(ll x, ll y)
{
    // Time Complexity => O(N);
    ll x_rep = findDSU(x);
    ll y_rep = findDSU(y);
    if (x_rep != y_rep)
    { // agar dono ka parent ek nhi hai toh
        //  kisi ek ko dushra ka parent bane do
        parent[y_rep] = x_rep;
    }
    else
    {
        return;
    }
}

int main()
{
    ll x, y;
    initializeDSU();
    cin >> x >> y;
    unionDSU(x, y);
    cin >> x >> y;
    unionDSU(x, y);
    // cin >> x >> y;
    while (cin >> x >> y)
    {
        if (findDSU(x) == findDSU(y))
        {
            cout << "yes" << '\n';
        }
        else
        {
            cout << "No" << '\n';
        }
    }
    return 0;
}
