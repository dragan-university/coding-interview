"""
https://www.hackerrank.com/challenges/ctci-bfs-shortest-reach/problem

How to run from VSCode: Run > Run Without Debugging
"""

DISTANCE_BETWEEN_NODES = 6

class Graph:
    def __init__(self, numberOfNodes):
        self.numberOfNodes = numberOfNodes

        # connections[i] contains list of all nodes connected to the node i
        self.connections = []
        for i in range(self.numberOfNodes):
            self.connections.append([])

    """
    i and j are zero based indexes of the nodes
    """        
    def connect(self, i, j):
        self.connections[i].append(j)
        self.connections[j].append(i)

    """
    startNode is zero based index of the node

    returns list of distances

    created this function because original is not testable
    """        
    def find_all_distances_helper(self, startNode):
        # init distances from start node
        # 0: distane from start node
        # -1: all other nodes are assumed not conneted 
        distances = []
        for i in range(self.numberOfNodes):
            distances.append(-1)
        distances[startNode] = 0

        # perfomr BFS, init queue with start node
        bfsQueue = [startNode]
        while len(bfsQueue) > 0:
            # get first node from queue (imprtant)
            node = bfsQueue.pop(0)

            # iterate through all the connected nodes of this node
            for connectedNode in self.connections[node]:
                # if node was not visited update its distance and add it to the BFS queue
                if distances[connectedNode] == -1:
                    distances[connectedNode] = distances[node] + DISTANCE_BETWEEN_NODES
                    bfsQueue.append(connectedNode)

        # remove start node from the distanes
        distances.remove(0)
        
        return distances

    """
    startNode is zero based index of the node
    """        
    def find_all_distances(self, startNode):
        distances = find_all_distances_helper(startNode)

        for i in range(len(distances)):
            print(distances[i], end = ' ')

        print('')

def hackerrank():
    t = int(input())
    for i in range(t):
        n,m = [int(value) for value in input().split()]
        graph = Graph(n)
        for i in range(m):
            x,y = [int(x) for x in input().split()]
            graph.connect(x-1,y-1) 
        s = int(input())
        graph.find_all_distances(s-1)

def test_find_all_distances(numberOfNodes, edges, startNode, expectedResult):
    graph = Graph(numberOfNodes)
    for edge in edges:
        graph.connect(edge[0]-1, edge[1]-1)

    distances = graph.find_all_distances_helper(startNode-1)
    if distances == expectedResult:
        print("PASS")
    else:
        print("FAIL")
        print("expected: ", expectedResult)
        print("actual:   ", distances)

def test_hr_sample():
    n = 4
    edges = [(1, 2), (1,3)]
    startNode = 1
    expectedResult = [6, 6, -1]

    test_find_all_distances(n, edges, startNode, expectedResult)

def test_01_my():
    n = 5
    edges = [(1, 2), (1,3), (2,4), (4,5), (3,5)]
    startNode = 1
    expectedResult = [6, 6, 12, 12]

    test_find_all_distances(n, edges, startNode, expectedResult)

def test_from_file(inputFile, outputFile):
    inFile = open(inputFile, 'r')
    inFile.readline()
    numberOfNodes, numberOfEdges = [int(value) for value in inFile.readline().split()]
    edges = []
    for i in range(numberOfEdges):
        x, y = [int(value) for value in inFile.readline().split()]
        edges.append([x, y])
    startNode = int(inFile.readline())

    outFile = open(outputFile, 'r')
    expectedResult = [int(x) for x in outFile.readline().split()]

    test_find_all_distances(numberOfNodes, edges, startNode, expectedResult)

"""
Main
"""
#hackerrank()
#test_hr_sample()
test_01_my()
#test_from_file('hr_case_input.txt', 'hr_case_output.txt')
#test_from_file('test_case_1_input.txt', 'test_case_1_output.txt')