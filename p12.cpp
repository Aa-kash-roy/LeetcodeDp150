// link :: https://leetcode.com/problems/remove-duplicate-letters/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        stack<char> st;
        st.push(s[0]);
        int freq[26] = {0}, vis[26] = {0};
        for(int i=1;s[i];i++)
            freq[s[i] - 'a'] = i;
        vis[s[0] - 'a'] = 1;
        for(int i=1;s[i];i++)
        {
            if(!vis[s[i] - 'a'])
            {
                while(s[i] < st.top() && freq[st.top()- 'a'] > i)
                {
                    vis[st.top() - 'a'] = 0;
                    st.pop();
                    if(st.size() == 0)
                        break;
                }
                st.push(s[i]);
                vis[s[i] - 'a'] = 1;
            }
        }
        
        string ans = "", res = "";
        while(st.size() > 0)
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
