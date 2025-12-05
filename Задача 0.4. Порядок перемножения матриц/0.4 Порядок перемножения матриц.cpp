// 0.4 Порядок перемножения матриц.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream in("input.txt");

    int s;
    in >> s;
    vector<int> sizes(s + 1);

    in >> sizes[0] >> sizes[1];

    int j = 0;
    for (int i = 2; i < s + 1; i++) {
        int a;
        in >> a;
        in >> sizes[i];        
    }

    vector<vector<long long>> dp(s + 1, vector<long long>(s + 1, 0));
    

    for (int length = 2; length <= s; length++) {
        for (int i = 0; i <= s - length; i++) {
            int j = i + length - 1;
            dp[i][j] = numeric_limits<long long>::max();
            for (int k = i; k < j; k++) {
                long long q = dp[i][k] + dp[k + 1][j] + sizes[i] * sizes[k + 1] * sizes[j + 1];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }

    ofstream out("output.txt");

    out << dp[0][s - 1];

    out.close();
    in.close();
    return 0;
}

