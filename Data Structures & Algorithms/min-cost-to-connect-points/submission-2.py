def pointDistance(point1: List[int], point2: List[int]) -> int:
    return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1])
class Solution:
    def makeListOfEdges(self, points: List[List[int]]) -> List[List[int]]:
        outputList = [[a,b] for a in range(len(points)) for b in range(a)]
        outputList.sort(key = lambda x: pointDistance(points[x[0]], points[x[1]]))
        return outputList
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        groups = [i for i in range(len(points))]
        edgesSorted = self.makeListOfEdges(points)
        targetEdgeIndex = 0
        numberOfEdgesLeft = len(points) - 1
        finalLength = 0
        #print(type(edgesSorted))
        print(edgesSorted)
        while (numberOfEdgesLeft > 0):
            if (groups[edgesSorted[targetEdgeIndex][0]] != groups[edgesSorted[targetEdgeIndex][1]]):
                preyGroup = groups[edgesSorted[targetEdgeIndex][0]]
                predatorGroup = groups[edgesSorted[targetEdgeIndex][1]]
                for i in range(len(points)):
                    if (groups[i] == preyGroup):
                        groups[i] = predatorGroup
                finalLength += pointDistance(points[edgesSorted[targetEdgeIndex][0]], points[edgesSorted[targetEdgeIndex][1]])
                numberOfEdgesLeft -= 1
            targetEdgeIndex += 1
            print(groups)
        return finalLength
    
    
    
        
        