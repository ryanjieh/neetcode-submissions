from copy import deepcopy
class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        #setup - find horizontal and vertical lengths
        rows = len(heights)
        cols = len(heights[0])
        pacgrid = deepcopy(heights)
        #print(pacgrid)
        for cell in range(cols):
            pacgrid[0][cell] = -2
            self.dfs(0, cell, pacgrid, heights, rows, cols)
            #print(pacgrid)
        for row in range(rows):
            pacgrid[row][0] = -2
            self.dfs(row, 0, pacgrid, heights, rows, cols)
        #print(pacgrid)
        alangrid = deepcopy(heights)
        #print(alangrid)
        for cell in range(cols):
            alangrid[-1][cell] = -2
            self.dfs(rows-1, cell, alangrid, heights, rows, cols)
        for row in range(rows):
            alangrid[row][-1] = -2
            self.dfs(row, cols-1, alangrid, heights, rows, cols)
        print(alangrid)
        #processing done
        return [[x, y] for x in range(rows) for y in range(cols) 
                       if (pacgrid[x][y] < 0 and alangrid[x][y] < 0)]
        #dfs(xcoord, ycoord, pacgrid) - pacgrid is there to ensure no double searches
    def dfs(self, xcoord: int, ycoord: int, 
                  grid: List[List[int]], ref: List[List[int]],
                  rows: int, cols: int):
        #print(str(xcoord) + " " + str(ycoord))
        #print(grid)
        if (grid[xcoord][ycoord] == -1):
            #print("i am a retard!")
            return
        else:
            #print("eat shit " + str(xcoord) + " " + str(ycoord)) 
            grid[xcoord][ycoord] = -1
            if (xcoord != 0 and ref[xcoord-1][ycoord] >= ref[xcoord][ycoord] and grid[xcoord-1][ycoord] > -1):
                self.dfs(xcoord-1, ycoord, grid, ref, rows, cols)
            if (xcoord != rows-1 and ref[xcoord+1][ycoord] >= ref[xcoord][ycoord] and grid[xcoord+1][ycoord] > -1):
                self.dfs(xcoord+1, ycoord, grid, ref, rows, cols)
            if (ycoord != 0 and ref[xcoord][ycoord-1] >= ref[xcoord][ycoord] and grid[xcoord][ycoord-1] > -1):
                self.dfs(xcoord, ycoord-1, grid, ref, rows, cols)
            if (ycoord != cols-1 and ref[xcoord][ycoord+1] >= ref[xcoord][ycoord] and grid[xcoord][ycoord+1] > -1):
                self.dfs(xcoord, ycoord+1, grid, ref, rows, cols)
            #print(grid)
            return

        