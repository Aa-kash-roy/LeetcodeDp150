// link :: https://atcoder.jp/contests/abc190/tasks/abc190_d
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

int n;           
void solve(){

    cin>>n;
    n = 2*n;

    vector<int> div;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0)
        {
            if(n/i == i)
                div.pb(i);
            else
            {
                div.pb(i);
                div.pb(n/i);
            }
        }
    }
    // for(auto x: div)
    //     cout<<x<<' ';
    // cout<<endl;

    int cnt = 0;
    for(auto x: div){
        int val = n/x;
        val = abs(x-val);
        if(val%2)
            cnt++;
    }
    cout<<cnt<<endl;
}

int32_t main()
{    
    int t=1;
    //cin>>t;
    while(t--) solve();
    
    return 0;
}
