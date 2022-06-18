class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(),sum = 0, len = INT_MAX;
        while(r<n){
            sum = sum + nums[r++];
            while(sum>=target){
                len = min(len, r-l);
                sum -= nums[l++];
            }
        }
        return len==INT_MAX ? 0 : len;
        // vector<int> arr;
        // int sum = 0;
        // for(int i : nums){
        //     sum += i;
        //     arr.push_back(sum);
        // }
        // if(sum==target) return nums.size();
        // int i = 0, j = nums.size()-1;
        // while(i < j){
        //     if(target==arr[j]-arr[i]) return j-i;
        //     else if(nums[i] > nums[j]) j--;
        //     else i++;
        // }
        // return 0;
    }
};