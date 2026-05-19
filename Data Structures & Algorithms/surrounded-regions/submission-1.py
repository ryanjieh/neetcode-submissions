import copy
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        #this looks like a bfs problem
        #when we find an O, if we find another O, add O to a queue
        #change the O to a ?
        #if queue terminates when empty, is surrounded, change all ?s to X
        #else keep all ?
        #finally change all ? to O\
        rows = len(board)
        cols = len(board[0])
        for row in range(rows):
            for col in range(cols):
                if (row == 0 or row == rows-1 or col == 0 or col == cols-1):
                    surs = self.dfs(row, col, board, [], rows, cols, "border")
        for row in range(rows):
            for col in range(cols):
                if (board[row][col] == "O"):
                    board[row][col] = "X"
        for row in range(rows):
            for col in range(cols):
                if (board[row][col] == "border"):
                    board[row][col] = "O"
    def dfs (self, row: int, col: int, 
                     board: List[List[str]],
                     accummax: List[tuple(int, int)],
                     rows: int, cols: int, symbol: str) -> List[tuple(int, int)]:
        #print(str(row) + " " + str(col))
        if (board[row][col] == "O"):
            accummax.append((row, col))
            board[row][col] = symbol
            if (row != 0):
                accummax = self.dfs(row-1, col, board, accummax, rows, cols, symbol) 
            if (row != rows-1):
                accummax = self.dfs(row+1, col, board, accummax, rows, cols, symbol)
            if (col != 0):
                accummax = self.dfs(row, col-1, board, accummax, rows, cols, symbol)
            if (col != cols-1):
                accummax = self.dfs(row, col+1, board, accummax, rows, cols, symbol)
        return accummax
        
        


        