class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> arr;
        for(int i : spells){
            int count = 0;
            int k = 0, j = potions.size()-1;
            while(k <= j){
                int mid = (k+j)/2;
                long long cal = (long long)i*potions[mid];
                if(cal >= success){
                    count += j-mid+1;
                    j = mid-1;
                }
                else{
                    k = mid+1;
                }
            }
            arr.push_back(count);
        }
        return arr;
    }
};