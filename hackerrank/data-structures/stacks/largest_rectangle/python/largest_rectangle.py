#!/usr/local/bin/python
#  -*- coding: utf-8 -*-
"""
Problem Statement

There are N buildings in a certain one-dimensional landscape. Each building has a height given by hi,iE[1,N]. If you
join K adjacent buildings, they will form a solid rectangle of area K×min(hi,hi+1,…,hi+k−1).

Given N buildings, find the greatest such solid area formed by consecutive buildings.

Input Format
The first line contains N, the number of buildings altogether.
The second line contains N space-separated integers, each representing the height of a building.

Constraints
1≤N≤10**5
1≤hi≤10**6

Output Format
One integer representing the maximum area of rectangle formed.
"""


def largest_rectangle(heights):
    """
    This alghorithm iterates through all the buildings and for each building
    finds the left-most and the right-most not smaller buildings then
    calculate largest area that contains that building.

    Max of this areas is the solution

    Time complexity: perhaps O(n^2)

    :param heights: list of building heights
    :return: int - maximum area of rectangle
    """
    print("")
    n = len(heights)
    print("n " + str(n))
    largest_area = 0

    for building in range(n):
        #print("check building " + str(building)
        leftmost_not_smaller = building
        rightmost_not_smaller = building

        # find the leftmost building that is not smaller than the current one
        if building > 0:
            for left_side_building in range(building-1,-1,-1):
                #print("check left side building " + str(left_side_building))
                if heights[left_side_building] < heights[building]:
                    break
            if heights[left_side_building] < heights[building]:
                leftmost_not_smaller = left_side_building+1
            else:
                leftmost_not_smaller = left_side_building

        # find the rightmost building that is not smaller than the current one
        if building < n-1:
            for right_side_building in range(building+1,n):
                #print("check right side building " + str(right_side_building))
                if heights[right_side_building] < heights[building]:
                    break
            if heights[right_side_building] < heights[building]:
                rightmost_not_smaller = right_side_building-1
            else:
                rightmost_not_smaller = right_side_building
            #print("rightmost_not_smaller is " + str(rightmost_not_smaller))

        #print("area " + str((rightmost_not_smaller-leftmost_not_smaller+1)*heights[building]))
        largest_area = max(largest_area, (rightmost_not_smaller-leftmost_not_smaller+1)*heights[building])

    return largest_area

def marcus_stuhr_solution(h):
    """
    This is stack based solution -- need to document
    """
    N = len(h)
    h += [0]
    stack = []
    i = 0
    best = 0
    while i<=N:
        print("i="+str(i))
        if len(stack)==0 or h[stack[-1]]<=h[i]:
            print("stack="+str(stack))
            if len(stack):
                print("stack[-1]="+str(stack[-1])+" "+str(h[stack[-1]])+":"+str(h[i]))
            stack.append(i)
            i+=1
        else:
            print("else")
            p = stack.pop()
            A = h[p]*(i-stack[-1]-1) if len(stack)>0 else h[p]*i
            print("p="+str(p)+" stack="+str(stack)+" A="+str(A))
            best = max(best,A)
    return best

def largest_rectangle_recursive(h):
    """
    This is just pseudo code for recursive solution

    Perfomrance should be much better then 'largest_rectangle' function, possible n*log(n)
    """
    if len(h) == 1:
        return h[0]

    mid_building = len(h)/2
    l = largest_rectangle_recursive(h[:mid_building])
    r = largest_rectangle_recursive(h[mid_building+1:])
    area_for_mid_building = calculate_area_for_building(mid_building, h)
    return max(l,r,area_for_mid_building)


from time import clock

def test_single_building():
    area = largest_rectangle([4])
    assert area == 4

def test_flat():
    area = largest_rectangle([1,1,1,1,1])
    assert area == 5

def test_ascending():
    area = largest_rectangle([1,2,3,4,5])
    assert area == 9
    area = marcus_stuhr_solution([1,2,3,4,5])
    assert area == 9

def test_descending():
    area = largest_rectangle([5,4,3,2,1])
    assert area == 9

def test_large_number_of_buildings():
    NUM_OF_BUILDINGS = 10000
    from random import randint
    heights = list()
    for ix in range(NUM_OF_BUILDINGS):
        heights.append(randint(1,1000))

    btime = clock()
    area1 = largest_rectangle(heights)
    print(str(area1) + " lr time " + str(clock()-btime))
    btime = clock()
    area2 = marcus_stuhr_solution(heights)
    print(str(area2) + " ms time " + str(clock()-btime))

    assert area1 >= NUM_OF_BUILDINGS
    assert area2 >= NUM_OF_BUILDINGS
    assert area1 == area2

def test_10():
    area = largest_rectangle([1,2,4])
    assert area == 4

def test_12():
    area = largest_rectangle([1,2,5])
    assert area == 5

def test_20():
    area = largest_rectangle([1,2,4,3,4])
    assert area == 9
    area = marcus_stuhr_solution([1,2,4,3,4])
    assert area == 9

def test_30():
    area = largest_rectangle([1,2,3,2,3,4,1,5,2])
    assert area == 10
