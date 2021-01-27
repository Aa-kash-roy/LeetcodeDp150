// Link :: https://leetcode.com/problems/regular-expression-matching/
/*
  uploaded this code 
  Just to look in future how terrible I was while writing codes and laugh (^_^).
*/

class Solution {
public:
    vector<int> str;
    
    int dp[30][40];
    bool go(string s, string p, int i1, int i2)
    {
        if(i1 == s.length())
        {
            bool ok = true;
            for(int i=i2;i<p.length();i = i+2)
            {
                if(p[i+1] != '*')
                    ok = false;
            }
            return ok;
        }
        if(i1 == s.length() && i2 == p.length())
            return true;
        if(i2 == p.length())
            return false;
        
        if(dp[i1][i2] != -1)
            return dp[i1][i2];
        if(p[i2+1] && p[i2+1] == '*')
        {
            // cout<<"Im here :: "<<i2<<endl;
            if(p[i2] == '.')
            {
                // cout<<"Im in right loop"<<endl;
                bool res = false;
                int val = i1;
                for(int i=0;i+val<=s.length();i++)
                {
                    // cout<<"Im value of I ::"<<i<<endl;
                    res |= go(s, p, i1+i, i2+2);
                }
                return dp[i1][i2] = res;
            }
            else
            {   
                bool res = false;
                
                if(s[i1] != p[i2])
                {
                    // cout<<"Im calling from not equal"<<endl;
                    res |= go(s, p, i1, i2+2);
                }
                else
                {
                    
                    // cout<<"My char is equal"<<endl;
                    int val = str[i1];
                    // cout<<val<<" Im number of iteration"<<endl;
                    for(int i=0;i<=val;i++)
                    {
                        // cout<<"Im calling with i value:: "<<endl;
                        res |= go(s, p, i1+i, i2+2);
                    }
                }
                return dp[i1][i2] = res;
            }
        }
        else if(p[i2] == '.')
            return dp[i1][i2] = go(s, p, i1+1, i2+1);
        else
        {
            // cout<<"Im here"<<endl;
            if(s[i1] == p[i2])
                return dp[i1][i2] = go(s, p, i1+1, i2+1);
            else
                return dp[i1][i2] = false;
        }
    }
    
    bool isMatch(string s, string p) {
        
        memset(dp, -1, sizeof(dp));
        int n = s.length();
        if(n!= 0)
        {
            str.resize(n);
        str[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            if(s[i] == s[i+1])
                str[i] = str[i+1] + 1;
            else
                str[i] = 1;
        }
        
        }
//         for(auto x: str)
//             cout<<x<<" ";
//         cout<<endl;
        
        return go(s, p, 0, 0);
    }
};
