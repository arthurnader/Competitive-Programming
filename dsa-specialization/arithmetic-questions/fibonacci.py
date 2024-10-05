def fibonacci_number(n):
    
    if n <= 1:
        return n
    
    prev = 0
    current = 1
    
    for i in range(2, n+1):
        current, prev = current+prev, current
        
    return current


if __name__ == '__main__':
    input_n = int(input())
    print(fibonacci_number(input_n))
