// Link :: https://leetcode.com/problems/minimum-cost-for-tickets/
class Solution {
public:
    int Day[400];
    int dp[400];
    int go(int idx, vector<int>& costs)
    {
        if(idx > 365)
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        if(Day[idx])
        {
            int op1, op2, op3;
            op1 = op2 = op3 = INT_MAX;
        
            op1 = costs[0] + go(idx + 1, costs);
            op2 = costs[1] + go(idx + 7, costs);
            op3 = costs[2] + go(idx + 30, costs);
            
            return dp[idx] = min({op1, op2, op3});
        }
        else
            return dp[idx] = go(idx+1, costs);
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        memset(Day, 0, sizeof(Day));
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<days.size();i++)
            Day[days[i]] = 1;
        
        return go(1, costs);
    }
};
