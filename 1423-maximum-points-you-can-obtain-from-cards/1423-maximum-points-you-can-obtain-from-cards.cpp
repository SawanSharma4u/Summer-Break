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
        int j = k-1;
        for(int i = n-1; i >= n-k; i--){
            ans = ans - cardPoints[j] + cardPoints[i];
            j--;
            MaxScore = max(MaxScore, ans);
        }
        return MaxScore;
    }
};