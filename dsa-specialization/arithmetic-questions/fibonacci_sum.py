def fibonacci_sum(n):
    
    if n <= 1:
        return n
    
    prev = 0
    current = 1
    sum_ = 1
    
    for i in range(2, n+1):
        current, prev = (current+prev)%10, current
        sum_+= current
        sum_%=10
        
    return sum_


if __name__ == '__main__':
    n = int(input())
    print(fibonacci_sum(n))
