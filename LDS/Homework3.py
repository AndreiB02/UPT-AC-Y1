from itertools import count

print("---------------Exercise 1---------------")
def arithmeticProgression(n):
    if n==0:
        return 2
    else:
        return 2*arithmeticProgression(n-1) - 3

print(arithmeticProgression(4))


print("---------------Exercise 2---------------")
def fibonacci(n):
    if n==0:
        return 0
    if n==1:
        return 1
    else:
        return fibonacci(n-1)+fibonacci(n-2)

print(fibonacci(6))
print("---------------Exercise 3---------------")
#first N, including 0  -> first 4: 0,1,2,3
def sumFirstN(n):
    if n==0:
        return 0
    else:
        return n-1+sumFirstN(n-1)
print(sumFirstN(4))


print("---------------Exercise 4 a)---------------")
def productDigits(n):
    if n<0 :
        n=-n
    if abs(n)<1:
        return 1
    else:
        return n%10*productDigits(n//10)

print(productDigits(3456))

print("---------------Exercise 4 b)---------------")
def countDigits(n):
    if n<0 :
        n=-n
    if n<1:
        return 0
    else:
        return 1 + countDigits(n//10)

print(countDigits(632132))

print("---------------Exercise 4 c)---------------")

def maxDigit(n):
    if n<0 :
        n=-n
    if n<1:
        return -1
    else:
        return max(n%10, maxDigit(n//10))

print(maxDigit(758))

print("---------------Exercise 4 d)---------------")

def numberOfEvenDigits(n):
    if n<0 :
        n=-n
    if n < 10:
        if n % 2 == 0:
            return 1
        else:
            return 0
    else:
        if(n % 2 == 0):
            return 1 + numberOfEvenDigits(n//10)
        else:
            return numberOfEvenDigits(n//10)

print(numberOfEvenDigits(2448))

print("---------------Exercise 5 ---------------")

def exponential(n ,a):
    if n==0:
        return 1
    else:
        return a*exponential(n-1 ,a)

print(exponential(3 ,4))

print("---------------Exercise 6 ---------------")


def primeRecursive(n,d):
    if n<2 or n % 2 == 0:
        return False
    if( n == 2 ):
        return True
    if( n == d ) :
        return True
    if(n % d == 0):
        return False
    else:
        return primeRecursive(n,d+1)

print(primeRecursive(25,2))

print("---------------Exercise 7 ---------------")

def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)
print(gcd(12,15))

print("---------------Exercise 8 ---------------")

def my_reverse(s):
    if len(s) == 0:
        return s
    else:
        return my_reverse(s[1:]) + s[0]

print(my_reverse("hello"))

print("---------------Exercise 9 ---------------")

def interval(min_value, max_value):
    if min_value == max_value:
        print(min_value)
    else:
        print(min_value)
        return interval(min_value + 1, max_value)

#interval(10,34)

print("---------------Exercise 10 a)---------------")

def checkDigit(number, digit):
    if number < 10:
        if number == digit:
            return True
        else:
            return False
    else:
        return number % 10 == digit or checkDigit(number//10, digit)

print(checkDigit(123, 3))

print("---------------Exercise 10 b)---------------")
def countDigitOccurrence(number, digit):
    if number < 10:
        if number == digit:
            return 1
        else:
            return 0
    else:
        if number % 10 == digit:
            return 1  + countDigitOccurrence(number // 10, digit)
        else:
            return countDigitOccurrence(number // 10, digit)

print(countDigitOccurrence(23123, 2))

print("---------------Exercise 11 ---------------")

def checkPalindrome(number ,lenght ,palindrome, copy_number):
    if lenght == countDigits(palindrome):
        if copy_number == palindrome:
            return True
        else:
            return False
    else:
        palindrome  = palindrome * 10 + number%10
        return checkPalindrome(number//10,   lenght ,palindrome ,copy_number)

# 12  1
#  1  12
#  0  121
number  = 12221
print(countDigits(number))
print(checkPalindrome(number, countDigits(number) ,0 , number))
