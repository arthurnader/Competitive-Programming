def change(money):
    
    coins_10 = money//10
    money = money%10
    
    coins_5 = money//5
    money = coins_10 + coins_5 + money%5

    return money

if __name__ == '__main__':
    m = int(input())
    print(change(m))