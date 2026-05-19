class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if (len(edges) != n-1):
            return False
        components = dict()
        for vertex in range(n):
            components[vertex] = vertex
        for edgeIndex in range(n-1):
            start = components[edges[edgeIndex][0]]
            end = components[edges[edgeIndex][1]]
            resultant = min(start, end)
            for vertex in range(n):
                if (components[vertex] == start or components[vertex] == end):
                    components[vertex] = resultant
            print(components)
        for vertex in range(n):
            if components[vertex] != 0:
                print(components)
                return False
        return True


        