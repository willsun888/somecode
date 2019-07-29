
## filter(function, iterable)
## return: iterable object

def test_compact():
    def compact(lst):
        return list(filter(bool, lst))

    # output: [ 1, 2, 3, 'a', 's', 34 ]
    print(compact([0, 1, False, 2, '', 3, 'a', 's', 34]))

def test_function():
    def is_odd(n):
        return n % 2 == 1

    tmplist = filter(is_odd, [1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
    print(tmplist)  # output: <filter object at 0x10c8f1a20>, filter返回迭代器对象
    newlist = list(tmplist) # 通过list转换为列表
    print(newlist)  # output: [1, 3, 5, 7, 9]

if __name__ == "__main__":
    test_compact()
    test_function()
