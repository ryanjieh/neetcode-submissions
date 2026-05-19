class Solution:
    def rob(self, nums: List[int]) -> int:
        cashPerHouse = [0,0,0]
        for i in range(len(nums)):
            cashPerHouse.append(nums[i]+max(cashPerHouse[-2], cashPerHouse[-3]))
        return max(cashPerHouse[-1], cashPerHouse[-2])
        