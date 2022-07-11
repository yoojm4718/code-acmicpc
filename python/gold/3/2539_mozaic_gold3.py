def parametric_search(n, m, paper_num, miss_num, miss, max_h):
    low = max_h
    high = min(n, m)
    
    while low < high:
        mid = (low + high) // 2
        
        cnt = 0
        start = 0
        while start < miss_num:
            cnt += 1
            x, y = miss[start][1], 1
            
            covered = start
            
            while covered < miss_num and x <= miss[covered][1] < x + mid and y <= miss[covered][0] < y + mid: covered += 1
            
            start = covered
        
        if cnt <= paper_num:
            high = mid
        else:
            low = mid + 1
        
    return high

n, m = map(int, input().split())
paper_num = int(input())
miss_num = int(input())
miss = []
max_h = 0
for i in range(miss_num):
    miss.append(list(map(int, input().split())))
    max_h = max(max_h, miss[i][0])

print(parametric_search(n, m, paper_num, miss_num, sorted(miss, key=lambda x: x[1]), max_h))