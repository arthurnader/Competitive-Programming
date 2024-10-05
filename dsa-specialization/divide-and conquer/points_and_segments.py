def points_cover(starts, ends, points):
    
    events = []
    intervals_count = [0]*len(points)
    
    for s in starts:
        events.append((s, 0))
        
    for p in points:
        events.append((p, 1))
        
    for e in ends:
        events.append((e, 2))

    events.sort(key=lambda x: (x[0], x[1]))
    
    point_to_index = dict()
    for i in range(len(points)):
        if points[i] in point_to_index:
            point_to_index[points[i]].append(i)
        else:
            point_to_index[points[i]] = [i]
    
    
    current_segments=0
        
    for event in events:
        
        if event[1] == 0:
            current_segments += 1
        
        elif event[1] == 2:
            current_segments -= 1
            
        else:
            idx_point = point_to_index[event[0]]
            for idx in idx_point:
                intervals_count[idx] = current_segments
        
    return intervals_count

if __name__ == '__main__':
    data = list(map(int, input().split()))
    n, m = data[0], data[1]
    input_starts, input_ends = data[2:2 * n + 2:2], data[3:2 * n + 2:2]
    input_points = data[2 * n + 2:]

    output_count = points_cover(input_starts, input_ends, input_points)
    print(*output_count)