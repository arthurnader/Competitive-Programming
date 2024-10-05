def gcd(a, b):
    
    while b != 0 :
        a, b = b, a%b
        
    return a


def lcm(a, b):
    gcd_ = gcd(a,b)
    
    return a//gcd_*b


if __name__ == '__main__':
    a, b = [int(x) for x in input().split(" ")]
    print(lcm(a, b))

