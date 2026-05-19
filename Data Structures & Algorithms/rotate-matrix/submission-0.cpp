class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        cout << size << "   size\n";
        int size1 = size;
        for (int i = 0; i < size1; i++) {
            cout << i << "   i\n";
            for (int j = 0; j < size1 - 1 - i; j++) {
                cout << j << "   j\n";
                cout << size1 << "   size1\n";
                int temp = matrix[i][i+j];
                matrix[i][i+j] = matrix[size1-1-j][i];
                matrix[size1-1-j][i] = matrix[size1-1][size1-1-j];
                matrix[size1-1][size1-1-j] = matrix[i+j][size1-1];
                matrix[i+j][size1-1] = temp;
            }
            size1--;
        }
    }
};
