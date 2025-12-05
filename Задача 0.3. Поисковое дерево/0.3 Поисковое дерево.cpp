// 0.3 Поисковое дерево.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream in("bst.in");
    ofstream out("bst.out"); 

    vector<int> key;
    vector<int> column;
    vector<char> graniza;

    int size;
    int head;

    in >> size;
    in >> head;

    key.resize(size);
    column.resize(size); 
    graniza.resize(size); 

    key[0] = head; 
    column[0] = 0;
    graniza[0] = 0;

    long long* dp[2];
    for (int i = 0; i < 2; i++) {
        dp[i] = new long long[size];
    }

    dp[0][0] = INT64_MIN;
    dp[1][0] = INT64_MAX;

    for (int i = 1; i < size; i++) {
        in >> key[i];
        in >> column[i];
        in >> graniza[i];
        column[i]--;

        if (graniza[i] == 'L') {
            dp[0][i] = dp[0][column[i]];
            dp[1][i] = key[column[i]];
            if (key[i] < dp[0][i] || key[i] >= dp[1][i]) {
                out << "NO";
                out.close(); 
                in.close(); 
                return 0;
            }
        }
        else if (graniza[i] == 'R') { 
            dp[0][i] = key[column[i]];
            dp[1][i] = dp[1][column[i]]; 
            if (key[i] < dp[0][i] || key[i] >= dp[1][i]) {
                out << "NO";
                out.close(); 
                in.close(); 
                return 0;
            }
        }
    }

    out << "YES";

    out.close();
    in.close();

    return 0;
}

