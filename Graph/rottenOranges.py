from collections import deque

def minTimeToRot(grid, n, m):
    q = deque()
    tot = 0
    days = 0
    cnt = 0

    for i in range(n):
        for j in range(m):
            if grid[i][j] != 0:
                tot += 1
            if grid[i][j] == 2:
                q.append((i, j))

    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    while q:
        k = len(q)
        cnt += k

        while k > 0:
            x, y = q.popleft()

            for i in range(4):
                nx, ny = x + dx[i], y + dy[i]

                if nx < 0 or ny < 0 or nx >= n or ny >= m or grid[nx][ny] != 1:
                    continue

                grid[nx][ny] = 2
                q.append((nx, ny))

            k -= 1

        if q:
            days += 1

    if cnt != tot:
        return -1

    return days