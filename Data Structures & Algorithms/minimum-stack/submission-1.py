import sys

class MinStack:
    def __init__(self):
        self.topelem = None 
        self.minimum = sys.maxsize
        self.mins = []
    def push(self, val: int) -> None:
        new = StackElem(val, self.topelem)
        self.topelem = new
        self.mins.append(self.minimum)
        self.minimum = min(self.minimum, val)
    def pop(self) -> None:
        self.topelem = self.topelem.nextone
        self.minimum = self.mins[-1]
        self.mins.pop()
    def top(self) -> int:
        return self.topelem.this
    def getMin(self) -> int:
        return self.minimum
class StackElem:
    def __init__(self, thisvalue: int, nextvalue: StackElem):
        self.this = thisvalue
        self.nextone = nextvalue



        
