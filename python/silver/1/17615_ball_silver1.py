def check_balls(balls, color):
    for _ in range(len(balls)):
        check = balls.pop()
        if check != color:
            balls.append(check)
            break
    
    return balls.count(color)

N = int(input())
balls = list(input())

print(min(check_balls(balls[:], "R"), check_balls(balls[::-1], "R"), check_balls(balls[:], "B"), check_balls(balls[::-1], "B")))