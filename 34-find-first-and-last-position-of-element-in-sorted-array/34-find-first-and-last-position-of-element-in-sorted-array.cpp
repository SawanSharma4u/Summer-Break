class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int high = upper_bound(nums.begin(), nums.end(), target) - nums.begin()-1; 
        if (low >= nums.size() || nums[low] != target)  return {-1,-1};
        return {low, high};
    }
};