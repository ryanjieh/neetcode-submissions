class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        #checking whether there is an order which we can take thr courses 
        #to get an order we will dfs through the graph, as i cannot see a clear root
        #the condition for failure is if in the graph turns cyclic 
        #this is a check for cycles!
        answer = True
        for i in range(numCourses):
            coursearray = self.dfs(prerequisites, i, [0 for i in range(numCourses)])
            print("i eat shit")
            print(coursearray)
            if (coursearray[0] == -1):
                answer = False
                break
        return answer
    def dfs(self, prereqs: List[List[int]], index: int, visited: List[int]) -> List[int]:
        print(prereqs)
        print(index)
        print(visited)
        print(visited[index])
        if (visited[index] > 1):
            print("terminate")
            return [-1]
        else:
            print("aaaaaaaaaaaa")
            for (postreq, prereq) in prereqs:
                if visited == [-1]:
                    return [-1]
                if (postreq == index):
                    visited = self.dfs(prereqs, prereq, arrayupdate(visited, postreq))
            return visited
def arrayupdate(visited: List[int], index:int):
    visited[index] += 1
    return visited


        