class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int first;
        int second;
        for (int i = 0; i < tokens.size(); ++i) {
                if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                    first = nums.top();
                    nums.pop();
                    second = nums.top();
                    nums.pop();
                    if (tokens[i] == "+") {
                        nums.push(first + second);
                    }
                    if (tokens[i] == "-") {
                        nums.push(second - first);
                    }
                    if (tokens[i] == "*") {
                        nums.push(first * second);
                    }
                    if (tokens[i] == "/") {
                        nums.push(second / first);
                    }
                } else {
                    nums.push(stoi(tokens[i]));
                }
            }
    return nums.top();
    }
};
