class Solution {
    vector<int> dp;
    bool helper(vector<int>& arr, int i){
        if(arr[i]==0) return true;
        if(dp[i]!=-1) return dp[i];
        dp[i] = 0;
        if(i - arr[i] >= 0){
            dp[i] = helper(arr, i-arr[i]);
        }
        if(i + arr[i] < arr.size()){
            dp[i] = dp[i] || helper(arr, i + arr[i]);
        }
        return dp[i];
    }
public:
    bool canReach(vector<int>& arr, int start) {
        dp.resize(arr.size(), -1);
        return helper(arr, start);
    }
};