class Solution {
    bool check(vector<char>& row, int i, int j, string word){
        if(j-i+1!=word.length()) return false;
        int k = 0;
        while(k < word.length() && (row[k+i]==' ' || row[k+i]==word[k])) k++;
        if(k==word.length()) return true;
        k = 0;
        while(k < word.length() && (row[j-k]==' ' || row[j-k]==word[k])) k++;
        if(k==word.length()) return true;
        return false;
    }
    bool match(vector<vector<char>>& A, string word){
        int m = A[0].size();
        for(auto row : A){
            for(int i = 0; i < m; i++){
                while(i < m && row[i]=='#') i++;
                int start = i;
                while(i < m && row[i]!='#') i++;
                int last = i - 1;
                bool ans = check(row, start, last, word);
                if(ans) return true;
            }
        }
        return false;
    }
public:
    bool placeWordInCrossword(vector<vector<char>>& A, string s) {
        vector<vector<char>> transposeOfA;
        for(int i = 0; i < A[0].size(); i++){
            vector<char> temp;
            for(int j = 0; j < A.size(); j++){
                temp.push_back(A[j][i]);
            }
            transposeOfA.push_back(temp);
        }
        return match(A, s) || match(transposeOfA, s);
    }
};