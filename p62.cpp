// link :: https://binarysearch.com/problems/5-Star-Review-Percentage
int solve(vector<vector<int>>& reviews, int threshold) {
    
    int s0 = 0, s1 = 0;
    for(auto x: reviews){
        s0 += x[0];
        s1 += x[1];
    }

    int low = 0, high = 1e6+7;
    int ans = -1;

    while(low <= high){
        int mid = low + (high - low)/2;
        int val = ((s0 + mid)*100)/(s1 + mid);
        if(val >= threshold)
        {
            high = mid -1;
            ans = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
