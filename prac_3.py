# # Code for 8-Puzzle Problem

# # A* Search Algorithm - f(x) = g(x) + h(x)
# # where g(x) is cost from initial state to current state,aka tree level
# # h(x) is heuristic value, aka difference from goal state
import heapq

class Node: 
    def __init__(self, puzzle, level, hueristic, parent=None):
        self.puzzle = puzzle
        self.level = level
        self.hueristic = hueristic
        self.f = self.level + self.hueristic
        self.parent = parent

    def __lt__ (self, other):
        return self.f < other.f
    
    def generateChild(self, goalState):
        x, y = self.find(self.puzzle, '0')
        swapList = [[x, y-1],[x, y+1],[x-1, y],[x+1, y]]
        # swapList = [[up],[down],[left],[right]]
        children = []
        for i in swapList: 
            child = self.swap(self.puzzle, x, y, i[0], i[1])
            if child is not None: 
                child_node = Node(child, self.level+1, 0, self)
                children.append(child_node)
        return children

    def swap(self, puzzle, x1, y1, x2, y2):
        if x2 >= 0 and x2 < len(self.puzzle) and y2 >= 0 and y2 < len(self.puzzle):
            temp = []
            temp = self.copy(puzzle)
            a = temp[x1][y1]
            temp[x1][y1] = temp[x2][y2]
            temp[x2][y2] = a
            return temp
        else:
            return None

    def copy(self, original):
        temp = []
        for i in original:
            t = []
            for j in i: 
                t.append(j)
            temp.append(t)
        return temp

    def find(self, state, key):
        for i in range(len(self.puzzle)):
            for j in range (len(self.puzzle)):
                if state[i][j] == key: 
                    return i, j


class Puzzle: 
    def __init__ (self, size): 
        self.n = size
        self.open = []
        self.closed = set()
    
    def getPuzzle(self):
        puzzle = []
        for i in range(self.n):
            temp = input().strip().split()
            puzzle.append(temp)
            if len(temp) != self.n:
                print("Invalid input. Please enter a valid input.")
                break
        return puzzle

    def printPuzzle(self, state):
        for i in range(self.n):
            for j in range(self.n):
                print(state[i][j], end = " ")
            print()
        print()        

    def heuristic(self, current, goal): 
        temp = 0
        for i in range(self.n):
            for j in range(self.n):
                if current[i][j] != goal[i][j]:
                    temp += 1
        return temp

    def print_puzzle(self, state):
        for row in state:
            print(" ".join(row))
        print()

    def print_solution_path(self, goal_node):
        path = []
        while goal_node:
            path.append(goal_node.puzzle)
            goal_node = goal_node.parent

        for state in reversed(path):
            self.print_puzzle(state)

    def solve(self, initialState, goalState):
        initialState = Node(initialState, 0, self.heuristic(initialState, goalState))
        heapq.heappush(self.open, initialState)
        print()
        goalNode = None
        while self.open:
            currentState = heapq.heappop(self.open)
            
            if self.heuristic(currentState.puzzle, goalState) == 0:
                print("Found goal state")
                goalNode = currentState
                self.print_solution_path(goalNode)
                break

            self.closed.add(tuple(tuple(row) for row in currentState.puzzle))

            for child in currentState.generateChild(goalState):
                if tuple(tuple(row) for row in child.puzzle) not in self.closed:
                    child.heuristic = self.heuristic(child.puzzle, goalState)
                    child.f = child.level + child.heuristic
                    heapq.heappush(self.open, child)
            
        print("Exited.")


def main():
    p = Puzzle(3)
    print("Enter the initial state:  ")
    initialState = p.getPuzzle()

    print("Enter the goal state: ") 
    goalState = p.getPuzzle()

    print("Processing...")
    p.solve(initialState, goalState)

if __name__ == "__main__":
    main()
