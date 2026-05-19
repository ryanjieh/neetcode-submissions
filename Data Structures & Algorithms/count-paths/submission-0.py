class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # For m rows, n columns
        table = [[0] * (n+1) for _ in range(m+1)]
        table[1][1] = 1
        print(table)
        for m_index in range(m):
            for n_index in range(n):
                if ((m_index == 0 and n_index == 0) == False):
                    table[m_index + 1][n_index + 1] = table[m_index + 1][n_index] + table[m_index][n_index + 1]
                print(table)
        return table[m][n]