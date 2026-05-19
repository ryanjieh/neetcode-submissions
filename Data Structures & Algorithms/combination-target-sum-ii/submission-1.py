class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates = sorted(candidates)
        listdict = {}
        callstack = [(0, [], 0, "")]
        #(sum, list, last possible index, unique id)
        while callstack:
            current = callstack[-1]
            print(current[3])
            callstack.pop()
            if (current[0] == target):
                listdict.setdefault(current[3],current[1])
            else:
                for index in range(current[2],len(candidates),1):
                    if (current[0] + candidates[index] <= target):
                        callstack.append((current[0]+candidates[index], [*current[1],candidates[index]], index+1, (current[3]+"!"+str(candidates[index]))))
        return list(listdict.values())