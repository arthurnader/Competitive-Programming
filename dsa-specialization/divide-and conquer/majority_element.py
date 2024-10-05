def majority_element(elements):
    
    majority = elements[0]
    occurences = 1
    
    for i in range(1, len(elements)):
        if elements[i] == majority:
            occurences += 1
        else:
            occurences -=1
            
        if occurences == 0:
            majority = elements[i]
            occurences = 1
    
    return 1 if elements.count(majority) > len(elements)/2 else 0


if __name__ == '__main__':
    input_n = int(input())
    input_elements = [int(x) for x in input().split(" ")]

    print(majority_element_naive(input_elements))