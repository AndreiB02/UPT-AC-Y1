import functools
print("---------------Exercise 1---------------")

number_list  = [1,122,3, 8 ,9 ,10]
def displayEven(list):
    if(len(list) >= 1):
        if(list[0] % 2 == 0 ):
            print(list[0])
        displayEven(list[1:])
displayEven(number_list)


print("---------------Exercise 2---------------")

string_list = [ "abcdde", "cvbn", "aa"]

result = list(filter(lambda x: len(x) < 3, string_list))
print(result)

print("---------------Exercise 3---------------")

random_list = ["abc" , 13 , True]
#print(sorted(random_list))
#TypeError: '<' not supported between instances of 'int' and 'str'
print("---------------Exercise 4---------------")

number_list = [1,122,33, 85 ,1 ,103 ,111, 100,71]
def last_digit(number):
    return number % 10
sorted_numbers = sorted(number_list, key = last_digit) # ,reverse = True
print(sorted_numbers)

print("---------------Exercise 5---------------")

multiplied_numbers = functools.reduce(lambda x,y: x*y, number_list)
print(multiplied_numbers)

print("---------------Exercise 6---------------")

power_three = list(map(lambda x: x**3, number_list))
print(power_three)

print("---------------Exercise 7---------------")
def prime (x):
    if x < 2:
        return False
    if x == 2:
        return True
    if x % 2 == 0:
        return False
    i = 3
    while i * i <= x:
        if x % i == 0:
            return False
        i += 2
    return True

