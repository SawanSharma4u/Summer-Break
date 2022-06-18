class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size()-1;
        for(int i = 0; i < matrix.size()-1; i++){
            if(target >= matrix[i][0] && target < matrix[i+1][0]){
                row = i;
                break;
            }
        }
        for(int i = 0; i < matrix[row].size(); i++){
            if(target==matrix[row][i])
                return true;
        }
        return false;
    }
};