class Solution:
    def twoSum(self, nums: List[int], target: int):
    # 1. O(n) time is a problem, no sorting O(n log n)
    # 2. no brute force O(n^2)
    # 3. generate a target list and then look for duplicates 
    # (didnt work because target/2 can choke the program)
        nums2 = [(target - num) for num in nums]
    # 3.1 set generation 
        potentialdupe = set()
        firstindex = -1
    # checking 
        for i in range(0, len(nums)):
            if nums2[i] in potentialdupe:
                second = i
                secondval = nums2[i]
                print(secondval)
                break
            else:
                potentialdupe.add(nums[i])
    # getting first
        for i in range(0, len(nums)):
            if (nums[i] == secondval):
                first = i
                print(nums[i])
                break
    #output
        outlist = []
        outlist.append(min(first, second))
        outlist.append(max(first, second))
        return outlist
        

        