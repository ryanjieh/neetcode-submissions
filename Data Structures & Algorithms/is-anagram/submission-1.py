class Solution:
    def isAnagram(self, s: str, t: str):
        dict1 = {}
        for char1 in s:
            if (dict1.get(char1) == None):
                dict1.update({char1: 1})
            else:
                dict1.update({char1: (dict1.get(char1) + 1)})
        dict2 = {}
        for char2 in t:
            if (dict2.get(char2) == None):
                dict2.update({char2: 1})
            else:
                dict2.update({char2: (dict2.get(char2) + 1)})
        return (dict1 == dict2)   

            

        