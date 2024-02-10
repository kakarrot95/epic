import numpy as np
iter  = 1000000
cnt = 0
for i in range(iter):
    s1 = np.random.normal(0.5, 0.02, 1000).sum()
    s2 = np.random.normal(0.5, 0.02, 1000).sum()
    if(abs(s1-s2)>2):
        cnt+=1


print(cnt/iter * 1000)
