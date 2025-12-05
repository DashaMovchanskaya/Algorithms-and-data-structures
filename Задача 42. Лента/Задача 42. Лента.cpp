// Задача 42. Лента.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Задана лента шириной в одну клетку и длиной в n клеток. На каждой клетке написано некоторое целое число. 
// Играют два игрока, которые ходят поочерёдно. За один ход игрок отрезает от ленты одну из крайних клеток и забирает её. 
// Игра останавливается, когда лента заканчивается. Выигрыш игрока равен сумме чисел на находящихся у него клетках ленты. 
// Необходимо определить величину выигрыша, которую может себе гарантировать игрок, начинающий игру первым.
// (Это тот размер выигрыша, который первый игрок обеспечит себе при любой игре второго игрока.)

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int sizeOfWin(int begin, int end, const vector <int>& numbers, bool first, int** memo) {
   
    if (first) {
        if (begin == end) {
            return numbers[end];
        }
        if (memo[begin + 1][end] == -1) {
            memo[begin + 1][end] = sizeOfWin(begin + 1, end, numbers, false, memo);
        }
        if (memo[begin][end - 1] == -1) {
            memo[begin][end - 1] = sizeOfWin(begin, end - 1, numbers, false, memo);
        }
        int left = numbers[begin] + memo[begin + 1][end];
        int right = numbers[end] + memo[begin][end - 1];
        if (left > right) {
            return left;
        }
        else {
            return right;
        }
    }
    else {
        if (begin == end) {
            return 0;
        }
        if (memo[begin + 1][end] == -1) {
            memo[begin + 1][end] = sizeOfWin(begin + 1, end, numbers, true, memo);
        }
        if (memo[begin][end - 1] == -1) {
            memo[begin][end - 1] = sizeOfWin(begin, end - 1, numbers, true, memo);
        }
        int left = memo[begin + 1][end];
        int right = memo[begin][end - 1];
        if (left < right) {
            return left;
        }
        else {
            return right;
        }
    }
    
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin.is_open() || !fout.is_open()) {
        cout << "Файл не открыт.";
    }

    vector<int> numbers;
    int size;
    fin >> size;
    numbers.resize(size);
    for (int i = 0; i < size; i++) {
        fin >> numbers[i];
    }

    int** memo = new int* [size];
    for (int i = 0; i < size; i++) {
        memo[i] = new int[size];
        for (int j = 0; j < size; j++) {
            memo[i][j] = -1;
        }
    }

    int begin = 0;
    int end = size - 1;
    fout << sizeOfWin(begin, end, numbers, true, memo);

    for (int i = 0; i < size; i++) {
        delete[] memo[i];
    }

    delete[] memo;

    return 0;
}

