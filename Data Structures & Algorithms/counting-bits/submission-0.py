class Solution:
    def countBits(self, n: int) -> List[int]:
        outputList = []
        noOfBits = 32
        for number in range(n+1):
            answer = 0
            for i in range(noOfBits):
                check = (number & (1 << i))
                if (check == (1 << i)):
                    answer += 1
            outputList.append(answer)
        return outputList