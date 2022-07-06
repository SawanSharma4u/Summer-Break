class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size()-1;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans += abs(nums[i]-nums[0]);
        }
        return ans;
    }
    
};