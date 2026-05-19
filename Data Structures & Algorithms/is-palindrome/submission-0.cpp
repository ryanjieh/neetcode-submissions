class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), [](unsigned char ch){ return tolower(ch); });
        cout << s << "\n";
        string s2 = "";
        string validchars = "qwertyuiopasdfghjklzxcvbnm1234567890";
        copy_if (s.begin(), s.end(), back_inserter(s2), [validchars](unsigned char ch){return validchars.find(ch) != string::npos;});
        cout << s2 << "\n";
        int firstp = 0;
        int lastp = s2.length() - 1;
        bool result = true;
        while (lastp >= firstp) {
            result = result && (s2[lastp] == s2[firstp]);
            lastp--;
            firstp++;
        }
        return result;
    }
};
