class Solution:
    def hasDuplicate(self, nums: List[int]):
        set1 = set()
        ans = False
        for i in range(len(nums)):
            if nums[i] in set1:
                ans = True
            else: 
                set1.add(nums[i])
        return ans
        