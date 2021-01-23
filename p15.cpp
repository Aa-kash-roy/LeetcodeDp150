// link :: https://atcoder.jp/contests/abc189/tasks/abc189_c
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

int go(int l, int r)
{
    if(r < l)
        return 0;
    if(r == l)
        return a[r];
    int idx = l;
    for(int i=l;i<=r;i++)
    {
        if(a[i] < a[idx])
            idx = i;
    }

    int fi = go(l, idx-1);
    int se = go(idx+1, r);

    if(a[idx]*(r-l+1) > max(fi, se))
        return a[idx]*(r-l+1);
    else
        return max(fi, se);
}

void solve(){

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<go(0, n-1)<<endl;
}

int32_t main()
{    
    int t=1;
    // cin>>t;
    while(t--) solve();
    
    return 0;
}
