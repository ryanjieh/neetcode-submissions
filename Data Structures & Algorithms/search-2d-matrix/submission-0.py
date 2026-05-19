class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        flatList = [eleele for ele in matrix for eleele in ele]
        print(flatList)
        upperBound = len(flatList) - 1
        lowerBound = 0
        searchIndex = (upperBound + lowerBound) // 2
        while((flatList[searchIndex] != target and upperBound > lowerBound)):
            print(searchIndex)
            if (flatList[searchIndex] < target):
                lowerBound = min(len(flatList) - 1, searchIndex + 1)
                print(str(lowerBound) + " lower")
            else:
                upperBound = max(0, searchIndex - 1)
                print(str(upperBound) + " upper")
            searchIndex = (upperBound + lowerBound) // 2
        if (flatList[searchIndex] == target):
            return True
        else:
            return False
        