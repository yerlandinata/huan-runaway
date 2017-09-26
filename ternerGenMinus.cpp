#include <bits/stdc++.h>

using namespace std;

const long long int MOD = 1000000007;

long long int modMul(long long int a, long long int b){
    return ((a % MOD) * (b % MOD)) % MOD;
}

long long int modAdd(long long int a, long long int b){
    return ((a % MOD) + (b % MOD)) % MOD;
}

long long int modSub(long long int a, long long int b){
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

int main(){
    int t;
    cin >> t;
    int inputs[105], sortedInputs[105];
    int n;
    for(int i = 0; i < t; i++){
        cin >> n;
        inputs[i] = n;
        sortedInputs[i] = n;
    }

    sort(sortedInputs, sortedInputs+t);

    int pointer = 0;
    unordered_map<int, long long> ans;

    long long int x1 = 2;
    long long int x2 = 0;
    long long int x3 = 0;
    long long int temp;
    for(int i = 3; i <= sortedInputs[t - 1]; i++){
        temp = x1;
        x1 = (modSub( modMul(5, x1),  modAdd( modMul(5, x2), modMul(3, x3)     )   )) % MOD;
        if (i == sortedInputs[pointer]) ans[sortedInputs[pointer++]] = x1;
        x3 = x2;
        x2 = temp;
    }
    for(int i = 0; i < t; i++){
        cout << ans[inputs[i]] << endl;
    }
}