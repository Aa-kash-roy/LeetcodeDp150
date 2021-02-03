// link :: https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    vector<vector<string>> res;
    bool is_palindrome(string str)
    {
        string temp = str;
        reverse(str.begin(), str.end());
        return temp==str;
    }
    void go(string s, int low, int high, vector<string> ans){
        if(low > high){
            res.push_back(ans);
            return;
        }
            
        string temp = "";
        for(int i = low; i<=high;i++){
            temp.push_back(s[i]);
            if(is_palindrome(temp)){
                ans.push_back(temp);
                go(s, i+1, high, ans);
                ans.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<string> ans;
        go(s, 0, s.length()-1, ans);
        for(auto x:res)
        {
            for(auto y: x)
                cout<<y<<' ';
            cout<<endl;
        }
        return res;
    }
};
