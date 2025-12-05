#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int main()
{
    ifstream in("huffman.in");
    ofstream out("huffman.out");

    long long res = 0;

    int n;
    in >> n;
    vector<long long> v(n);
    queue<long long> q1, q2;

    for (int i = 0; i < n; i++) {
        in >> v[i];
        q1.push(v[i]);
    }

    while (n > 1) {
        long long first, second;
        if (q2.empty() || (!q1.empty() && q1.front() <= q2.front())) {
            first = q1.front();
            q1.pop();
        }
        else {
            first = q2.front();
            q2.pop(); 
        }

        if (q2.empty() || (!q1.empty() && q1.front() <= q2.front())) {
            second = q1.front(); 
            q1.pop();
        }
        else {
            second = q2.front(); 
            q2.pop();
        }
        
        long long sum = first + second;
        q2.push(sum); 
        res += sum;
        n--;
    }

    out << res;

    return 0;
}

