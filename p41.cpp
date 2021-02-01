// link :: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/dynamic-programming/msis-official/ojquestion#

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

int n, a[MAXN];            
void solve(){

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];

    int dp[n] = {0};
    for(int i=0;i<n;i++){
        dp[i] = a[i];
        for(int j=0;j<i;j++){
            if(a[i] >= a[j]){
                dp[i] = max(dp[i], dp[j]+a[i]);
            }
        }
    }
    int mx = 0;
    for(auto x: dp)
        mx = max(mx, x);
    cout<<mx<<endl;
}

int32_t main()
{    
    int t=1;
   // cin>>t;
    while(t--) solve();
    
    return 0;
}
