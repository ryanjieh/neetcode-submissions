class Solution {
public:
    int jump(vector<int>& nums) {
        int near = 0;
        int far = 0;
        int answer = 0;
        int newfar = 0;
        int temp = 0;
        int lastindex = nums.size() - 1;
        while (far < lastindex) {
            for (int test = far; test >= near; --test) {
                temp = test + nums[test];
                if (newfar < temp) {
                    newfar = temp;
                }
            }
            cout << newfar << " far \n";
            cout << far + 1 << " near \n";
            near = far + 1;
            far = newfar;
            ++answer;
        }
        return answer;
    }
};
