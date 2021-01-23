// link :: https://leetcode.com/problems/decode-xored-permutation/
class Solution {
public:
    
    int ok(int n){
        
        n = n%4;
        if(n==0)
            return n;
        else if(n==1)
            return 1;
        else if(n==2)
            return n+1;
        else
            return 0;
    }
    
    vector<int> decode(vector<int>& encoded) {
        vector<int> res;
        int n = encoded.size()+1;
        int a = ok(n), b = 0;
        for(int i=0;i<n-1;i+=2)
            b = b^encoded[i];
        int c = a^b;
        res.push_back((a^b));
        
        for(int i=n-2;i>=0;i--){
            c = encoded[i]^c;
            res.push_back(c);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
