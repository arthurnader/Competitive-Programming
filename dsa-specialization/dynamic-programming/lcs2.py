def lcs2(first_sequence, second_sequence):
    
    dp = [[0]*(len(second_sequence)+1) for _ in range(len(first_sequence)+1)]
    
    for j in range(1, len(first_sequence)+1):
        for i in range(1, len(second_sequence)+1):
            
            if second_sequence[i-1] == first_sequence[j-1]:
                dp[j][i] = dp[j-1][i-1]+1
                
            else:
                dp[j][i] = max(dp[j][i-1],  dp[j-1][i])
       
    return dp[-1][-1]

if __name__ == '__main__':
    n = int(input())
    a = [int(x) for x in input().split(" ")]

    m = int(input())
    b = [int(x) for x in input().split(" ")]

    print(lcs2(a, b))