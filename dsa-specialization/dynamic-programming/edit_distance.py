def edit_distance(first_string, second_string):
    
    dp = [[0] * (len(second_string) + 1) for _ in range(len(first_string) + 1)]
    
    for i in range(1, len(second_string) + 1):
        dp[0][i] = i
        
    for j in range(1, len(first_string) + 1):
        dp[j][0] = j
        
    for j in range(1, len(first_string)+1):
        for i in range(1, len(second_string)+1):
            
            if second_string[i-1] == first_string[j-1]:
                dp[j][i] = dp[j-1][i-1]
            else:
                dp[j][i] = min(dp[j-1][i-1], dp[j-1][i], dp[j][i-1]) + 1
    
    return dp[-1][-1]


if __name__ == "__main__":
    print(edit_distance(input(), input()))