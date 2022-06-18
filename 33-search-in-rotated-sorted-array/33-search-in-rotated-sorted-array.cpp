class Solution {
public:
    int search(vector<int>& nums, int target) {
         int start = 0, end = nums.size() - 1;
    while (start < end) {
        int mid = (start + end) / 2;
        if (nums[mid] > nums[end]) {  // eg. 3,4,5,6,1,2
            if (target > nums[mid] || target <= nums[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        } else {  // eg. 5,6,1,2,3,4
            if (target > nums[mid] && target <= nums[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
    }
    if (start == end && target != nums[start]) return -1;
    return start;
    }
};