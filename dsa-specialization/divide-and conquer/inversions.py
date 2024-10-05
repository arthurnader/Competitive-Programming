def inversions(elements):
    
    def merge(l1, l2):
        sorted_list = []
        inversions = 0
        index_1 = 0
        index_2 = 0
        
        while index_1 < len(l1) and index_2 < len(l2):
            
            if l1[index_1] <= l2[index_2]:
                sorted_list.append(l1[index_1])
                index_1 += 1
                
            else:
                sorted_list.append(l2[index_2])
                index_2 += 1
                inversions += len(l1)-index_1
    
        sorted_list += l1[index_1:]
        sorted_list += l2[index_2:]
    
        return sorted_list, inversions
    
    
    def mergesort(elements, start, end):
        
        if start == end:
            return [elements[start]], 0
        
        mid = (start + end)//2

        elements_1, left_inv = mergesort(elements, start, mid)
        elements_2, right_inv = mergesort(elements, mid+1, end)
        sorted_elements, split_inv = merge(elements_1, elements_2)

        total_inversions = left_inv + right_inv + split_inv
        
        return sorted_elements, total_inversions
    
    sort_list, number_of_inversions = mergesort(elements, 0, len(elements)-1)
    
    return number_of_inversions


if __name__ == '__main__':
    input_n = int(input())
    elements = [int(x) for x in input().split(" ")]

    print(inversions(elements))