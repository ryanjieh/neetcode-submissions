class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        mostfromhere = [0] * (len(nums))
        for i in range(len(nums) - 1, -1, -1):
            mostfromhere[i] = nums[i]
            if (i < len(nums) - 1 and mostfromhere[i+1] > 0):
                mostfromhere[i] += mostfromhere[i+1]
        return max(mostfromhere)
