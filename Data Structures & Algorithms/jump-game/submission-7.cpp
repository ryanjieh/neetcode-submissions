class Solution {
private: 
    int cjarray[1001];
    int length;
public:
    void cjHelper(vector<int>& nums, int start) {
        //cout << start << "\n";
        //immeidate failure out of bounds
        if (start >= length) {
            cjarray[start] = 0;
            return;
        } 
        //immediate success
        if (start == length - 1) {
            cjarray[start] = 1;
            return;
        }
        //immediate failure 
        if (nums[start] == 0) {
            cjarray[start] = 0;
            return;
        }
        //goal reach
        if (cjarray[start] == -1) {
            bool output = false;
            for (int i = nums[start]; i >= 1; i--) {
                if (cjarray[start + i] == -1) {
                    cjHelper(nums, start + i);
                    if (cjarray[start] == -1) {
                        cjarray[start] = cjarray[start + i];
                    }
                }
                if (cjarray[start + i] == 1) {
                    cjarray[start] = 1;
                }
            }
        }
        // for (int i = 0; i < length; i++) {
        //     cout << cjarray[i] << " ";
        // }
        cout << "\n";
        return;
    }
    bool canJump(vector<int>& nums) {
        length = nums.size();
        fill(cjarray, cjarray+1001, -1);
        cjHelper(nums, 0); 
        return (cjarray[0] == 1);
    }
};
