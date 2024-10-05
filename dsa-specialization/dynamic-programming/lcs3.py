def lcs3(first_sequence, second_sequence, third_sequence):
    
    dp = [[[0]*(len(third_sequence)+1) for _ in range(len(second_sequence)+1)] for _ in range(len(first_sequence)+1)]
    
    
    for i in range(1, len(first_sequence)+1):
        for j in range(1, len(second_sequence)+1):
            for k in range(1, len(third_sequence)+1):
                
                if first_sequence[i-1] == second_sequence[j-1] == third_sequence[k-1]:
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1
                else:
                    dp[i][j][k] = max(dp[i][j][k-1], dp[i][j-1][k], dp[i-1][j][k])
                    
    return dp[-1][-1][-1]


if __name__ == '__main__':
    n = int(input())
    a = [int(x) for x in input().split(" ")]

    m = int(input())
    b = [int(x) for x in input().split(" ")]

    q = int(input())
    c = [int(x) for x in input().split(" ")]

    print(lcs3(a, b, c))