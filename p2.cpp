// link :: https://codeforces.com/problemset/problem/1221/D

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
#define INF         (int)(1e18)

typedef tree<int, null_type, 
     less_equal<int>, rb_tree_tag,
          tree_order_statistics_node_update> 
    Ordered_set; 
// s.find_by_order(idx) find using index..!
// s.order_of_key(val) Gives iterator to the key..! 

/* First solve then try Writing Code.. And be cool ^_^ and calm. */

int n, u, v;
vector<pair<int, int>> vp; 

void solve(){

    vp.clear();
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>u>>v;
        vp.pb({u,v});
    }

    int dp[n+1][3];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 0, dp[0][1] = vp[0].S , dp[0][2] = 2*vp[0].S;
    for(int i=1;i<n;i++){

        for(int j=0;j<3;j++){
            int ht = vp[i].F + j;
            int mn = INF;
            for(int k=0;k<3;k++){
                if(vp[i-1].F + k != ht){
                    mn = min(dp[i-1][k], mn);
                }
            }
            dp[i][j] = j*vp[i].S + mn;
        }
    }

    cout<<min({dp[n-1][0], dp[n-1][1], dp[n-1][2]})<<endl;
}

int32_t main()
{    
    fast;
    int t=1;
    cin>>t;
    while(t--) solve();
    
    return 0;
}
