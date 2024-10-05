def fibonacci_last_digit(n):

    if n <= 1:
        return n
    
    prev = 0
    current = 1
    
    for i in range(2, n+1):
        current, prev = (current+prev)%10, current
        
    return current


if __name__ == '__main__':
    n = int(input())
    print(fibonacci_last_digit(n))
