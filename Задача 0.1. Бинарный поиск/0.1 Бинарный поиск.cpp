// 0.1 Бинарный поиск.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int bynarySearch(int* numbers, int n, int request, int& index1, int& index2) {
    int begin = 0, end = n - 1;
    int faund = 0;
    int middle = 0;
    while (begin <= end) {
        middle = begin + (end - begin) / 2;
        if (request == numbers[middle]) {
            faund = 1;
            break;
        }
        else if (request > numbers[middle]) {
            begin = middle + 1;
        }
        else {
            end = middle - 1;
        }
    }

    begin = 0, end = n - 1;
    while (begin <= end) {
        int middle = begin + (end - begin) / 2;
        if (request <= numbers[middle]) {
            index1 = middle; 
            end = middle - 1; 
        }
        else {
            begin = middle + 1; 
        }
    }

    begin = 0, end = n - 1;
    while (begin <= end) {
        int middle = begin + (end - begin) / 2;
        if (request < numbers[middle]) {
            index2 = middle; 
            end = middle - 1; 
        }
        else {
            begin = middle + 1; 
        }
    }
    
    return faund;
}
int main()
{
    int n;
    cin >> n;
    int* numbers = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int k;
    cin >> k;
    int* requests = new int[k];
    for (int i = 0; i < k; i++) {
        cin >> requests[i];
        int index1 = n, index2 = n;
        int faund = bynarySearch(numbers, n, requests[i], index1, index2);
        cout << faund << " " << index1 << " " << index2 << endl;
    }

    delete[] numbers;
    delete[] requests;
    return 0;
}


