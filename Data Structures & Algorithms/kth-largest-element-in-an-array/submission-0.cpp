class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> topk;
        int i = 0;
        for (; i < k; ++i) {
            topk.push(nums[i]);
        }
        for (; i < nums.size(); ++i) {
            if (nums[i] > topk.top()) {
                topk.pop();
                topk.push(nums[i]);
            }
        }
        return topk.top();
    }
};
