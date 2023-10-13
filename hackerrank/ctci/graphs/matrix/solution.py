"""
https://www.hackerrank.com/challenges/matrix/problem

How to run from VSCode: Run > Run Without Debugging
"""


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