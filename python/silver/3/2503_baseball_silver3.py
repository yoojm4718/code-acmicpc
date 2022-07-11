from itertools import permutations

def input_guess(N):
    guess = []

    for _ in range(N):
        info = {}
        num, S, B = input().split()
        info["num"] = [int(_) for _ in list(num)]
        info["S"] = int(S)
        info["B"] = int(B)
        guess.append(info)
    
    return guess

def baseball(guess, cases):
    for info in guess:
        num, S, B = tuple(info.values())
        rmv = 0
        
        for i in range(len(cases)):
            S_cnt = 0
            B_cnt = 0
            i -= rmv
            
            for j in range(3):
                if num[j] == cases[i][j]: S_cnt += 1
                elif num[j] in cases[i]: B_cnt += 1
        
            if S != S_cnt or B != B_cnt:
                rmv += 1
                cases.remove(cases[i])
    
    return cases

cases = list(permutations([1, 2, 3, 4, 5, 6, 7, 8, 9], 3))

N = int(input())
guess = input_guess(N)
result = baseball(guess, cases)

print(len(result))