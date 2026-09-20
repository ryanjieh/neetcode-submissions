class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int low = 0;
        int high = size - 1;
        //low and high are the number of times it has been fotated
        int mid;
        while (low < high) {
            if (nums[low] == target) {
                return low;
            }
            mid = low + (high - low)/2;
            cout << mid << "\n";
            cout << low << "\n";
            cout << high << "\n\n";
            if (nums[low] <= target) {
                if (nums[mid] < target) {
                    if (nums[low] <= nums[mid]) {
                        low = mid + 1;
                    } else {
                        high = mid;
                    }
                } else {
                    high = mid;
                }
            } else {
                if (nums[mid] < target) {
                    if (nums[low] <= nums[mid]) {
                        high = mid;
                    } else {
                        low = mid + 1;
                    }
                } else {
                    if (nums[low] <= nums[mid]) {
                        low = mid + 1;
                    } else {
                        high = mid;
                    }
                }
            }
        }
        if (nums[low] == target) {
            return low;
        } else {
            return -1;
        }
    }
};
