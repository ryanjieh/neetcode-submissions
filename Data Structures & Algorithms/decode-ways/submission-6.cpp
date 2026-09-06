class Solution {
public:
    bool checkDoubleDigit(string s, int index) {
        //pre: 0 <= index <= s.length() - 2
        int value = 10*((int)s[index] - (int)'0') + ((int)s[index + 1] - (int)'0');
        return (value <= 26) && (s[index] != '0');
    }
    int numDecodings(string s) {
        int length = s.length();
        int waysIndexByStart[101];
        int index = length - 1;
        if (length == 1) {
            return int(s[0] != '0');
        } 
        waysIndexByStart[length] = 1;
        waysIndexByStart[length - 1] = int(s[length - 1] != '0');
        for (; index > 0; --index) {
            waysIndexByStart[index - 1] = int(checkDoubleDigit(s, index - 1)) * waysIndexByStart[index + 1] + int(s[index - 1] != '0') * waysIndexByStart[index];
        }
        return waysIndexByStart[0];
    }
};
