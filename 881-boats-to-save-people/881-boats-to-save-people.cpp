class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boat = 0;
        int i = 0;
        int j = people.size()-1;
        while(i <= j){
            if(people[i]+people[j] > limit){
                j--;
                boat++;
            }
            else{
                i++;
                j--;
                boat++;
            }
        }
        return boat;
    }
};