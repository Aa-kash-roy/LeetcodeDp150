// link :: https://binarysearch.com/problems/Cut-Ribbons-of-Same-Length
bool check(int mid, vector<int> &ribbons, int k){
    long long sum = 0;
    for(auto x: ribbons){
        sum += x/mid;
    }
    return sum>=k ? true : false;
}

int solve(vector<int>& ribbons, int k) {
    
    long long low = 1, high = 1e18+7;
    int ans = -1;
    while(low <= high)
    {
        long long mid = low + (high - low)/2;
        if(check(mid, ribbons, k)){
            low = mid + 1;
            ans = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
