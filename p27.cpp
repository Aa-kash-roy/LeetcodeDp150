// link :: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
public:
    
    vector<string> ans;
    map<char, vector<char>> mp;
    void go(string digits, string re, int idx)
    {
        if(idx == digits.length())
            ans.push_back(re);
        vector<char> temp = mp[digits[idx]];
        
        for(auto ch: temp){
            re += ch;
            go(digits, re, idx+1);
            re.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        if(digits.size() == 0)
            return ans;
        mp['1'] = {};
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};
        
        go(digits, "", 0);
        return ans;
    }
};
