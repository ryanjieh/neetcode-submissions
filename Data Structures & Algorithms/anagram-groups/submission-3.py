class Solution:
    def groupAnagrams(self, strs: List[str]):
        #1. we want to put all the characters into a set then compare the sets
        # which that means that we want a list of sets that can be used 
        # to index the elements 
        # and this indexing is done with a dictionary
        listofsets = {} #dict: (set, index)
        strwithindex = [] #list
        #oh shit we forgot to allow duplicates here
        noofsets = 0
        letters = "qwertyuiopasdfghjklzxcvbnm"
        for strin in strs:
            charset = {letter: 0 for letter in letters}
            for char in strin:
                charset[char] += 1
            charset = tuple(charset.items())
            #print(charset)
            if (charset not in listofsets.keys()):
                listofsets.update({charset: noofsets})
                strwithindex.append((strin, noofsets))
                noofsets += 1
            else:
                strmatch = listofsets[charset]
                strwithindex.append((strin, strmatch))
        #output generation
        #print(strwithindex)
        #works fine here
        outputlist = [[] for _ in range (noofsets)]
        for entry in strwithindex:
            #print(outputlist[strwithindex[key]])
            outputlist[entry[1]].append(entry[0])
            #print(outputlist)
        return outputlist
            





        