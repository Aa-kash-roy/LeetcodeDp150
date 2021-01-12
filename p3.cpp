// link :: https://codeforces.com/problemset/problem/1324/E
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
 
int n, day, l, r, a[3005];
int dp[2005][2005];

int go(int pos, int last){

    if(pos == n)
        return 0;
    if(dp[pos][last] != -1)
        return dp[pos][last];

    int op1 = 0, op2 = 0;
    int val1 = (last + a[pos] - 1)%day, val2 = (last + a[pos])%day;
    if(val1 >= l &&  val1 <= r)
        op1 = 1 + go(pos+1, val1);
    else
        op1 = go(pos+1, val1);
    if(val2 >= l && val2 <= r)
        op2 = 1 + go(pos+1, val2);
    else
        op2 = go(pos+1, val2);

    return dp[pos][last] = max(op1, op2);
}

void solve(){

    memset(dp, -1, sizeof(dp));
    cin>>n>>day>>l>>r;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<go(0, 0)<<endl;
}

int32_t main()
{    
    int t=1;
    //cin>>t;
    while(t--) solve();
    
    return 0;
}
