def min_refills(distance, tank, stops):
    
    stops.append(distance)
    available_distance = tank
    refills = 0
    last = 0
    
    i = 0
    while i != len(stops):
        
        available_distance -= stops[i]-last
        if available_distance < 0:
            return -1
        
        if i < len(stops) -1 and stops[i+1] - stops[i] > available_distance:
            available_distance = tank
            refills += 1
        
        last = stops[i]    
        i+=1
    
    return refills

if __name__ == '__main__':
    d, m, n = int(input()), int(input()),  int(input()) 
    stops = [int(x) for x in input().split(" ")]
    print(min_refills(d, m, stops))
    
  