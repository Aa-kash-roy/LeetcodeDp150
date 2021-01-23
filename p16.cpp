// link :: https://atcoder.jp/contests/abc189/tasks/abc189_d
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
using namespace __gnu_pbds; 

#define pb          push_back
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define endl        "\n"
#define fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int         long long int
#define mod         1000000007
#define MAXN        200001

typedef tree<int, null_type, 
     less_equal<int>, rb_tree_tag,
          tree_order_statistics_node_update> 
    Ordered_set; 
// s.find_by_order(idx) find using index..!
// s.order_of_key(val) Gives iterator to the key..! 

/* First solve then try Writing Code.. And be cool ^_^ and calm. */

int n, a[65];
string str;
int dp[65][3];
int go(int last, int idx)
{
    if(idx == n)
    {
        if(last == 1)
            return 1;
        return 0;
    }

    if(dp[idx][last] != -1)
        return dp[idx][last];

    if(a[idx] == 1)
        return dp[idx][last] = go(last&1, idx+1) + go(last&0, idx+1);
    else
        return dp[idx][last] = go(last|1, idx+1) + go(last|0, idx+1);
}

void solve(){

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        if(str == "AND")
            a[i] = 1;
        else
            a[i] = 0;
    }

    memset(dp, -1, sizeof(dp));
    int a = go(0, 0);
    memset(dp, -1, sizeof(dp));
    int b = go(1, 0);

    cout<<a+b<<endl;
}

int32_t main()
{    
    int t=1;
    // cin>>t;
    while(t--) solve();
    
    return 0;
}
