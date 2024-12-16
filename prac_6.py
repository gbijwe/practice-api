# Travelling salesman problem

from sys import maxsize
from itertools import permutations

def travellingSalesmanProblem(graph, s, V):

	vertex = []
	for i in range(V):
		if i != s:
			vertex.append(i)

	# store minimum weight Hamiltonian Cycle
	min_path = maxsize
	next_possible_permutation = permutations(vertex)

	for i in next_possible_permutation: # i is a tuple of all the routes from source to destination
		current_pathweight = 0

		# compute current path weight
		k = s
		for j in i:
			current_pathweight += graph[k][j]
			k = j
		current_pathweight += graph[k][s] # adding the distance from source to first vertex, i.e. k

		min_path = min(min_path, current_pathweight)

	return min_path

if __name__ == "__main__":
	graph = [
        [0, 10, 15, 20],
        [10, 0, 35, 25],
        [15, 35, 0, 30],
        [20, 25, 30, 0]
    ]

	s = 0 # source vertex
	V = 4
	print("The minimum path is: ", travellingSalesmanProblem(graph, s, V))
