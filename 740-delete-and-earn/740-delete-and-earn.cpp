class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNumber = 0;
        unordered_map<int, int> points;
        for(int i = 0; i < nums.size(); i++){
            points[nums[i]] += nums[i];
            if(maxNumber < nums[i]){
                maxNumber = nums[i];
            }
        }
        int a = 0;
        int b = points[1];
        for(int i = 2; i <= maxNumber; i++){
            int temp = max(b, a + points[i]);
            a = b;
            b = temp;
        }
        return b;
    }
};