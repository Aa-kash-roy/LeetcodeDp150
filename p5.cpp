// Link :: https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/

class Solution {
public:
    
    bool ok(vector<pair<int,int>> vp, int mid){
        
        bool flag = true;
        for(int i=0;i<vp.size();i++){
            
            if(mid >= vp[i].second){
                mid -= vp[i].first;
            }
            else
                return false;
        }
        return true;
    }
    
    int helper(vector<pair<int,int>> vp){
        sort(vp.begin(), vp.end(), [](pair<int,int> a, pair<int, int> b){
           return (a.second - a.first) > (b.second - b.first); 
        });
        
        int low = 1, high = (int)1e9, ans = -1;
        while(low <= high){
            
            int mid = low + (high - low)/2;
            if(ok(vp, mid)){
                high = mid - 1;
                ans = mid;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
    
    int minimumEffort(vector<vector<int>>& tasks) {
        
        vector<pair<int,int>> vp;
        for(auto x: tasks){
            vector<int> temp = x;
            vp.push_back({temp[0], temp[1]});
        }
        
        return helper(vp);
    }
};
