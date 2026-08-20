#define ALPHABETS 26
#include <cstring>

class Solution {
public:
    array<int, ALPHABETS> charfreq;
    char mostCommonChar;
    int mostCommonCount = 0;
    int characterReplacement(string s, int k) {
        //initial
        charfreq.fill(0);
        int windowStart = 0;
        int windowSize = 0;
        int charIndex = 0;
        int slen = s.length();
        if (s.length() == 0) {
            return 0;
        } else {
            mostCommonChar = s[0];
        }
            //main loop
        while (charIndex < slen) {
            if (windowSize < k + mostCommonCount) {
                ++windowSize;
                if (++charfreq[s[charIndex] - 'A'] > mostCommonCount) {
                    ++mostCommonCount;
                    mostCommonChar = s[charIndex];
                };
            } else {
                //PRE: they are equal
                if (++charfreq[s[charIndex] - 'A'] == mostCommonCount + 1) {
                    ++mostCommonCount;
                    mostCommonChar = s[charIndex];
                    ++windowSize;
                } else {
                    --charfreq[s[windowStart] - 'A'];
                    windowStart++;
                }
            }
            charIndex++;
        }
        return windowSize;
    }
};
