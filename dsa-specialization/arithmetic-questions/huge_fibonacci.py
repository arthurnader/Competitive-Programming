def fibonacci_huge(n, m):

    if n <= 1:
        return n
    
    prev = 0
    current = 1
    
    for i in range(2, n+1):
        current, prev = (current+prev)%m, current
        
    return current


if __name__ == '__main__':
    n, m = [int(x) for x in input().split(" ")]
    print(fibonacci_huge(n, m))
