def max_dot_product(first_sequence, second_sequence):
    max_product = 0
    
    first_sequence.sort()
    second_sequence.sort()
    
    for i in range(len(first_sequence)):
        max_product += first_sequence[i]*second_sequence[i]
    
    return max_product


if __name__ == '__main__':
    n = int(input())
    prices = [int(x) for x in input().split(" ")]
    clicks = [int(x) for x in input().split(" ")]

    print(max_dot_product(prices, clicks))