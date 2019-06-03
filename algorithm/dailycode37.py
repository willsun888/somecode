#!/usr/bin/python3

def get_subset(lst):
    if len(lst) == 0:
        return [[]]
    sset = get_subset(lst[1:])
    return sset + [ e+[lst[0]] for e in sset ]

if __name__ == "__main__":
    lst = [1, 2, 3, 4]
    res = get_subset(lst)
    print(res)
    print(len(res))
