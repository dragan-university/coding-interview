"""

"""

def merge_sorted_lists(list1, list2):
    l1idx = 0
    l2idx = 0
    listm = []

    while ((l1idx < len(list1)) or (l2idx < len(list2))):
        if (l1idx == len(list1)):
            listm.append(list2[l2idx])
            l2idx += 1
        elif (l2idx == len(list2)):
            listm.append(list1[l1idx])
            l1idx += 1
        else:
            if (list1[l1idx] < list2[l2idx]):
                listm.append(list1[l1idx])
                l1idx += 1
            else:
                listm.append(list2[l2idx])
                l2idx += 1
    
    return listm

def test_driver(l1, l2, expected_lm):
    actual_lm = merge_sorted_lists(l1, l2)

    if (expected_lm == actual_lm):
        print('PASS')
    else:
        print('FAIL') 

test_driver([1,3,5], [2,4,6], [1,2,3,4,5,6])
test_driver([1,2], [2,3], [1,2,2,3])
