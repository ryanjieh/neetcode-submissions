class Solution {
public:
    bool isValid(string s) {
        bool answer = true;
        string opens = "({[";
        string closes = ")}]";
        stack<int> brackets;
        for (char ch: s) {
            for (int i = 0; i < 3; i++) {
                if (ch == opens[i]) {
                    brackets.push(i);
                }
                if (ch == closes[i]) {
                    if (brackets.empty()) {
                        return false;
                    }
                    if (brackets.top() == i) {
                        brackets.pop();
                    }
                    else {
                        return false;
                    }
                }
            }

        }
        return (brackets.empty());
    }
};
