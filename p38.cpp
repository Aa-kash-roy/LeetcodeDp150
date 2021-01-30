// link :: https://leetcode.com/problems/russian-doll-envelopes/
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(), envelopes.end(), [](vector<int> a, vector<int> b)         {
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        
        int n = envelopes.size();
        if(n==0)
            return 0;
        int dp[n];
        
        for(int i=0;i<n;i++){
            dp[i] = 1;
            for(int j=0;j<i;j++){
                if(envelopes[i][1] > envelopes[j][1] && envelopes[i][0] > envelopes[j][0])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
        
        int ans = 0;
        for(auto x: dp){
            // cout<<x<<' ';
            ans = max(ans, x);
        }
        // cout<<endl;
        return ans;
    }
};
