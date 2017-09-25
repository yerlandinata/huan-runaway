#include <bits/stdc++.h>

using namespace std;

// const unsigned int MOD = 1000000007;

// unsigned int modMul(unsigned int a, unsigned int b){
//     unsigned int res = 0;
//     while (a != 0) {
//         if (a & 1) res = (res + b) % MOD;
//         a >>= 1;
//         b = (b << 1) % MOD;
//     }
//     return res;
// }

// unsigned int modAdd(unsigned int a, unsigned int b){
//     return ((a % MOD) + (b % MOD)) % MOD;
// }

// unsigned int modSub(unsigned int a, unsigned int b){
//     return ((a % MOD) - (b % MOD)) % MOD;
// }

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

    unsigned int x1 = 2;
    unsigned int x2 = 0;
    unsigned int x3 = 0;
    unsigned int temp;
    // auto t1 = chrono::high_resolution_clock::now();
    for(int i = 3; i <= sortedInputs[t - 1]; i++){
        temp = x1;
        // x1 = (modSub( modMul(5, x1),  modAdd( modMul(5, x2), modMul(3, x3)     )   )) % MOD;
        x1 = 5 * x1 - 5 * x2 - 3 * x3;
        if (i == sortedInputs[pointer]) ans[sortedInputs[pointer++]] = x1;
        x3 = x2;
        x2 = temp;
    }
    // auto t2 = chrono::high_resolution_clock::now();
    // chrono::duration<int64_t,nano> elapsed = t2 - t1;
    for(int i = 0; i < t; i++){
        cout << ans[inputs[i]] << endl;
    }
    // cout << "Runtime: " << elapsed.count() / 1000000.0 << " ms\n";
}