// Задача 0.5. LCS.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int lenght;
    cin >> lenght;
    vector<int> A;
    vector<int> B;

    for (int i = 0; i < lenght; i++) {
        int n;
        cin >> n;
        A.push_back(n);
    }

    for (int i = 0; i < lenght; i++) {
        int n;
        cin >> n;
        B.push_back(n);
    }

    int** dp = new int* [lenght + 1];
    for (int i = 0; i < lenght + 1; i++) {
        dp[i] = new int [lenght + 1];
    }

    for (int i = 0; i < lenght + 1; i++) {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    vector<int> prevA;
    vector<int> prevB;

    for (int i = 0; i < lenght; i++) {
        for (int j = 0; j < lenght; j++) {
            if (A[i] == B[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
                prevA.push_back(i);
                prevB.push_back(j);
            }
            else if (dp[i + 1][j] > dp[i][j + 1]) {
                dp[i + 1][j + 1] = dp[i + 1][j];
            }
            else {
                dp[i + 1][j + 1] = dp[i][j + 1];
            }
        }
    }

    cout << dp[lenght][lenght] << endl;

    vector<int> pathA;
    vector<int> pathB;

    int i = lenght - 1, j = lenght - 1; 
    while(i >= 0 && j >= 0) {
        if (A[i] == B[j]) {
            pathA.push_back(i);
            pathB.push_back(j);
            i--;
            j--;
            if (i < 0 || j < 0) break;
        }
        if (dp[i + 1][j + 1] == dp[i][j + 1]) {
            i--;
        }
        if (dp[i + 1][j + 1] == dp[i + 1][j]) {
            j--;
        }
    }

    for (int i = pathA.size() - 1; i >= 0; i--) {
        cout << pathA[i] << " ";
    }

    cout << endl;

    for (int i = pathB.size() - 1; i >= 0; i--) {
        cout << pathB[i] << " ";
    }

    for (int i = 0; i < lenght + 1; i++) {
        delete[] dp[i];
    }
    delete[] dp;

    return 0;
}


