# Implementing Breadth First Search

def bfs(graph, root, visited):
    q = []
    q.append(root)
    visited[root] = 1

    while q:
        current = q.pop(0)
        print("current: ", current)
        for i in range(len(graph[current])):
            if graph[current][i] == 1 and visited[i] == 0:
                q.append(i)
                visited[i] = 1
                # print("queue: ",q)
                # print("visited: ", visited)

# Implementing Depth First Search

def dfs(graph, root, visited):
    visited[root] = 1
    print("current: ", root)

    for i in range(len(graph[root])):
        if graph[root][i] == 1 and visited[i] == 0:
            dfs(graph, i, visited)

def main ():
    graph = [[0,1,0,0,1], [1,0,1,0,1], [0,1,0,1,0], [1,0,1,0,1], [0,1,0,1,0]] # Adjacency matrix
    visited = [0 for _ in range(len(graph))] # Initialize all nodes as not visited

    # Call the BFS function
    print("BFS Traversal: ")
    bfs(graph, 0, visited)

    visited = [0 for _ in range(len(graph))]
    print("DFS Traversal: ")
    dfs(graph, 0, visited)

if __name__ == '__main__':
    main()
