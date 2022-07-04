class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, list<int>> adj;
        for(auto i : prerequisites){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
        }
        int m = queries.size();
        vector<bool> ans;
        vector<vector<int>> dp(n,vector<int>(n, -1));
        for(int i = 0; i < m; i++){
            int src = queries[i][0];
            int des = queries[i][1];
            if(dp[src][des]!=-1){
                if(dp[src][des]==1) ans.push_back(true);
                else ans.push_back(false);
            }
            else{
                queue<int> q;
                q.push(src);
                vector<bool> visited(n, false);
                visited[src] = true;
                while(!q.empty()){
                    int front = q.front();
                    dp[src][front] = 1;
                    if(front==des){
                        ans.push_back(true);
                        break;
                    }
                    q.pop();
                    for(auto j : adj[front]){
                        if(!visited[j]){
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }
                if(ans.size()==i){
                    ans.push_back(false);
                }
            }
        }
        return ans;
    }
};