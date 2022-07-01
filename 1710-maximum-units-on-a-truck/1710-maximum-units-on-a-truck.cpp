class Solution {
    static bool compare(vector<int> a, vector<int> b){
        return (a[1] > b[1]);
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int ans = 0;
        // for(int i = 0 ; i < boxTypes.size(); i++){
        //     cout<<boxTypes[i][0]<<" "<<boxTypes[i][1]<<endl;
        // }
        for(int i = 0 ; i < boxTypes.size() && truckSize > 0; i++){
            int x = min(boxTypes[i][0], truckSize);
            ans += x*boxTypes[i][1];
            truckSize -= x;
        }
        return ans;
    }
};