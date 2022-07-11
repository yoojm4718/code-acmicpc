N = 5

def color_result(color):
    result = {}
    
    for i in range(5):
        cnt = 1
        if color[i] in result.keys(): continue
        
        for j in range(i + 1, 5):
            if color[j] == color[i]: cnt += 1
            
        if cnt > 1: result[color[i]] = cnt
    
    return result

def num_result(num):
    result = {}
    
    for i in range(5):
        cnt = 1
        if num[i] in result.keys(): continue
        
        for j in range(i + 1, 5):
            if num[j] == num[i]: cnt += 1
            
        if cnt > 1: result[num[i]] = cnt
    
    return result

def num_continuous(num):
    return sorted(num) == list(range(min(num), max(num) + 1))

def score_result(color, num):
    color_dict = color_result(color)
    num_dict = num_result(num)
    is_continuous = num_continuous(num)
    
    color_values_list = list(color_dict.values())
    num_keys_list = list(num_dict.keys())
    num_values_list = list(num_dict.values())
    
    if 5 in color_values_list and is_continuous:
        return 900 + max(num)
    if 4 in num_values_list:
        return 800 + num_keys_list[num_values_list.index(4)]
    if sum(num_values_list) == 5:
        return 700 + 10 * num_keys_list[num_values_list.index(3)] + num_keys_list[num_values_list.index(2)]
    if 5 in color_values_list:
        return 600 + max(num)
    if is_continuous:
        return 500 + max(num)
    if 3 in num_values_list:
        return 400 + num_keys_list[num_values_list.index(3)]
    if sum(num_values_list) == 4:
        return 300 + 10 * max(num_keys_list) + min(num_keys_list)
    if 2 in num_values_list:
        return 200 + num_keys_list[num_values_list.index(2)]
    return 100 + max(num)

color = []
num = []

for i in range(N):
    temp_color, temp_num = input().split()
    color.append(temp_color)
    num.append(int(temp_num))

print(score_result(color, num))