class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3) return 0;
		int left = 0;
        int result=0;
        int diff = nums[1]-nums[0];
        int cnt = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]-nums[i-1]==diff){
                cnt++;
            }
            else{
                left=i-1; 
                cnt=1;
                diff = nums[i]-nums[i-1];
            }
            if(cnt>=2){
                result += i-left-1;
            }
        }
        return result;
    }
};