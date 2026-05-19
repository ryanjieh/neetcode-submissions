class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        callstack = [(-1,list())]
        answerstack = list()
        maxindex = len(nums) - 1
        while (callstack):
            current = callstack[-1]
            #print(type(current[1]))
            callstack.pop()
            if (current[0] == maxindex):
                answerstack.append(current[1])
            else:
                callstack.append((current[0]+1,current[1]))
                callstack.append((current[0]+1,[*current[1],(nums[current[0]+1])]))
        return answerstack