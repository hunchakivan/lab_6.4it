#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>

using namespace std;

void inputArray(double* a, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Введіть елемент " << i + 1 << ": "; cin >> a[i];
    }
}

void Print(double* r, const int size) {
    for (int i = 0; i < size; i++)
        cout << setw(4) << r[i] << " ";
    cout << endl;
}

double findMaxElement(double* a, int size) {
    double maxElement = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] > maxElement) {
            maxElement = a[i];
        }
    }
    return maxElement;
}

double sumElementsBeforeLastPositive(double* a, int size) {
    double sum = 0;
    int lastPositiveIndex = -1;
    for (int i = 0; i < size; i++) {
        if (a[i] > 0) {
            lastPositiveIndex = i;
        }
        if (lastPositiveIndex == -1) {
            sum += a[i];
        }
    }
    return sum;
}

void compressArray(double* a, int& size, double a_val, double b_val) {
    int writeIndex = 0;
    for (int readIndex = 0; readIndex < size; readIndex++) {
        if (abs(a[readIndex]) < a_val || abs(a[readIndex]) > b_val) {
            a[writeIndex] = a[readIndex];
            writeIndex++;
        }
    }

    while (writeIndex < size) {
        a[writeIndex] = 0;
        writeIndex++;
    }

    size = writeIndex;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size;
    double a_val, b_val;

    cout << "Розмір масиву: "; cin >> size;
    double* a = new double[size];

    inputArray(a, size);
    Print(a, size);

    double maxElement = findMaxElement(a, size);
    cout << "1.1. Максимальний елемент у масиві: " << maxElement << endl;

    double sumBeforeLastPositive = sumElementsBeforeLastPositive(a, size);
    cout << "1.2. Сума елементів масиву, розташованих до останнього додатного елементу: " << sumBeforeLastPositive << endl;

    cout << "a = "; cin >> a_val;
    cout << "b = "; cin >> b_val;

    compressArray(a, size, a_val, b_val);

    cout << "2. Стиснутий масив: ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    delete[] a;

    return 0;
}