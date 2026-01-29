def compare(a,b, index1,index2):
    if a==b:
        print("Arguments", index1, "and", index2, "are equal")

def distinctValues (x,y,z):
    if x==y==z:
        print("Arguments are equal")
        return 1
    elif x != y and y != z and x != z:
        print("All arguments are distinct")
        return 3
    else:
        compare(x,y,1,2) 
        compare(x,z,1,3) 
        compare(y,z,2,3)
        return 2        

print(distinctValues(2,2,2))
print(distinctValues(1,2,3))
print(distinctValues(2,3,2))

add15 = lambda x : x+15 
print( add15(20))


