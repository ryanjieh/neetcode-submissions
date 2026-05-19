class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        fresh = 0
        queue = []
        days = 0
        #count no. of fresh fruits
        for row in range(m):
            for col in range(n):
                if (grid[row][col] == 1):
                    fresh += 1
                    print(fresh)
                if (grid[row][col] == 2):
                    queue.append((row, col, 0))
        #simulated rotting
        while (fresh and queue):
            (fresh, days) = self.traverse(grid, queue, fresh, days, m, n)
        if fresh:
            return -1
        else:
            return days
    def traverse(self, grid: List[List[int]], queue: List[Tuple(int, int, int)], fresh: int, days: int, m: int, n: int):
        (row, col, value) = queue[0]
        print(str(row) + " " + str(col) + " " + str(value))
        if (grid[row][col] == 1):
            grid[row][col] = 2
            fresh = fresh - 1
            #print(str(row) + " " + str(col) + " " + str(value))
            print(fresh)
            if (value > days):
                days = value
                print(str(days) + "days")
        if (row != 0 and grid[row-1][col] == 1):
            queue.append((row-1, col, value+1))
        if (row != m-1 and grid[row+1][col] == 1):
            queue.append((row+1, col, value+1))
        if (col != 0 and grid[row][col-1] == 1):
            queue.append((row, col-1, value+1))
        if (col != n-1 and grid[row][col+1] == 1):
            queue.append((row, col+1, value+1))
        queue.pop(0)
        return (fresh, days)
        

                
        