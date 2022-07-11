N = 6

def melon_area(directions, lengths):
    verticals = [lengths[i] for i in range(N) if directions[i] < 3]
    horizontals = [lengths[i] for i in range(N) if directions[i] >= 3]
    
    if {lengths[0], lengths[1]} == {max(verticals), max(horizontals)} or {lengths[3], lengths[4]} == {max(verticals), max(horizontals)}:
        areas = [lengths[0] * lengths[1], lengths[3] * lengths[4]]
        return max(areas) - min(areas)
    else:
        return lengths[0] * lengths[1] + lengths[3] * lengths[4]

K = int(input())

directions = [0 for _ in range(N)]
lengths = [0 for _ in range(N)]

for i in range(N):
    directions[i], lengths[i] = map(int, input().split())

print(melon_area(directions, lengths) * K)