#include <queue>
#include <algorithm>
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> ordered;
        for (auto stone: stones) {
            ordered.push(stone);
        }
        while (ordered.size() >= 2) {
            int stone1 = ordered.top();
            ordered.pop();
            int stone2 = ordered.top();
            ordered.pop();
            if (stone1 != stone2) {
                ordered.push(max(stone1, stone2) - min(stone1, stone2));
            }
        }
        if (ordered.size() == 0) {
            return 0;
        } else {
            return ordered.top();
        }
    }
};
