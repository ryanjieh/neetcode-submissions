class Solution {
public:
    int findMin(vector<int> &nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        int low = 0;
        int high = size - 2;
        if (nums[high + 1] - nums[0] > 0) {
            return nums[0];
        }
        //confirmed there is a point to search for 
        int cand;
        while (low < high) {
            cand = low + (high - low)/2;
            cout << cand << "\n";
            if (nums[cand] - nums[cand + 1] > 0) {
                return nums[cand + 1];
            } else {
                if (nums[cand] > nums[size - 1]) {
                    low = cand + 1;
                } else {
                    high = cand;
                }
            }
        }
        return nums[low + 1];
    }
};
