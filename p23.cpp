// link :: https://leetcode.com/problems/shopping-offers/
class Solution {
public:
    
    map<pair<int, vector<int>>, int> dp;
    int go(vector<int> price, vector<vector<int>> special, vector<int> needs, vector<int> item, int idx)
    {
        if(idx == special.size())
        {
            int cost = 0;
            for(int i=0;i<needs.size();i++)
            {
                cost += (needs[i]-item[i])*price[i];
            }
            return cost;
        }
        
        if(dp.count({idx, item}))
            return dp[{idx, item}];
        bool ok = 0;
        for(int i=0;i<needs.size();i++)
        {
            if(item[i]+special[idx][i] > needs[i]){
                ok = 1;
                break;
            }
        }
        
        if(!ok)
        {
            vector<int> temp(item.size(), 0);
            for(int i=0;i<item.size();i++)
            {
                temp[i] = item[i] + special[idx][i];
            }
           return dp[{idx, item}] = min(special[idx][item.size()] + go(price, special, needs, temp, idx), go(price, special, needs, item, idx+1));
        }
        else
            return dp[{idx, item}] = go(price, special, needs, item, idx+1);
           
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        
        int n = needs.size();
        vector<int> item(n, 0);

        return go(price, special, needs, item, 0);
    }
};
