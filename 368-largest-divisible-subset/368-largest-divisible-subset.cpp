class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        vector<int> arr(n, 1);
        sort(nums.begin(), nums.end());
        int maxLen = 1;
        int idx = 0;
        for(int i = 1; i < n; i++){
            for(int j = i-1; j >= 0; j--){
                if(nums[i]%nums[j]==0 && arr[i] < arr[j]+1){
                    dp[i] = j;
                    arr[i] = arr[j] + 1;
                    if(arr[i] > maxLen){
                        idx = i;
                        maxLen = arr[i];
                    }
                }
            }
        }
        vector<int> ans(maxLen);
        while(idx!=-1){
            ans[maxLen-1] = nums[idx];
            idx = dp[idx];
            maxLen--;
        }
        return ans;
    }
};