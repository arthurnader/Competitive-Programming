def aux_partition3(values, target1, target2, target3, index, lookup = None):
    
    lookup = {} if lookup is None else lookup
    
    if (target1, target2, target3) in lookup:
        return lookup[(target1, target2, target3)]
    
    if target1 == target2 == target3 == 0:
        return 1
    
    elif index >= len(values) or target1<0 or target2<0 or target3<0:
        return 0
    
    res1 = aux_partition3(values, target1-values[index], target2, target3, index + 1, lookup)
    res2 = aux_partition3(values, target1, target2-values[index], target3, index + 1, lookup)
    res3 = aux_partition3(values, target1, target2, target3-values[index], index + 1, lookup)
    
    lookup[(target1, target2, target3)] = res1 or res2 or res3
    return lookup[(target1, target2, target3)]

def partition3(values):
    
    total = sum(values)
    
    if total%3 != 0:
        return 0
    
    target = total//3 
    
    return aux_partition3(values, target, target, target, 0)

if __name__ == '__main__':
    input_n = int(input())
    input_values = [int(x) for x in input().split(" ")]
    
    print(partition3(input_values))