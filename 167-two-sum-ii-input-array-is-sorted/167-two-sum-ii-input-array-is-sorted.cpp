class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>arr(2);
        for(int i = 0; i < numbers.size(); i++){
            int k = i+1; 
            int j = numbers.size()-1;
            int revised_target = target - numbers[i];
            int ans = -1;
            while(k<=j){
                int mid = (k+j)/2;
                if(numbers[mid]==revised_target){
                    ans = mid;
                    break;
                }
                else if(numbers[mid] > revised_target){
                    j = mid-1;
                }
                else k = mid+1;
            }
            if(ans!=-1){
                arr[0] = i+1;
                arr[1] = ans+1;
                break;
            }
        }
        return arr;
    }
};