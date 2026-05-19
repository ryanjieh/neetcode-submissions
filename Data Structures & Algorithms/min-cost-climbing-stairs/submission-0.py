class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        costPerStep = [0, 0]
        for step in (reversed(cost)):
            costPerStep.append(step+min(costPerStep[-1], costPerStep[-2]))
        return min(costPerStep[-1], costPerStep[-2])

