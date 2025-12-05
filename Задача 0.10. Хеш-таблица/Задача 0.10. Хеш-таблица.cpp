#include <fstream>
#include <iostream>
#include <vector>

using namespace std;    

int main()
{
    ofstream out("output.txt");
    ifstream in("input.txt");

    int m, c, n;
    in >> m >> c >> n;
    vector<long long> hesh(m, -1); 

    vector<long long> keys(n);
    for (int i = 0; i < n; i++) {
        in >> keys[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int ind = ((keys[i] % m) + c * j) % m;
            if (hesh[ind] == -1) {
                hesh[ind] = keys[i];
                break;
            }
            else if (hesh[ind] == keys[i]) {
                break;
            }
        }
    }

    for (int i = 0; i < m; i++) {
      out << hesh[i] << " ";
    }

    return 0;
}


