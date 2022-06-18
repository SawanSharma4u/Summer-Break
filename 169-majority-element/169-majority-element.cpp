class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size()-1, ans;
        while(j - i >= 0){
            if(nums[i]==nums[j]){
                ans = nums[i];
                break;
            }
            i++;
            j--;
        }
        return ans;
    }
};