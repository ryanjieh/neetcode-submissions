class Solution:
    def climbStairs(self, n: int) -> int:
        listofways = []
        listofways.append(1)
        listofways.append(2)
        for i in range(n):
            listofways.append(listofways[-1] + listofways[-2])
        return listofways[n-1]
        