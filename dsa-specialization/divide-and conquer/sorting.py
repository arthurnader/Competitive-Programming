def partition3(array, left, right):
    
    m1 = left
    m2 = left
    pivot = array[left]
    
    i = left+1
    while i <= right:
        
        if array[i] == pivot:
            m2 += 1
            i += 1
            
        elif array[i] < pivot:
            array[i], array[m1] = array[m1], array[i]
            
            m1 += 1
            m2 += 1
            i += 1
            
        else:
            array[i], array[right] = array[right], array[i]
            right -= 1            
    
    return m1, m2
    

def randomized_quick_sort(array, left, right):
    if left >= right:
        return
    k = randint(left, right)
    array[left], array[k] = array[k], array[left]
    m1, m2 = partition3(array, left, right)
    randomized_quick_sort(array, left, m1 - 1)
    randomized_quick_sort(array, m2 + 1, right)
    
    
if __name__ == '__main__':
    input_n = int(input())
    elements = [int(x) for x in input().split(" ")]
    
    randomized_quick_sort(elements, 0, len(elements) - 1)
    print(*elements)