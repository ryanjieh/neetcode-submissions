class Solution:
    def search(self, nums: List[int], target: int) -> int:
        upperBound = len(nums) - 1
        lowerBound = 0
        searchIndex = (upperBound + lowerBound) // 2
        while(nums[searchIndex] != target and upperBound != lowerBound):
            print(searchIndex)
            if (nums[searchIndex] < target):
                lowerBound = min(len(nums) - 1, searchIndex + 1)
            if (nums[searchIndex] > target):
                upperBound = max(0, searchIndex - 1)
            searchIndex = (upperBound + lowerBound) // 2
        if (nums[searchIndex] == target):
            return searchIndex
        else:
            return -1
        