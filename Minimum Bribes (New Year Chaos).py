def minimumBribes(q):
    minBribes = 0
    n = len(q)
    
    for i in range(n - 1, -1, -1):
        if q[i] - (i + 1) > 2:
            print("Too chaotic")
            return
        # Fixed the range here:
        for j in range(max(0, q[i] - 2), i):
            if q[j] > q[i]:
                minBribes += 1
                
    print(minBribes)