N = int(input())

words = set()

for _ in range(N): words.add(input())

words = sorted(list(words), key=lambda x: (len(x), x))

for i in words: print(i)