

def func(dict, sen):
    lists = [[]]
    _func(dict, sen, lists)
    return lists

def _func(dict, sen, lists):
    if (len(sen) == 0):
        lists = [[]]

    for i in range(len(sen)+1):
        prefix, suffix = sen[:i], sen[i:]
        print(prefix, " ", suffix)
        if prefix in dict:
            rest = [[]]
            _func(dict, suffix, rest)
            print("prefix ", prefix, " rest ", rest)
            if len(rest) > 0:
                for j in range(len(rest)):
                    rest[j] = [prefix] + rest[j]
                    lists.extend(rest[j])

if __name__ == "__main__":
    #sen = 'thequickbrownfox'
    #dict = {'quick':True, 'brown':True, 'the':True, 'fox':True}
    sen = 'bedbathandbeyond'
    dict = {'bed':True, 'bath':True, 'bedbath':True,'and':True,'beyond':True}
    results = func(dict, sen)
    print(results)
