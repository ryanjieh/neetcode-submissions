class KthLargest {
public:
    vector<int> topk;
    vector<int> rest;
    vector<int> v;
    int glK;
    KthLargest(int k, vector<int>& nums) {
        glK = k;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            v.push_back(nums[i]);
        }
        /*
        topk.clear();
        for (int i = 0; i < k; i++) {
            topk.push_back(rest.front());
            rest.pop_back();
        }
        for (auto v: topk) {
            cout << v;
        }
        for (auto v: rest) {
            cout << v;
        }*/
        return;
    }
    
    int add(int val) {
        v.push_back(val);
        sort(v.begin(), v.end());
        return v[v.size()-glK];
    }
};
