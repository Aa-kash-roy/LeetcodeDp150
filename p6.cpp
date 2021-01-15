link :: https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/odd-even-subarrays-72ad69db/description/
Idea :: To find number of subarray with zero sum
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

int n, a[MAXN];            
void solve(){

     cin>>n;
     for(int i=0;i<n;i++){
          cin>>a[i];
          if(a[i]&1)
               a[i] = -1;
          else
               a[i] = 1;
     }

     map<int,int> mp;
     mp[0] = 1;

     int sum = 0, ans = 0;
     for(int i=0;i<n;i++){
          sum += a[i];
          if(mp.count(sum))
               ans += mp[sum];
          mp[sum] = mp[sum] + 1;
     }
     cout<<ans<<endl;
}

int32_t main()
{    
    int t=1;
   // cin>>t;
    while(t--) solve();
    
    return 0;
}
