#!/usr/bin/python3

def get_subset(lst):
    if len(lst) == 0:
        return [[]]
    sset = get_subset(lst[1:])
    return sset + [ s+[lst[0]] for s in sset ]

if __name__ == "__main__":
    lst = [1, 2, 3, 4]
    print(get_subset(lst))

