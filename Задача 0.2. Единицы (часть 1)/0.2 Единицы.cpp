#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long long combination(int n, int k, long long** memo) {
    if (k == n || k == 0) {
        return 1;
    }
    if (memo[n][k] == -1) {
        memo[n][k] = (combination(n - 1, k, memo) + combination(n - 1, k - 1, memo)) % 1000000007;
    }
    return memo[n][k];
}

int main()
{
    int n, k;
    cin >> n;
    cin >> k;

    long long** memo = new long long*[n + 1];
    for (int i = 0; i <= n; i++) {
        memo[i] = new long long [k + 1];
        for (int j = 0; j <= k; j++) {
            memo[i][j] = -1;
        }
    }

    long long result = combination(n, k, memo); 
    cout << result; 

    for (int i = 0; i <= n; i++) {
        delete[] memo[i];
    }
    delete[] memo;
    return 0;
}


