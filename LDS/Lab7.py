print("---------- Exercise 1 ----------")

def transform(list, dictionary = {}):
    if list == []:
        return dictionary
    else:
        if list[0][0] in dictionary :
            dictionary[list[0][0]] += list[0][1]
        else:
            dictionary[list[0][0]] = list[0][1]
        return transform(list[1:], dictionary)
l = [('a', 7), ('b', 5), ('c', 2), ('a', 3), ('b', 3)]
print(transform(l))

print("---------- Exercise 2 ----------")

l = ["aaa", "bbb", "aaa", "aaa", "bbb", "ccc"]

def list_to_dict(list, dictionary = {}):
    if(list == []) :
        return dictionary
    print(list[0])
    if list[0] in dictionary:
    # if dictionary.get(list[0]):
        dictionary[list[0]] += 1
    else:
        dictionary[list[0]] = 1
    return list_to_dict(list[1:], dictionary)

print(list_to_dict(l))

print("---------- Exercise 3 ----------")

dict1  = {'a': 5, 'b': 7, 'c': 1}

import functools
def filter_with_reduce(dict, condition):
    new_dict = functools.reduce(lambda acc, elem : acc | {elem[0] : elem[1]} if condition(elem[1]) else acc, dict.items(), {})
    return new_dict
print(filter_with_reduce(dict1,lambda c : c >=5))


print("---------- Exercise 4 ----------")

def exists_and_for_all(dict, condition):
    exists = functools.reduce(lambda acc, elem : acc +1 if condition(elem[1]) else acc, dict.items(), 0)
    if exists == len(dict):
        return True,True
    else:
        if exists > 0 :
            return True,False
        else:
            return False,False

exists, for_all = exists_and_for_all(dict1,lambda c : c >=5)
print("exists" ,exists, "for_all", for_all)

print("---------- Exercise 5 ----------")
dict2  = {'a': 5, 'b': 7, 'c': 6}
def map_using_reduce(dict, condition):
    new_dict = functools.reduce(lambda acc,elem: acc | {elem[0] : condition(elem[1])} , dict.items(), {})
    return new_dict
print(map_using_reduce(dict2,lambda x : x +1))

print("---------- Exercise 6 ----------")

def filter_dict_with_list(dict,list, new_set = set()):
    if list == []:
        return new_set
    else:
        #print(list[0])
        if list[0] in dict :
            #print(dict[list[0]])
            new_set.add(dict[list[0]])
        #print(new_set)
        return filter_dict_with_list(dict,list[1:],new_set)

dict ={'aa': 5, 'bb': 7, 'ca': 6}
list = ['aa', 'bb', 'c']
print(filter_dict_with_list(dict,list))

print("---------- Exercise 7 ----------")







