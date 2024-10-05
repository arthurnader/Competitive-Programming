def maximum_gold(capacity, weights):

    dp = [[0]*(capacity+1) for _ in range(len(weights))]
    
    for j in range(capacity+1):
        if j - weights[0] >= 0:
            dp[0][j] = weights[0]
    
    for i in range(1, len(weights)):
        for weight in range(capacity+1):
            if weight-weights[i] >=0:
                dp[i][weight] = max(dp[i-1][weight], dp[i-1][weight-weights[i]]+weights[i])
            else:
                dp[i][weight] = dp[i-1][weight]
    
    return dp[-1][-1]


if __name__ == '__main__':
    input_capacity, n = [int(x) for x in input().split(" ")]
    input_weights = [int(x) for x in input().split(" ")]

    print(maximum_gold(input_capacity, input_weights))