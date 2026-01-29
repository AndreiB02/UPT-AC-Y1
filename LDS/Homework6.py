print("-------- 1 --------")

def printSet ( set):  #without using a print function
    print("{", end="")
    cnt = 0
    for element in set:
        cnt += 1
        if len(set) != cnt :
            print(element , end= ",")
        else :
            print(element, end="")
    print("}")

set1 = {1,2,5}
printSet( set1 )
print("-------- 2 --------")

def first_elem(pairs):
    result = set()
    for a, b in pairs:
        result.add(a)
    return result

pairs = [(1,2), (3,4)]
print(first_elem(pairs))

print("-------- 3 --------")

def filter_set(setFilter, condition):
    result = set()
    for element in setFilter:
        if(condition(element)):
            result.add(element)
    return result

set1 = {1,2,3,4,5,6}
set2 = {1,10,15,20,6}
set3 = {6,7,8,9,10}
print(filter_set(set1, lambda x : x % 2 == 0))

print("-------- 4 --------")

def partition_set(sets, condition):
    result_True = set()
    result_False = set()
    for element in sets:
        if(condition(element)):
            result_True.add(element)
        else:
            result_False.add(element)
    return result_True, result_False
print(partition_set(set1,lambda x : x % 2 == 0))

print("-------- 5 --------")

def intersection_set(sets):
    result = set()
    result = sets[0]
    for Set in sets:
        result = result & Set
    return result


sets = [set1,set2, set3]
print("intersection", intersection_set(sets))

print("-------- 6 --------")

# def digits_to_set(number):
#     result = set()
#     while(number > 0):
#         result.add(number% 10)
#         number //= 10
#     return result
# def union_digits(sets):
#     result = set()
#     print(sets[1])
#     result |= digits_to_set(sets[0])
#     for number in sets:
#         result = result & digits_to_set(number)
#     return result


set_no = {123,124,12345}
print("first:", iter(set_no))
#print("union digits", union_digits(set_no))

