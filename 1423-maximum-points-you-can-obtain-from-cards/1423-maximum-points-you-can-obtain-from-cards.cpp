class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0;
        for(int i = 0; i < k; i++){
            ans += cardPoints[i];
        }
        int n = cardPoints.size();
        if(k==n) return ans;
        int MaxScore = ans;
        for(int i = n-1, j = k-1; i >= n-k; i--, j--){
            ans = ans - cardPoints[j] + cardPoints[i];
            MaxScore = max(MaxScore, ans);
        }
        return MaxScore;
    }
};