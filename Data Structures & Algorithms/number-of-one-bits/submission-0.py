class Solution:
    def hammingWeight(self, n: int) -> int:
        answer = 0
        noOfBits = 32
        for i in range(noOfBits):
            check = (n & (1 << i))
            if (check == (1 << i)):
                answer += 1
        return answer
        