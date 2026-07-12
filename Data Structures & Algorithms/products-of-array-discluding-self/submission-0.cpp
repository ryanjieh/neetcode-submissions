class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int lengthOfInput = nums.size();
        int prefixProducts[1001];
        int suffixProducts[1001];
        prefixProducts[0] = 1;
        suffixProducts[lengthOfInput] = 1;
        for (int i = 0; i < lengthOfInput; i++) {
            prefixProducts[i+1] = prefixProducts[i] * nums[i];
            cout << prefixProducts[i+1] << "\n";
        }
        for (int i = lengthOfInput; i > 0; i--) {
            suffixProducts[i-1] = suffixProducts[i] * nums[i-1];
            cout << suffixProducts[i-1] << "\n";
        }
        //index i of nums
        //is included in index i+1 of pP and
        //index i of sP 
        vector<int> output;
        for (int i = 0; i < lengthOfInput; i++) {
            output.push_back(prefixProducts[i] * suffixProducts[i + 1]);
        }
        return output;
    }
};
