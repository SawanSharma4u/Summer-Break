class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int i;
        for(i = 0; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1]) break;
        }
        if(i==nums.size()-1) return true;
        if(i >= 1 && nums[i-1] > nums[i+1] && i+2 < nums.size() && nums[i] > nums[i+2]){
            return false;
        }
        i = i + 1;
        for(; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1]) return false;
        }
        return true;
    }
};