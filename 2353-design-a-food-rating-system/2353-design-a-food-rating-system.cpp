class FoodRatings {
    unordered_map<string, pair<int, string>> mp;
    unordered_map<string, set<pair<int, string>>> mp2;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++){
            mp2[cuisines[i]].insert({-ratings[i], foods[i]});
            mp[foods[i]] = {ratings[i], cuisines[i]};
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = mp[food].second;
        mp2[cuisine].erase({-mp[food].first, food});
        mp2[cuisine].insert({-newRating, food});
        mp[food].first = newRating;
    }
    
    string highestRated(string cuisine) {
        return (*mp2[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */