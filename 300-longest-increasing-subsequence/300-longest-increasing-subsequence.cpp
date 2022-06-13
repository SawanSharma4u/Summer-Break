class Solution {
    int solve(vector<int>& temp, int idx, vector<int>& nums){
        if(idx == nums.size()) return 0;
        if(temp[idx]!=-1) return temp[idx];
        int ans = 0;
        for(int i = idx+1; i < nums.size(); i++){
            if(nums[i]>nums[idx]){
                if(temp[i]!=-1) ans = max(ans, temp[i]);
                else ans = max(ans, solve(temp ,i, nums));
            }
        }
        return temp[idx] = ans+1;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp(nums.size(), -1);
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans = max(ans, solve(temp, i, nums));
        }
        return ans;
    }
};