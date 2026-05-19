class Solution {
public:
    int INF = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        cout << m << "\n";
        cout << n << "\n";
        queue<tuple<int, int, int>> bfsqueue;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) {
                    bfsqueue.push(make_tuple(row, col, 0));
                }
            }
        }
        while (not bfsqueue.empty()) {
            traverse(grid, m, n, bfsqueue);
        }
    }
    void traverse(vector<vector<int>>& grid, int m, int n, 
    queue<tuple<int, int, int>>& bfs) {
            int startrow = get<0>(bfs.front());
            int startcol = get<1>(bfs.front());
            int value = get<2>(bfs.front());
            cout << startrow << " " << startcol << " " << value << "\n";
            if (grid[startrow][startcol] == INF) {
                grid[startrow][startcol] = value;
            }
            if (startrow != 0 && grid[startrow-1][startcol] == INF) {
                bfs.push(make_tuple(startrow-1,startcol,value+1));
            }
            if (startrow != m-1 && grid[startrow+1][startcol] == INF) {
                bfs.push(make_tuple(startrow+1,startcol,value+1));
            }
            if (startcol != 0 && grid[startrow][startcol-1] == INF) {
                bfs.push(make_tuple(startrow,startcol-1,value+1));
            }
            if (startcol != n-1 && grid[startrow][startcol+1] == INF) {
                bfs.push(make_tuple(startrow,startcol+1,value+1));
            }
            bfs.pop();
    };
};
