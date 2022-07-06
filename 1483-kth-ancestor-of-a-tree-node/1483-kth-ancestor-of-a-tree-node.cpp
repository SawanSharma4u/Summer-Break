class TreeAncestor {
    vector<vector<int>> dp;
public:
    TreeAncestor(int n, vector<int>& parent) {
        dp.resize(20, vector<int>(n));
        for(int i = 0; pow(2,i) <= n; i++){
            for(int j = 0; j < n; j++){
                if(i==0){
                    dp[i][j] = parent[j];
                }
                else{
                    if(parent[j]!=-1){
                        dp[i][j] = dp[i-1][j];
                        if(dp[i][j]!=-1) dp[i][j] = dp[i-1][dp[i][j]];
                        else dp[i][j] = -1;
                    }
                    else dp[i][j] = -1;
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        while(k > 0){
            int temp = 0;
            while(pow(2,temp) <= k){
                temp++;
            }
            temp--;
            k = k - pow(2, temp);
            node = dp[temp][node];
            if(node == -1) return -1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */