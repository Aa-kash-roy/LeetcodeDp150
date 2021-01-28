// link :: https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3618/

class Solution {
public:
    
    int concatenatedBinary(int n) {
      
        long long int N = (1e9 + 7);
        long long ans=1;
        for(int i=2;i<=n;i++)
        {
            int digit=log2(i)+1;
            ans=(((ans%N*(1<<digit))%N+i)%N);
        }
        return ans;
    }
};
