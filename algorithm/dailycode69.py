
def maxnum_of_three(lst):
    if len(lst) <= 3:
        return lst[0]*lst[1]*lst[2]
    lst.sort()
    num1 = lst[0]*lst[1]*lst[-1]
    num2 = lst[-1]*lst[-2]*lst[-3]
    return max(num1, num2)

def maxnum_of_three2(lst):
    min2 = [lst[0], lst[1]]
    max3 = [lst[-3], lst[-2], lst[-1]]
    for i in range(2, len(lst)-1):
        if lst[i] < lst[0]:
            min2[0], min2[1] = lst[i], min2[0]
        elif lst[i] < lst[1]:
            min2[1] = lst[i]

if __name__ == "__main__":
    lst = [-10, -2, 5, 10, 10]
    print(maxnum_of_three(lst))
