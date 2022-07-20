class Solution {
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int src){
        visited[src] = true;
        for(auto i : rooms[src]){
            if(!visited[i]){
                dfs(rooms, visited, i);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(rooms, visited, 0);
        for(int i = 0; i < rooms.size(); i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};