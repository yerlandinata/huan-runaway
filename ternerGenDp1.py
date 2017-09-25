dp = [0 for i in range(1001)]

dp[0] = 0
dp[1] = 0
dp[2] = 2

MOD = 2 ** 16

def modMul(a, b):
    return a * b
    # return ((a % MOD) * (b % MOD)) % MOD

def modAdd(a, b):
    return a + b
    # return ((a % MOD) + (b % MOD)) % MOD

def modSub(a, b):
    return a - b
    # return ((a % MOD) - (b % MOD)) % MOD

for i in range(3, 1001):
    dp[i] = (modSub( modMul(5, dp[i - 1]),  modAdd( modMul(5, dp[i - 2]), modMul(3, dp[i - 3])     )   )) % MOD

n = int(input())
print(dp[n])