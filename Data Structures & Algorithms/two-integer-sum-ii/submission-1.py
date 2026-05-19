class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        backp = len(numbers) - 1
        frontp = 0
        while (numbers[backp] + numbers[frontp] != target):
            twosum = numbers[backp] + numbers[frontp]
            if (twosum > target):
                backp = backp - 1
            else:
                frontp = frontp + 1
        return [(frontp+1), (backp+1)]
