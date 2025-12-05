#include <iostream>
#include <vector>

using namespace std; 

int main()
{
    int n;
    cin >> n;

    int* arr = new int[n];
    long long* dp = new long long[n];
    int* wayStep = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = -1;
        wayStep[i] = -1;
    }
    
    dp[0] = arr[0];
    if (n > 2) { 
        dp[2] = arr[0] + arr[2]; 
        wayStep[2] = 0; 
    }
    if (n > 3) { 
        dp[3] = arr[0] + arr[3]; 
        wayStep[3] = 0; 
    } 

    for (int i = 2; i < n; i++) {
        long long res1 = -1, res2 = -1;
        if (i >= 2) {
            res1 = dp[i - 2];
        }
        if (i >= 3) {
            res2 = dp[i - 3];
        }

        if (res1 > res2 && res1 != -1) {
            dp[i] = arr[i] + res1;
            wayStep[i] = i - 2;
        }
        else if (res2 != - 1) {
            dp[i] = arr[i] + res2; 
            wayStep[i] = i - 3;
        }

    }

    int pos = n - 1;
    cout << dp[pos] << endl; 

    if (dp[pos] == -1) {
        delete[] arr;
        delete[] dp;
        delete[] wayStep;
        return 0;
    }

    vector<int> way;
    
    while (pos != -1) {
        way.push_back(pos + 1);
        pos = wayStep[pos];
    }
    
   for (int i = way.size() - 1; i >= 0; i--) {
        cout << way[i] << " ";
   }

    cout << endl;

    delete[] arr;
    delete[] dp;
    delete[] wayStep;

    return 0;
}

