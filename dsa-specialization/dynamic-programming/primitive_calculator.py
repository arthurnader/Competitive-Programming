def compute_operations(n):

    lookup = [0] * (n + 1)
    prev = [0] * (n + 1)
    
    for i in range(2, n + 1):
        minus_1 = lookup[i - 1] + 1
        divide_2 = lookup[i // 2] + 1 if i % 2 == 0 else float('inf')
        divide_3 = lookup[i // 3] + 1 if i % 3 == 0 else float('inf')

        lookup[i] = min(minus_1, divide_2, divide_3)

        if lookup[i] == minus_1:
            prev[i] = i - 1
        elif lookup[i] == divide_2:
            prev[i] = i // 2
        else:
            prev[i] = i // 3

    sequence = []
    while n > 0:
        sequence.append(n)
        n = prev[n]

    sequence.reverse()
    
    return sequence


if __name__ == '__main__':
    input_n = int(input())
    output_sequence = compute_operations(input_n)
    print(len(output_sequence) - 1)
    print(*output_sequence)