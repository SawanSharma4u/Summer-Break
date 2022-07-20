class Solution {
    unordered_map<int, vector<vector<int>> >store;
    vector<vector<int>> dfs(vector<vector<int>>& graph, vector<bool>& visited, int src){
        visited[src] = true;
        vector<vector<int>> ans;
        for(auto i : graph[src]){
            if(!visited[i]){
                vector<vector<int>> temp = dfs(graph, visited, i);
                for(int i = 0; i < temp.size(); i++){
                    ans.push_back(temp[i]);
                }
            }
            else{
                for(auto j : store[i]){
                    ans.push_back(j);
                }
            }
        }
        if(src == graph.size()-1){
            vector<int> temp;
            ans.push_back(temp);
        }
        for(int i = 0; i < ans.size(); i++){
            ans[i].push_back(src);
        }
        store[src] = ans;
        return ans;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        vector<vector<int>> ans = dfs(graph, visited, 0);
        for(int i = 0; i < ans.size(); i++){
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};