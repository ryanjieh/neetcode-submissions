class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int size = digits.size();
        for (int i = size - 1; i >= 0; --i) {
            digits[i] += carry;
            cout << digits[i] << '\n';
            if (digits[i] == 10) {
                digits[i] = 0;
                carry = 1;
            } else {
                carry = 0;
            }
            cout << digits[i] << '\n';
        }
        if (carry == 1) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
