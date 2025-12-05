#include <iostream>
#include <vector>

using namespace std;

long long Pow(long long n, int p) { 
    long long res = 1;
    n %= 1000000007;

    while (p > 0) {
        if (p % 2) {
            res = res * n % 1000000007;
            p--; 
        } 
        else {
            n = n * n % 1000000007; 
            p /= 2;
        }
    }

    return res;
}


int main()
{
    int n, k;
    cin >> n;
    cin >> k;

    if (k > n - k) {
        k = n - k;
    }

    if (k == n || k == 0) {
        cout << 1 << endl;
        return 0;
    }

    vector<long long> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i < n + 1; i++) {
        fact[i] = fact[i - 1] * i % 1000000007;
    }


    long long znam1 = fact[k] * fact[n - k] % 1000000007;
    long long znam2 = Pow(znam1, 1000000005);

    long long result = fact[n] * znam2 % 1000000007;

    cout << result << endl;

    return 0;
}