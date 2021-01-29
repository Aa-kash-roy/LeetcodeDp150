// link :: https://leetcode.com/problems/arithmetic-slices/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        
        // dp[i] Denotes Ap of size >= 3 ending at ith index.
        int n = A.size();
        int dp[200005] = {0};
        
        for(int i=2;i<A.size();i++)
        {
            if(A[i] - A[i-1] == A[i-1] - A[i-2])
                dp[i] = 1 + dp[i-1];
        }
        
        int sum = 0;
        for(int i=0;i<n;i++)
            sum += dp[i];
        
        return sum;
    }
};
