// Link :: https://leetcode.com/problems/count-vowels-permutation/

class Solution {
public:
    map<char, vector<char>> mp;
    int dp[20005][256];
    int mod = 1e9 + 7;
    int go(int idx, int sz, char ch)
    {
        if(idx == sz)
            return 1;
        if(dp[idx][ch] != -1)
            return dp[idx][ch];
        vector<char> temp = mp[ch];
        int ans = 0;
        for(auto cc:temp)
        {
            ans += go(idx+1, sz, cc);
            ans %= mod;
        }
        return dp[idx][ch] = ans%mod;
    }
    
    int countVowelPermutation(int n) {
        
        memset(dp, -1, sizeof(dp));
        mp['a'].push_back('e');
        mp['e'].push_back('a');
        mp['e'].push_back('i');
        mp['i'].push_back('a');
        mp['i'].push_back('e');
        mp['i'].push_back('o');
        mp['i'].push_back('u');
        mp['o'].push_back('i');
        mp['o'].push_back('u');
        mp['u'].push_back('a');
        
        vector<char> vec = {'a', 'e', 'i', 'o', 'u'};
        int ans = 0;
        
        for(int i=0;i<vec.size();i++)
        {
            ans += go(1, n, vec[i]);
            ans %= mod;
        }
        
        return ans%mod;
    }
};
