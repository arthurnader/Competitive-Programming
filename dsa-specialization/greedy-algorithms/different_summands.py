def optimal_summands(n):
    summands = []
    already_taken = set()
    
    if n == 2:
        return 1, [2]
    
    i = 1
    while n != 0:
        
        if n - i not in already_taken:
            summands.append(i)
            already_taken.add(i)
            n = n-i
        
        i+=1
        
    
    return len(summands), summands

if __name__ == '__main__':
    n = int(input())
    k, summands = optimal_summands(n)
    print(k)
    print(*summands)