def gcd(a, b):
    
    while b != 0 :
        a, b = b, a%b
        
    return a

if __name__ == "__main__":
    a, b = [int(x) for x in input().split(" ")]
    print(gcd(a, b))
