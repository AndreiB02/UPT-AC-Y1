print("------Exercise 1-------")
def LastDigit(number):
    return abs(number)%10
result  = LastDigit(-42461)
print(result)

#===========================
print("------Exercise 2-------")
def MolecularMass(oxygen, hydrogen, carbon):
    return oxygen*16 + hydrogen *1 + carbon * 12

print(MolecularMass(10,5,2))

#==========================
print("------Exercise 3-------")
import math as m
def QuadraticEq(a,b,c):
    delta = b**2 - 4 * a * c
    if delta<0 :
        print("The equation has no real solutions.")
    else:
        if delta==0:
            x= (-b/2 * a)
            print("The equations has the solution x=", x)
        else :
            x1 = (-b + m.sqrt(delta))/2 * a
            x2 = (-b - m.sqrt(delta))/2 * a
            print("The solutions to the equation are:" ,x1, " and ", x2)

QuadraticEq(1, -5, -6)

 #====================
print("------Exercise 4-------")
def IsLeapYear(year):
    if year % 400 == 0:
        return True
    if year % 100 == 0:
        return False
    if year % 4 != 0 :
        return False
    return True

print(IsLeapYear(1600))
print(IsLeapYear(1700))
print(IsLeapYear(1601))
print(IsLeapYear(2024))


#====================================
print("------Exercise 5-------")
def f (x) :
    if  x < -3 :
        return 2 * x + 1
    elif  x == -3 :
        return 0
    else :
        return 3 * (x ** 2) +  6 * x - 5
    
print(f(0))
print(f(-4))
print(f(10))
print(f(-3))

#=========================
print("------Exercise 6-------")
def Interval(a,b,c):
    return c>=a and c <=b

print(Interval(1, 10, 5))
print(Interval(1, 10, 11))
print(Interval(10, 1, 5))

#=======================
print("------Exercise 7-------")
def SortDesc(a,b,c):
    return max(a,max(b,c)) ,min(max(a,b),max(b,c),max(a,c)) ,min(min(a,b),c)

print(SortDesc(1,3,2))

#========================
print("------Exercise 8-------")
def TimeToSeconds(hour,minute,second):
    return hour*60*60 + minute*60 + second
def FlightTime( arrivalTime, departureTime ):
    aHour = int(arrivalTime[0 : 2])
    aMinute = int(arrivalTime[3 : 5])
    aSecond = int(arrivalTime[6 : 8])
    # print("Arrival Hour", aHour)
    # print("Arrival Minute", aMinute)
    # print("Arrival Second", aSecond)
    dHour = int(departureTime[0 : 2])
    dMinute = int(departureTime[3 : 5])
    dSecond = int(departureTime[6 : 8])
    # print("Arrival Hour", dHour)
    # print("Arrival Minute", dMinute)
    # print("Arrival Second", dSecond)
    arrivalTimeInSeconds = TimeToSeconds(aHour,aMinute,aSecond)
    departureTimeInSeconds = TimeToSeconds(dHour, dMinute, dSecond)
    return arrivalTimeInSeconds -  departureTimeInSeconds
print("Flight time in seconds: ",FlightTime( "17:23:59", "15:20:12"))

#========================
print("------Exercise 9-------")

def LenghtAndAreaCircle(radius):
    lenght = 2*m.pi*radius
    area = m.pi*(radius**2)
    return lenght, area

print(LenghtAndAreaCircle(3))

#========================
print("------Exercise 10-------")
def NumberOfDays(year1, year2):
    days = 0
    for year in range(year1, year2 + 1):
        if IsLeapYear(year):
            days += 366
        else:
            days += 365
    return days

print(NumberOfDays(1899,2001))

