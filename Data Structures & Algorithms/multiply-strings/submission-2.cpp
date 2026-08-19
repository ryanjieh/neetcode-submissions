#define MAXLENGTH 400
#define BASE 10;

class Solution {
public:
    unordered_map<char, int> charToDigit;
    unordered_map<int, string> digitToChar;
    array<int, MAXLENGTH> placeValue;
    void setup() {
        charToDigit['1'] = 1;
        charToDigit['2'] = 2;
        charToDigit['3'] = 3;
        charToDigit['4'] = 4;
        charToDigit['5'] = 5;
        charToDigit['6'] = 6;
        charToDigit['7'] = 7;
        charToDigit['8'] = 8;
        charToDigit['9'] = 9;
        charToDigit['0'] = 0;
        digitToChar[1] = "1";
        digitToChar[2] = "2";
        digitToChar[3] = "3";
        digitToChar[4] = "4";
        digitToChar[5] = "5";
        digitToChar[6] = "6";
        digitToChar[7] = "7";
        digitToChar[8] = "8";
        digitToChar[9] = "9";
        digitToChar[0] = "0";
        placeValue.fill(0);
    }
    string multiply(string num1, string num2) {
        setup();
        int l1 = num1.length();
        int l2 = num2.length();
        //actually doing the multiplication by repeated addition
        for (int i = 0; i < l1; ++i) {
            for (int j = 0; j < l2; ++j) {
                char dig1 = charToDigit[num1[l1 - 1 - i]];
                char dig2 = charToDigit[num2[l2 - 1 - j]];
                placeValue[i+j] += (dig1 * dig2);
            }
        }
        //handling carry over
        for (int i = 0; i < MAXLENGTH - 1; i++) {
            int carry = placeValue[i] / BASE;
            placeValue[i] = placeValue[i] % BASE;
            placeValue[i+1] += carry;
        }
        
        //printing
        string answer = "";
        bool printing = false;
        for (int i = MAXLENGTH - 1; i >= 0; --i) {
            //cout << placeValue[i];
            if (!printing && placeValue[i] != 0) {
                printing = true;
            } 
            if (printing) {
                answer = answer + digitToChar[placeValue[i]];
            }
        }
        if (answer == "") {
            return "0";
        }
        return answer; 
    }
};
