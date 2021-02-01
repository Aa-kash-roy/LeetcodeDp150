// link :: https://atcoder.jp/contests/abc190/tasks/abc190_f
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
#define MAXN        300005

typedef tree<int, null_type, 
     less_equal<int>, rb_tree_tag,
          tree_order_statistics_node_update> 
    pbds; 
// s.find_by_order(idx) find using index..!
// s.order_of_key(val) Gives iterator to the key..! 

/* First solve then try Writing Code.. And be cool ^_^ and calm. */

int n, a[MAXN];          
void solve(){

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];

    int incv[n] = {0};
    pbds st;
    st.insert(a[n-1]);

    for(int i=n-2;i>=0;i--){
        st.insert(a[i]);
        int k = st.order_of_key(a[i]);
        incv[i] = k;
    }
    int sum = 0;
    for(int i=0;i<n;i++)
        sum += incv[i];

    for(int i=0;i<n;i++){
        cout<<sum<<endl;
        sum -= st.order_of_key(a[i]);
        int sz = n - 1 - st.order_of_key(a[i]);
        sum += sz;
    }
}

int32_t main()
{    
    fast;
    int t=1;
    //cin>>t;
    while(t--) solve();
    
    return 0;
}
