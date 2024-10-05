def fibonacci_partial_sum(from_, to):
    
    if to <= 1:
        return to
    
    prev = 0
    current = 1
    sum_ = 0
    
    for i in range(2, from_):
        current, prev = (current+prev)%10, current
        
    for i in range(from_, to+1):
        current, prev = (current+prev)%10, current
        sum_+= current
        sum_%=10
        
    return sum_


if __name__ == '__main__':
    from_, to = [int(x) for x in input().split(" ")]
    print(fibonacci_partial_sum(from_, to))
