from itertools import repeat
class Solution:
    def search(self, grid: List[List[str]], intmap: {(int, int): int}, startrow, startcol, mark, m, n) -> None:
        if (intmap[(startrow, startcol)] == -1 and grid[startrow][startcol] == "1"):
            intmap[(startrow,startcol)] = mark
            #print(str(startrow) + " " + str(startcol))
            if (startrow >= 1):
                if (grid[startrow-1][startcol] == "1"):
                    self.search(grid, intmap, startrow-1, startcol, mark, m, n)
            if (startrow < m-1):
                if (grid[startrow+1][startcol] == "1"):
                    self.search(grid, intmap, startrow+1, startcol, mark, m, n)
            if (startcol >= 1):
                if (grid[startrow][startcol-1] == "1"):
                    self.search(grid, intmap, startrow, startcol-1, mark, m, n)
            if (startcol < n-1):
                if (grid[startrow][startcol+1] == "1"):
                    self.search(grid, intmap, startrow, startcol+1, mark, m, n)
            return None
        
    def numIslands(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n = len(grid[0])
        islands = 1
        islandsmap = dict(zip([(i,j) for i in range(m) for j in range(n)], repeat(-1)))
        for i in range(m):
            for j in range(n):
                if (islandsmap[(i,j)] != -1):
                    pass
                else: 
                    if (grid[i][j] == "0"):
                        islandsmap[(i,j)] = 0
                    else:
                        self.search(grid, islandsmap, i, j, islands, m, n)
                        #print(str(i) + " " + str(j) + "\n")
                        #if (i==3 and j==3):
                            #print(islandsmap)
                        islands += 1
        
        return (islands-1)
                


