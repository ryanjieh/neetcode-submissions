class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        combinations = []
        callstack = [(0, [], 0)]
        #(sum, list, last possible index)
        while callstack:
            current = callstack[-1]
            callstack.pop()
            if (current[0] == target):
                combinations.append(current[1])
            else:
                for index in range(current[2],len(nums),1):
                    if (current[0] + nums[index] <= target):
                        callstack.append((current[0]+nums[index], [*current[1],nums[index]], index))
        return combinations
        