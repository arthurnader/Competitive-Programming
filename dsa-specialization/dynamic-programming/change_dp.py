def change(money):
    
    dp = [float('inf')]*(money+1)
    dp[0] = 0
    
    for i in range(1, money+1):
        for coin in [1,3,4]:
            if i - coin >= 0:
                dp[i] = min(dp[i], dp[i-coin] + 1)
    
    return dp[-1]


if __name__ == '__main__':
    m = int(input())
    print(change(m))