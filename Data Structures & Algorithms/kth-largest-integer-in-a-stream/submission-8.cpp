#include <queue>
#include <algorithm>
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> topk;
    int glK;
    KthLargest(int k, vector<int>& nums) {
        glK = k;
        sort(nums.begin(), nums.end());
        if (nums.empty()) return;
        for(auto i = nums.end() - 1; i >= nums.end() - min(k, int(nums.size())); i--){
            topk.push(*i);
        }
        return;
    }
    
    int add(int val) {
        if (topk.size() < glK) {
            topk.push(val);
            return topk.top();
        }
        if (val < topk.top()) {
            return topk.top();
        } else {
            topk.push(val);
            topk.pop();
            return topk.top();
        }
    }
};
