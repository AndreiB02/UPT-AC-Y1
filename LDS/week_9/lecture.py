d = {
    1: "one",
    2: "two",
    3: "three",
}

import functools as ft

#swap key and value

def ex(d):
    def f(acc, elem):
        k,v  = elem
        acc[v] = k
        return acc
    return ft.reduce(f,list(d.items()),{ })

res = ex(d)
# print(res)

def ex2(d,res = {}):
    def rec(L):
        if(L != []):
            res[L[0][1]] = L[0][0]
            rec(L[1:])
    rec(list(d.items()))
    return res
res = ex2(d)
print(res)