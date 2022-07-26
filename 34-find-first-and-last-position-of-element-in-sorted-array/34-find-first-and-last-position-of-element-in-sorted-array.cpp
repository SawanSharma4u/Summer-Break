class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        if(nums.size()==0){
            ans.resize(2,-1);
            return ans;
        }
        int i = 0, j = nums.size()-1;
        int y=-1;
        while(i <= j){
            int mid = (i + j)/2;
            if(nums[mid] == target){
                y = j;
                break;
            }
            else if(nums[mid] < target){
                i = mid+1;
            }
            else j = mid-1;
        }
        while(i <= j){
            int mid = (i+j)/2;
            if(nums[mid] >= target){
                j = mid-1;
            }
            else{
                i = mid+1;
            }
        }
        if(i>=0 && i < nums.size() && nums[i]==target) ans.push_back(i);
        else {
            ans.resize(2,-1);
            return ans;
        }
        while(i<=y){
            int mid = (i+y)/2;
            if(nums[mid] <= target){
                i = mid+1;
            }
            else{
                y = mid-1;
            }
        }
        int upper_bound;
        ans.push_back(y);
        return ans;
    }
};