only_prime = list(filter(prime, number_list))
print(only_prime)
print()
print("=========================   PART II =============================")
print()
print("---------------Exercise 1a---------------")
nr_a = 123456
digit_list = []
def build_list_even_digits(number):
    if number:
        if number% 2 == 0:
            digit_list.append(number%10)
        build_list_even_digits(number//10)

build_list_even_digits(nr_a)
print(digit_list)
digit_list.reverse()
print(digit_list)

print("---------------Exercise 1b---------------")
nr_b  = 123456
digit_list_b = []
def build_list_digits_by_condition(number, condition):
    if number:
        if condition(number%10):
            digit_list_b.append(number%10)
        build_list_digits_by_condition(number//10, condition)

build_list_digits_by_condition(nr_b, prime)
print(digit_list_b)

print("---------------Exercise 1c---------------")
digits_1c = [4,3,3,7,8,9]
def construct_number_direct(digits, condition):
    number = 0
    for digit in digits:
        if condition(digit):
            number  = number * 10 + digit
    return number

print(construct_number_direct(digits_1c, lambda x : x % 3 == 0))

def construct_number_recursive(digits, condition, number):
    if len(digits) == 0 :
        return number
    if condition(digits[0]):
        number = number * 10 + digits[0]
    return construct_number_recursive(digits[1:], condition, number)

print(construct_number_recursive(digits_1c, lambda x : x % 3 != 0, 0))

def construct_number_filter_and_reduce(digits, condition):
    filtered_digits = list(filter(condition, digits))
    number = functools.reduce(lambda x,y: x*10 + y, filtered_digits , 0)
    return number
print(construct_number_filter_and_reduce(digits_1c, lambda x : x%2 == 0))

print("---------------Exercise 2----------------")

def fromto(start, end, divisor):
    divisible = []
    quotient = start // divisor
    if(start % divisor == 0) :
        first_value = start
    else :
        first_value = (quotient + 1) * divisor
    if(first_value > end) :
         return []
    current_value = first_value

    while(current_value <= end):
        divisible.append(current_value)
        current_value += divisor
    return divisible

print(fromto(0,10,5))

print("---------------Exercise 3a---------------")
def nth(list, index):
    return list[index]
number_list = [1,122,33, 85 ,1 ,103 ,111, 100,71]
print("number list",number_list)
print("nth:",nth(number_list, 2))

print("---------------Exercise 3b---------------")
def firstn(list, index):
    return list[:index]
print("first n",firstn(number_list, 2))

print("---------------Exercise 5a---------------")

def my_filter(list, condition):
    result = functools.reduce(lambda acc, elem : acc + [elem] if condition(elem) else acc,    list,   [])
    return result

print(my_filter(number_list, lambda x : x % 3 == 0))


print("---------------Exercise 5b---------------")

def my_exists(list, condition):
    for element in list:
        if condition(element):
            return True
    return False


print(my_exists(number_list, lambda x : x % 9 == 0))

print("---------------Exercise 6a---------------")

def count(list, condition):
    count  = functools.reduce(lambda acc, elem : acc + 1 if condition(elem) else acc, list, 0)
    return count

print("Count:",count(number_list, lambda x : x % 5 == 0))


print("---------------Exercise 6b---------------")
def sum(list, condition):
    sum = functools.reduce(lambda acc, elem : acc + elem if condition(elem) else acc, list, 0)
    return sum
print("Sum:", sum(number_list, lambda x : x % 5 == 0))

print("---------------Exercise 7----------------")

def split (list_of_pairs):
    pair1 = []
    pair2 = []
    for element in list_of_pairs:
        pair1.append(element[0])
        pair2.append(element[1])
    return (pair1, pair2)

list_pairs = [(1,2),(3,4),(5,6)]
print(split(list_pairs))
def combine (pair_of_lists):
    list1 = pair_of_lists[0]
    list2 = pair_of_lists[1]
    result = []
    for i in range(0, len(list1)):
        result.append((list1[i] , list2[i]))

    return result

pair_lists = ([1,2,3],[4,5,6])
print("Combine:", combine (pair_lists))

print("---------------Exercise 8----------------")

def partition(function, list1):
    list_satisfy = list(filter(lambda x: function(x) == 1, list1))
    list_not_satisfy = list(filter(lambda x: function(x) == 0, list1))
    return [list_satisfy, list_not_satisfy]
print(list(partition(lambda x : x >= 100 , number_list)))

print("---------------Exercise 9----------------")

def digits_to_number(digits):
    number = 0
    for digit in digits:
        number = number * 10 + digit
    return number

print("---------------Exercise 10----------------")
same_number =  [ 1,1,1,2,2,4,5,6,8,8]

def eliminate_duplicates(list_number):
    new_list = []
    return list(functools.reduce(lambda new_list, x : new_list if (new_list and  new_list[-1] == x) else new_list + [x] , same_number,[]))

print(eliminate_duplicates(number_list))


print("---------------Exercise 11----------------")

def compare (list1, list2):
    if (len(list1) < len(list2)):
        return -1
    elif (len(list1) > len(list2)):
        return 1
    else:
        for i in range(len(list1)):
            if list1[i] != list2[i]:
                if(list1[i] < list2[i]):
                    return -1
                else:
                    return 1
    return 0

print(compare(number_list[:3], number_list))

print("---------------Exercise 12----------------")
def merge_sort(list1, list2):
    result = []
    i = 0
    j = 0
    while(i  < len(list1) and j < len(list2)):
        if list1[i] <= list2[j]:
            result.append(list1[i])
            i += 1
        else:
            result.append(list2[j])
            j += 1
    while i < len(list1):
        result.append(list1[i])
        i += 1
    while j < len(list2):
        result.append(list2[j])
        j += 1
    return result

print("Merge sort:", merge_sort( [1,2,5,7,10],[2,3,4,8,12,14] ))

print("---------------Exercise 13----------------")

def split_alternating(list):
    list1 = []
    list2 = []
    for i in range(0,len(list)):
        if(i%2 == 0):
            list1.append(list[i])
        else:
            list2.append(list[i])
    return (list1, list2)
print(split_alternating([1,2,3,4,5,6,8,10]))

print("---------------Exercise 14----------------")

