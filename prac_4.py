# # A Star Algorithm
import heapq

class Node:
    def __init__(self, puzzle, parent=None, g=0, h=0):
        self.puzzle = puzzle
        self.parent = parent
        self.g = g
        self.h = h
        self.f = g + h

    def __lt__(self, other):
        return self.f < other.f

def heuristic(current, goal):
    # Manhattan distance
    return abs(current[0] - goal[0]) + abs(current[1] - goal[1])

def a_star(grid, start, destination):
    open_list = []
    closed_list = set()
    start_node = Node(start, None, 0, heuristic(start, destination))

    heapq.heappush(open_list, start_node)
    while open_list: 
        current_node = heapq.heappop(open_list)
        if current_node.puzzle == destination: 
            return reconstruct_path(current_node)
        
        closed_list.add(current_node.puzzle)

        for child in generate_children(current_node, grid):
            if child in closed_list: 
                continue

            g = current_node.g + 1
            h = heuristic(child, destination)
            child_node = Node(child, current_node, g, h)

            if add_to_open(open_list, child_node):
                heapq.heappush(open_list, child_node)

def add_to_open(open_list, child_node):
    for node in open_list:
        if child_node.puzzle == node.puzzle and child_node.g >= node.g:
            return False
    return True

def reconstruct_path(goal_node):
    path = []
    while goal_node: 
        path.append(goal_node.puzzle)
        goal_node = goal_node.parent
    return path[::-1]


def generate_children(current_node, grid):
    neighbours = []
    x, y = current_node.puzzle
    swap_list = [(x, y-1), (x, y+1), (x-1, y), (x+1, y)]
    for i, j in swap_list:
        if 0 <= i < len(grid) and 0 <= j < len(grid[0]) and grid[i][j] == 0:
            neighbours.append((i, j))
    return neighbours


def printMatrix(matrix):
    for row in matrix: 
        for elem in row: 
            print(elem, end=" ")
        print()


def main(): 
    grid = [
        [0, 1, 0, 0, 0],
        [0, 1, 0, 1, 0],
        [0, 0, 0, 1, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 0, 0, 0]
    ]
    start = (0,0)
    destination = (4,4)
    printMatrix(grid)
    path = a_star(grid, start, destination)

    if path: 
        print("Path found")
        for step in path: 
            print(step)
    else: 
        print("No path found")

if __name__ == "__main__":
    main()

# import heapq

# class Node:
#     def __init__(self, position, parent=None, g=0, h=0):
#         self.position = position
#         self.parent = parent
#         self.g = g
#         self.h = h
#         self.f = g + h

#     def __lt__(self, other):
#         return self.f < other.f

# def heuristic(a, b):
#     # Manhattan distance
#     return abs(a[0] - b[0]) + abs(a[1] - b[1])

# def a_star(grid, start, destination):
#     open_list = []
#     closed_list = set()
#     start_node = Node(start, None, 0, heuristic(start, destination))

#     heapq.heappush(open_list, start_node)
#     while open_list:
#         current_node = heapq.heappop(open_list)
        
#         if current_node.position == destination:
#             return reconstruct_path(current_node)
        
#         closed_list.add(current_node.position)

#         for child in generate_children(current_node, grid):
#             if child in closed_list:
#                 continue

#             g = current_node.g + 1
#             h = heuristic(child, destination)
#             child_node = Node(child, current_node, g, h)

#             if add_to_open(open_list, child_node):
#                 heapq.heappush(open_list, child_node)

#     return None

# def add_to_open(open_list, child_node):
#     for node in open_list:
#         if child_node.position == node.position and child_node.g >= node.g:
#             return False
#     return True

# def reconstruct_path(goal_node):
#     path = []
#     node = goal_node
#     while node:
#         path.append(node.position)
#         node = node.parent
#     return path[::-1]

# def generate_children(current_node, grid):
#     neighbours = []
#     x, y = current_node.position
#     swap_list = [(x, y-1), (x, y+1), (x-1, y), (x+1, y)]
#     for i, j in swap_list:
#         if 0 <= i < len(grid) and 0 <= j < len(grid[0]) and grid[i][j] == 0:
#             neighbours.append((i, j))
#     return neighbours

# def print_matrix(matrix):
#     for row in matrix:
#         for elem in row:
#             print(elem, end=" ")
#         print()

# def main():
#     grid = [
#         [0, 1, 0, 0, 0],
#         [0, 1, 0, 1, 0],
#         [0, 0, 0, 1, 0],
#         [0, 1, 1, 1, 0],
#         [0, 0, 0, 0, 0]
#     ]
#     start = (0, 0)
#     destination = (4, 4)
#     print_matrix(grid)
#     path = a_star(grid, start, destination)

#     if path:
#         print("Path found")
#         for step in path:
#             print(step)
#     else:
#         print("No path found")

# if __name__ == "__main__":
#     main()
