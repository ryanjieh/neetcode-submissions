//AI did this, but i really dont have the energy to
//change the previous recursive submission into a 
//memoised version today. 
//I will just try to solve the similar mistake
//in a future neetcode instead. 
class Solution {
public:
    vector<vector<int>> memo;

    int lcsh(const string& text1, int i, const string& text2, int j) {
        if (i == (int)text1.size() || j == (int)text2.size()) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        int answer = 0;
        for (int it1 = i; it1 < (int)text1.size(); it1++) {
            for (int it2 = j; it2 < (int)text2.size(); it2++) {
                if (text1[it1] == text2[it2]) {
                    int tempanswer = 1 + lcsh(text1, it1 + 1, text2, it2 + 1);
                    if (tempanswer > answer) answer = tempanswer;
                }
            }
        }
        return memo[i][j] = answer;
    }

    int longestCommonSubsequence(string text1, string text2) {
        memo.assign(text1.size() + 1, vector<int>(text2.size() + 1, -1));
        return lcsh(text1, 0, text2, 0);
    }
};