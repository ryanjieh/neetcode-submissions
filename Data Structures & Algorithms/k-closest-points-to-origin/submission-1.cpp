class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [] (const vector<int>& a, const vector<int>& b) {
        return ((a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]));
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> topkpoints;
        int i = 0;
        for (; i < k; i++) {
            topkpoints.push(points[i]);
        }
        for (;i < points.size(); i++) {
            if (cmp(points[i], topkpoints.top())) {
                topkpoints.pop();
                topkpoints.push(points[i]);
            }
        }
        vector<vector<int>> answer;
        while (!topkpoints.empty()) {
            answer.push_back(topkpoints.top());
            topkpoints.pop();
        }
        return answer; 
    }
};
