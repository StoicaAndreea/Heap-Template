// Template Heap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Heap.h"
using namespace std;


bool isPrime(int num) {
    bool flag = true;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            flag = false;
            break;
        }
    }
    return flag;
}

void kMinMax(int arr[], int n, int k, int& mins, int& minp, int& maxs, int& maxp) {
    mins = 0;
    minp = 1;
    maxs = 0;
    maxp = 1;
    int i = 0;
    int min = 0;
    int max = 0;
    int nr = k;
    while (i < k) {
        if (isPrime(arr[i]) and isPrime(arr[n - i - 1])) { k++; }
        else {
            if (!isPrime(arr[i]) and isPrime(arr[n - i - 1]) and min < nr) {
                mins += arr[i];
                minp *= arr[i];
                min++;
                k++;
            }
            else {
                if (!isPrime(arr[n - i - 1]) and isPrime(arr[i]) and max < nr)
                {
                    maxs += arr[n - i - 1];
                    maxp *= arr[n - i - 1];
                    max++;
                    k++;
                }
                else {
                    if (!isPrime(arr[n - i - 1]) and !isPrime(arr[i])) {
                        if (min < nr) {
                            mins += arr[i];
                            minp *= arr[i];
                            min++;
                        }
                        if (max < nr) {
                            maxs += arr[n - i - 1];
                            maxp *= arr[n - i - 1];
                            max++;
                        }
                        //k++;
                    }
                }
            }

        }
        i++;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    // 1. Construirea vectorului de sortat si a heap-ului asociat
    const int NumarElemente = 6;
    int elemente[] = { 2, 5, 6, 8, 10, 11 };
    Heap<int> heap(elemente, NumarElemente);
    // 2. Obtinerea si afisarea vectorului sortat
    int* elementeSortate = new int[NumarElemente];
    heap.SorteazaHeap(elementeSortate);
    for (int i = 0; i < NumarElemente; i++)
    {
        cout << elementeSortate[i] << " ";
    }
    cout << endl;
    int mins = 0;
    int minp = 0;
    int maxs = 0;
    int maxp = 0;
    int k = 2;
    printArray(elementeSortate, NumarElemente);
    kMinMax(elementeSortate, NumarElemente, k, mins, minp, maxs, maxp);
    cout << "min sum: " << mins << endl;
    cout << "max sum: " << maxs << endl;
    cout << "min prod: " << minp << endl;
    cout << "max prod: " << maxp << endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
