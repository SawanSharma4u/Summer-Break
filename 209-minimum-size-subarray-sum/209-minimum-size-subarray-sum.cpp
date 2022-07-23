class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int last = -1;
        int ans = INT_MAX;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(sum >= target){
                ans = min(ans, i-last);
                sum = sum-nums[last+1];
                last++;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};