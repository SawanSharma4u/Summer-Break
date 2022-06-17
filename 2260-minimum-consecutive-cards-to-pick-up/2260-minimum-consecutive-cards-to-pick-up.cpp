class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> myMap;
        int n = cards.size();
        int start = -1;
        int minLen = INT_MAX;
        for(int i = 0; i < n; i++){
            if(myMap.find(cards[i])!=myMap.end()){
                start = myMap[cards[i]];
                minLen = min(minLen, i - start+1);
            }
            myMap[cards[i]] = i;
        }
        return minLen==INT_MAX?-1:minLen;
    }
};