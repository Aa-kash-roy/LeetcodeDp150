// link :: https://leetcode.com/problems/repeated-dna-sequences/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        set<string> st;
        string temp = "";
        for(int i=0;i<min(10, (int)s.length());i++){
            temp.push_back(s[i]);
        }
        
        set<string> res;
        if(temp.length() < 10)
        {
            temp = "";
            vector<string> tt;
            return tt;
        }
        else
        {
            st.insert(temp);
            for(int i=10;i<s.length();i++){
                temp = temp.substr(1, 9);
                temp.push_back(s[i]);
                if(st.count(temp)){
                    res.insert(temp);
                }
                else
                {
                    st.insert(temp);
                }
            }
        }
        
        vector<string>tt;
        for(auto x: res){
            tt.push_back(x);
        }
        return tt;
        
    }
};
