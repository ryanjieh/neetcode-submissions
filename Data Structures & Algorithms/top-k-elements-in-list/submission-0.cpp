class Solution {
public:
    static bool compare(pair<int, int>a, pair<int, int>b) {
        return a.second > b.second;  // Compare by value (descending)
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //1. hash map? but we might need to sort the hash map
        //2. what if we only hold the first k elements and the cutoff point
        //2.1 we keep List A. a list of number which have one count less than
        //the cutoff point, 
        //List B, a list of exactly k digits which are the top elements 
        //1.1 no need sorting, just get the top k and cutoff -1 multiset will do
        //3 from hints bucket sort
        //number of buckets
        unordered_map<int, int> count_um;
        for (auto i: nums) {
            if (count_um.count(i) == 0) {
                count_um[i] = 1;
            } else {
                count_um[i]++;
            }
        }
        int max_value = -1;
        for (auto kv: count_um) {
            if (kv.second > max_value) {
                max_value = kv.second;
            } 
        }
        //make buckets
        vector<pair<int, int>> count_um2(count_um.begin(), count_um.end());
        nth_element(count_um2.begin(), count_um2.begin() + k, count_um2.end(), compare);
        vector<int> answer;
        transform(count_um2.begin(), count_um2.begin() + k, back_inserter(answer), [](pair<int, int> x){return x.first;});
        return answer;
    }
};
