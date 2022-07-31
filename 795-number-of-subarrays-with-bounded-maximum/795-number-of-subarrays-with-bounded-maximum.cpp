class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int l, int r) {
        int ans = 0, left = -1, right=-1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > r) left = i;
            if(nums[i] >= l) right = i;
            ans += right-left;
        }
        return ans;
    }
};