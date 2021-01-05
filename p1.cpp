// Problem Link :: https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/the-old-monk/submissions/
// Tag :: Binary Search

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

int n, a[MAXN], b[MAXN];

int go(){

     int ans = 0;
     for(int i=0;i<n;i++){

          int low = i, high = n-1, p = -1;
          while(low<=high){
               int mid = low + (high-low)/2;
               if(b[mid] >= a[i]){
                    low = mid + 1;
                    p = mid;
               }
               else
                    high = mid - 1;
          }
          ans = max(ans, (p - i));
     }

     return ans;
}

void solve(){

     cin>>n;
     for(int i=0;i<n;i++)
          cin>>a[i];
     for(int i=0;i<n;i++)
          cin>>b[i];

     cout<<go()<<endl;
}

int32_t main()
{    
    int t=1;
    cin>>t;
    while(t--) solve();
    
    return 0;
}
