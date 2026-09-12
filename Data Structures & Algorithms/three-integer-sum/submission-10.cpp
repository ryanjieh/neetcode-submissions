#define ELEMENTS_PER_TUPLE 3
#define MIN 10000
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int current = MIN-1;
        int low, high, sum3;
        for (int i = 0; i < size - ELEMENTS_PER_TUPLE + 1; ++i) {
            if (nums[i] == current) {
                continue;
            } else {
                current = nums[i];
            }
            low = i + 1;
            high = size - 1;
            while (low < high) {
                sum3 = nums[low] + nums[high] + nums[i];
                //cout << sum3 << "\n";
                if (sum3 == 0) {
                    vector<int> zerosum;
                    zerosum.push_back(nums[i]);
                    zerosum.push_back(nums[low]);
                    zerosum.push_back(nums[high]);
                    answer.push_back(zerosum);
                    while (low < high && nums[low] == nums[low + 1]) {
                        ++low;
                    }
                    while (low < high && nums[high] == nums[high - 1]) {
                        --high;
                    }
                    ++low;
                    --high;
                } else if (sum3 < 0) {
                    ++low;
                } else {
                    --high;
                }
            }
        }
        return answer;
    }
};
