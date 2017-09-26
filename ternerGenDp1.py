dp = [0 for i in range(100005)]

dp[0] = 0
dp[1] = 0
dp[2] = 2

MOD = (10 ** 9) + 7

def modMul(a, b):
    return a * b
    # return ((a % MOD) * (b % MOD)) % MOD

def modAdd(a, b):
    return a + b
    # return ((a % MOD) + (b % MOD)) % MOD

def modSub(a, b):
    return a - b
    # return ((a % MOD) - (b % MOD)) % MOD

for i in range(3, 100005):
    dp[i] = (modSub( modMul(5, dp[i - 1]),  modAdd( modMul(5, dp[i - 2]), modMul(3, dp[i - 3])     )   )) % MOD

t = int(input())
for i in range(t):
    n = int(input())
    print(dp[n])