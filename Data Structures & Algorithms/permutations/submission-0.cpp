class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer, tempans;
        if (nums.size() == 1) {
            answer.push_back(nums);
        } else {
            for (auto& num: nums)  {
                vector<int> numclone = nums; 
                erase(numclone, num);
                vector<vector<int>> tempans = permute(numclone);
                for (auto& anselem: tempans) {
                    anselem.push_back(num);
                    answer.push_back(anselem); 
                } 
            }
        }
        return answer;
    }
   
};
