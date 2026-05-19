from itertools import repeat
class Solution:
    def search(self, grid: List[List[int]], intmap: {(int, int): int}, startrow:int, startcol:int, m:int, n:int, area: int) -> int:
        #print(intmap[(startrow, startcol)])
        #print(grid[startrow][startcol])
        if (intmap[(startrow, startcol)] == -1 and grid[startrow][startcol] == 1):
            area = area + 1
            intmap[(startrow,startcol)] = 1
            #print(intmap)
            #print(str(startrow) + " " + str(startcol))
            if (startrow >= 1):
                if (grid[startrow-1][startcol] == 1):
                    area = self.search(grid, intmap, startrow-1, startcol, m, n, area)
            if (startrow < m-1):
                if (grid[startrow+1][startcol] == 1):
                    area = self.search(grid, intmap, startrow+1, startcol, m, n, area)
            if (startcol >= 1):
                if (grid[startrow][startcol-1] == 1):
                    area = self.search(grid, intmap, startrow, startcol-1, m, n, area)
            if (startcol < n-1):
                if (grid[startrow][startcol+1] == 1):
                    area = self.search(grid, intmap, startrow, startcol+1, m, n, area)
            print(area)
        return area
        
    def maxAreaOfIsland(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n = len(grid[0])
        area = 0
        islandsmap = dict(zip([(i,j) for i in range(m) for j in range(n)], repeat(-1)))
        for i in range(m):
            for j in range(n):
                if (islandsmap[(i,j)] != -1):
                    pass
                else: 
                    if (grid[i][j] == 0):
                        islandsmap[(i,j)] = 0
                    else:
                        areatemp = self.search(grid, islandsmap, i, j, m, n, 0)
                        #print(areatemp)
                        #print(str(i) + " " + str(j) + "\n")
                        #if (i==3 and j==3):
                            #print(islandsmap)
                        area = max(areatemp, area)
        return (area)
        