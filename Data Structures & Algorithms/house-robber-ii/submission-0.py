class Solution:
    def rob(self, nums: List[int]) -> int:
        custlist = nums[2:]
        custlist.append(nums[0])
        return max(self.rob2(nums[1:]), self.rob2(nums[2:]), self.rob2(custlist))
    def rob2(self, nums: List[int]) -> int:
        cashPerHouse = [0,0,0]
        for i in range(len(nums)):
            cashPerHouse.append(nums[i]+max(cashPerHouse[-2], cashPerHouse[-3]))
        return max(cashPerHouse[-1], cashPerHouse[-2])
        