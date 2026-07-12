#define MAXSIZE 1001
class Solution {
public:
    int countSubstrings(string s) {
        bool isPalin[MAXSIZE][MAXSIZE] = {};
        int length = s.size();
        //isPalin[length][start] for rowmajor ordering
        //base cases
        for (int i = 0; i < length; i++) {
            isPalin[1][i] = true;
        }
        for (int i = 0; i < length - 1; i++) {
            if (s[i] == s[i+1]) {
                isPalin[2][i] = true;
            }
        }
        //dp
        for (int i = 3; i <= length; i++) {
            for (int j = 0; j < length - i + 1; j++) {
                if (s[j] == s[j+i-1] && isPalin[i-2][j+1]) {
                    isPalin[i][j] = true;
                }
            }
        }
        //final answer
        int output = 0;
        for (int i = 0; i <= length; i++) {
            for (int j = 0; j < length - i + 1; j++) {
                if (isPalin[i][j]) {
                    output++;
                }
            }
        }
        return output;
    }
};
