class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size()));
      
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j]==0){
                    ans[i][j] = 0;
                }
                else if(i==0){
                    if(j!=0) ans[i][j] = min(INT_MAX-1, ans[i][j-1])+1;
                    else ans[i][j] = INT_MAX;
                }
                else{
                    if(j!=0){
                        ans[i][j] = min(INT_MAX-1, min(ans[i][j-1], ans[i-1][j])) + 1;
                    }
                    else ans[i][j] = min(INT_MAX-1, ans[i-1][j])+1;
                }
            }
        }
        for(int i = mat.size()-1 ; i >= 0; i--){
            for(int j = mat[0].size() - 1; j >= 0; j--){
                if(i==mat.size()-1){
                    if(j!=mat[0].size()-1) ans[i][j] = min(ans[i][j], ans[i][j+1]+1);
                }
                else{
                    if(j!=mat[0].size()-1) ans[i][j] = min(min(ans[i][j], ans[i][j+1]+1), ans[i+1][j]+1);
                    else ans[i][j] = min(ans[i][j], ans[i+1][j]+1);
                }
            }
        }
        return ans;
    }
};