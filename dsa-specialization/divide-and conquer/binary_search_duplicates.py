def binary_search(keys, query):
    
    left = 0
    right = len(keys)-1
    ans =-1
    
    while left <= right:
        
        mid = (left + right)//2
        
        if keys[mid] == query:
            ans = mid
            right = mid -1
            
        elif keys[mid] > query:
            right = mid-1
            
        else:
            left = mid+1
            
    return ans



if __name__ == '__main__':
    num_keys = int(input())
    input_keys = [int(x) for x in input().split(" ")]

    num_queries = int(input())
    input_queries = [int(x) for x in input().split(" ")]

    for q in input_queries:
        print(binary_search(input_keys, q), end=' ')