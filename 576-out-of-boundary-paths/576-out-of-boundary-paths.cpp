class Solution {
    #define e 1000000007
    unordered_map<string, int> map;
public:
    int findPaths(int m, int n, int k, int i, int j) {
        if(k == 0 || i == m || i < 0 || j < 0 || j == n) return 0;
        string key = to_string(i) + "-" + to_string(j) + "-" + to_string(k);
        if(map.count(key)!=0){
            return map[key];
        }
        int ans = 0;
        if(n==1 && m==1) ans = 4;
        else if((i==0 || i == m-1) && (j == 0 || j == n-1)){
            if(m==1 || n==1) ans = 3;
            else ans = 2;
        }
        else if(i==0 || j == 0 || i==m-1 || j == n-1){
            if(m==1 || n==1) ans = 2;
            else ans = 1;
        }
        ans = ((((ans + findPaths(m, n, k-1, i-1, j))%e + findPaths(m, n, k-1, i+1, j))%e + findPaths(m, n, k-1, i, j-1))%e + findPaths(m, n, k-1, i, j+1))%e;
        map[key] = ans;
        return ans; 
    }
};