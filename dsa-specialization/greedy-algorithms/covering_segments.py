def optimal_points(segments):
    points = []
    
    segments.sort(key=lambda x: x[1])
    current_point = segments[0][1]
    points.append(current_point)
    
    for s in segments:
        
        if current_point < s[0]: 
            current_point = s[1]
            points.append(current_point)
    
    return len(points), points

if __name__ == '__main__':
    n = int(input())
    segments = []
    
    for i in range(n):
        data = input().split(" ")
        segments.append((int(data[0]), int(data[1])))
    
    num_points, points = optimal_points(segments)
    print(num_points)
    print(*points)