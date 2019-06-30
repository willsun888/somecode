
def get_maxsum(lst):
    curr, curr_max = lst[0], lst[0]
    for elem in lst[1:]:
        curr = max(elem, curr+elem)
        curr_max = max(curr, curr_max)

    return max(curr, curr_max)

def max_of_three(x, y, z):
    m = x
    if y > m:
        m = y
    if z > m:
        m = z
    return m

def get_maxsum2(i, lst):
    if i == len(lst)-1:
        return lst[i]
    if lst[i] < 0:
        return max(lst[i], get_maxsum2(i+1, lst))        
    return max_of_three(lst[i], get_maxsum2(i+1, lst), lst[i]+get_maxsum2(i+1, lst))

if __name__ == "__main__":
    lst = [34, -50, 42, 14, -5, 86]
    # lst = [-9, -4, -1, -3]
    print(get_maxsum2(0, lst))
