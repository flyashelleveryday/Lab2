#include <iostream>
#include <windows.h>
#include <chrono>
#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace chrono;


void bubbleSort(int* Arr, int n = 100) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if (Arr[i] > Arr[i + 1]) {
                swap(Arr[i], Arr[i + 1]);
                swapped = true;
            }
        }        
    } 
}
void shakerSort(int* Arr, int n = 100) {

    bool swapped = 1;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = 0;

        for (int i = start; i < end; i++) {
            if (Arr[i] > Arr[i + 1]) {
                swap(Arr[i], Arr[i + 1]);
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        for (int i = end - 1; i >= start; i--) {
            if (Arr[i] > Arr[i + 1]) {
                swap(Arr[i], Arr[i + 1]);
                swapped = 1;
            }
        }

        start++;
    }


}
void combSort(int* Arr, int n = 100) {

    float k = 1.247;
    int s = n - 1;
    int cout = 0;

    while (s >= 1) {
        for (int i = 0; i + s < n; i++) {
            if (Arr[i] > Arr[i + s])
                swap(Arr[i], Arr[i + s]);
        }

        s /= k;
    }

    while (true) {

        for (int j = 0; j < n - 1; j++) {
            if (Arr[j] > Arr[j + 1])
                swap(Arr[j], Arr[j + 1]);
            else
                cout++;
        }
        if (cout == n - 1)
            break;
        else
            cout = 0;
    }
}
void insertSort(int* Arr, int n = 100) {

    int i, j, key;

    for (i = 1; i < n; i++) {
        key = Arr[i];
        j = i - 1;

        while (j >= 0 && Arr[j] > key) {
            Arr[j + 1] = Arr[j];
            j = j - 1;
        }
        Arr[j + 1] = key;
    }
}
void quickSort(int* Arr, int left = 0, int right = 99) {
    if (left >= right) {
        return;
    }

    int i = left, j = right;
    int pivot = Arr[(right + left) / 2];

    while (i <= j) {
        while (Arr[i] < pivot) i++;
        while (Arr[j] > pivot) j--;

        if (i <= j) {
            swap(Arr[i], Arr[j]);
            i++;
            j--;
        }
    }
    quickSort(Arr, left, j);
    quickSort(Arr, i, right);
}
int binarySearch(int* Arr, int value, int begin, int end) {
    while (begin <= end) {
        int mid = (begin + end) / 2;

        if (Arr[mid] == value)
            return mid;

        if (Arr[mid] < value)
            begin = mid + 1;
        else
            end = mid - 1;
    }
    return 1000;
}

void writeArr(int Arr[], int n = 100) {
    for (int i = 0; i < n; i++)
        cout << Arr[i] << " ";
    cout << endl;
}

void task1(int* Arr, int* Arr2, int n = 100) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        Arr[i] = rand() % 199 - 99;
        Arr2[i] = Arr[i];
    }
    cout << endl << "Задание 1. \nМассив со случайными значениями от -99 до 99: " << endl;
    writeArr(Arr);
    cout << endl << endl;
}
void task2(int* Arr) {
    int answer;
    cout << endl << "Задание 2. Выберете сортировку: " << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Shaker Sort" << endl;
    cout << "3. Comb Sort" << endl;
    cout << "4. Insert Sort" << endl;
    cout << "5. Quick Sort" << endl;
    cout << ">";
    cin >> answer;

    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    start = steady_clock::now();
    switch (answer) {
    case 1:
        bubbleSort(Arr);
        break;
    case 2:
        shakerSort(Arr);
        break;
    case 3:
        combSort(Arr);
        break;
    case 4:
        insertSort(Arr);
        break;
    case 5:
        quickSort(Arr);
        break;
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);

    writeArr(Arr);
    cout << "Сортировка выполнена за " << result.count() << " наносекунд" << endl << endl << endl;
}
void task3(int* Arr, int* unArr, int n = 100) {
    int maxValue = Arr[0], minValue = Arr[0];
    cout << endl << "Задание 3. \nПоиск максимального и минимального значения в отсортироанном и неотсортиорванном массивах: " << endl << endl;

    //поис max, min в отсортированном массиве
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    start = steady_clock::now();
    maxValue = Arr[n - 1];
    minValue = Arr[0];
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "Максимальное значение в массиве(max) равно " << maxValue << endl << "Минимальное значение в массиве(min) равно " << minValue << endl << endl;
    cout << "В отсортированном массиве поиск max и min занял " << result.count() << " наносекунд" << endl;

    //поиск max и min в неотсортированном массиве
    maxValue = unArr[0];
    minValue = unArr[0];
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start1, end1;
    nanoseconds result1;
    start1 = steady_clock::now();
    for (int i = 1; i < n - 1; i++) {
        if (unArr[i] >= maxValue)
            maxValue = unArr[i];
        if (unArr[i] <= minValue)
            minValue = unArr[i];
    }
    end1 = steady_clock::now();
    result1 = duration_cast<nanoseconds>(end1 - start1);
    cout << "В неотсортированном массиве поиск max и min занял " << result1.count() << " наносекунд" << endl << endl;
}
void task4(int* Arr, int* unArr, int n = 100) {
    int maxValue = Arr[n - 1];
    int minValue = Arr[0];
    int cnt1 = 0, cnt2 = 0;
    int averageValue = round((minValue + maxValue) / 2);
    cout << endl << "Задание 4." << endl;
    cout << "Среднее значение максимального и минимального значения равно " << averageValue << endl << endl;


    cout << "Индексы элементов в отсортированном массиве, равных среднему значению: ";
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    start = steady_clock::now();
    for (int i = 0; Arr[i] <= averageValue && i < n; i++) {
        if (Arr[i] == averageValue) {
            cnt1++;
            cout << i << " ";
          
        }
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << endl << "Количество элементов, равных среднему значению: " << cnt1 << endl;
    cout << "Поиск значений и вывод их индексов(если они есть) в отсортированном массиве занял " << result.count() << " наносекунд" << endl << endl;


    cout << "Индексы элементов в неотсортированном массиве, равных среднему значению: ";
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start1, end1;
    nanoseconds result1;
    start1 = steady_clock::now();
    for (int j = 0; j < n; j++) {
        if (unArr[j] == averageValue) {
            cnt2++;
            cout << j << " ";
        }
    }
    end1 = steady_clock::now();
    result1 = duration_cast<nanoseconds>(end1 - start1);
    cout << endl << "Количество элементов, равных среднему значению: " << cnt2 << endl;
    cout << "Поиск значений и вывод их индексов(если они есть) в неотсортированном массиве занял " << result1.count() << " наносекунд" << endl << endl;
}
void task5(int* Arr, int n = 100) {
    int a, cnt = 0;
    cout << endl << "Задание 5. \n";
    cout << "Введите число: ";
    cin >> a;

    for (int i = 0; i < n; i++) {
        if (Arr[i] < a)
            cnt++;
    }

    cout << "Количество элементов в массиве, которые меньше числа " << a << ": " << cnt << endl << endl << endl;
}
void task6(int* Arr, int n = 100) {
    int b, cnt = 0;
    cout << endl << "Задание 6. \n";
    cout << "Введите число: ";
    cin >> b;

    for (int i = 0; i < n; i++) {
        if (Arr[i] > b)
            cnt++;
    }

    cout << "Количество элементов в массиве, которые больше числа " << b << ": " << cnt << endl << endl << endl;
}
void task7(int* Arr, int n = 100) {
    int value;
    int searchResult = 0;
    cout << endl << "Задание 7.\nВведите число: ";
    cin >> value;
    cout << endl;

    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    start = steady_clock::now();
    int binarySearchResult = binarySearch(Arr, value, 0, 99);
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);

    if (binarySearchResult == 1000)
        cout << "Введенного числа нет в массиве" << endl;
    else
        cout << "Введенное число есть в массиве" << endl;
    cout << "Время поиска числа с помощью бинарного поиска заняло: " << result.count() << " наносекунд" << endl;

    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start1, end1;
    nanoseconds result1;
    start1 = steady_clock::now();
    for (int i = 0; i < n; i++) {
        if (Arr[i] == value) {
            searchResult = 1;
            break;
        }
    }
    end1 = steady_clock::now();
    result1 = duration_cast<nanoseconds>(end1 - start1);
    if (searchResult == 0)
        cout << "Введенного числа нет в массиве" << endl;
    else
        cout << "Введенное число есть в массиве" << endl;
    cout << "Время поиска числа с помощью перебора заняло: " << result1.count() << " наносекунд" << endl << endl;
}
void task8(int* Arr) {
    int a, b;
    cout << endl << "Задание 8.\n";
    cout << "Введите индекс первого числа, которого хотите поменять: ";
    cin >> a;
    cout << "Введите индекс второго числа, которого хотите поменять: ";
    cin >> b;

    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start1, end1;
    nanoseconds result1;
    start1 = steady_clock::now();
    swap(Arr[a], Arr[b]);
    end1 = steady_clock::now();
    result1 = duration_cast<nanoseconds>(end1 - start1);
    cout << endl << "Чтобы поменять элементы местами понадобилось " << result1.count() << " наносекунд" << endl;
    writeArr(Arr);
}
void task9(int* unSortArr, int half = 50) {
    cout << "\nИДЗ (задание 3)\n";

    //разделяем неотсортированный массив на 2 массива
    int Arr1[50] = {}, Arr2[50] = {};
    int count = 0;
    for (int i = 0; i < half; i++) {
        Arr1[i] = unSortArr[i];
        Arr2[i] = unSortArr[i + half];
    }

    cout << "Первая половина массива: \n";
    writeArr(Arr1, 50);
    cout << "Вторая половина массива: \n";
    writeArr(Arr2, 50);
    system("pause");

    //меняем нечетные элементы первого массива и четные элементы второго массива
    for (int i = 1; i < half; i += 2)
        swap(Arr1[i], Arr2[i - 1]);


    cout << "\n**Поменяли значения нечетных элементов первого массива и четных элементов второго массива: \n";
    cout << "Первая половина массива: \n";
    writeArr(Arr1, 50);
    cout << "Вторая половина массива: \n";
    writeArr(Arr2, 50);
    system("pause");

    //делаем все элементы второго массива четными
    for (int i = 0; i < half; i++) {
        if (Arr2[i] % 2 != 0)
            Arr2[i] += 1;
    }

    cout << "\n**Сделали все элементы 2 массива четными: \n";
    writeArr(Arr2, 50);
    system("pause");

    //считаем сколько элементов первого массива больше второго
    for (int i = 0; i < half; i++) {
        if (Arr1[i] > Arr2[i])
            count++;
    }
    cout << "\n**В первом массиве количество элементов, которые больше, чем во втором равно: " << count << endl;

}

void printMenu(int* Arr) {
    system("cls"); // очищаем экран
    writeArr(Arr);
    cout << endl;
    cout << "Что Вы хотите сделать?" << endl;
    cout << "1. Заполнить массив случайными значениями от -99 до 99" << endl;
    cout << "2. Отсортировать массив" << endl;
    cout << "3. Найти максимальный и минимальный элементы" << endl;
    cout << "4. Определить среднее значение" << endl;
    cout << "5. Вывести количество элементов, которые меньше а" << endl;
    cout << "6. Вывести количество элементов, которые больше b" << endl;
    cout << "7. Узнать, есть ли число в массиве" << endl;
    cout << "8. Поменять элементы местами" << endl;
    cout << "9. ИДЗ" << endl;
    cout << "0. Выход из программы" << endl;
    cout << ">";
}
int getVariant() {
    int variant;
    cin >> variant;

    while ((variant < 0) || (variant > 9)) {
        cout << "Попробуйте еще раз, введено неправильное значение" << endl << ">";

        cin >> variant;
    }

    return variant;
}

int main()
{
    setlocale(0, "");
    const int n = 100;
    const int half = n / 2;
    int sortArr[n] = {}, unSortArr[n] = {}, arrForTask9[2] = {};
    int variant;
    do {

        printMenu(sortArr);
        variant = getVariant();

        switch (variant) {
        case 1:
            task1(sortArr, unSortArr);
            break;
        case 2:
            task2(sortArr);
            break;
        case 3:
            task3(sortArr, unSortArr);
            break;
        case 4:
            task4(sortArr, unSortArr);
            break;
        case 5:
            task5(sortArr);
            break;
        case 6:
            task6(sortArr);
            break;
        case 7:
            task7(sortArr);
            break;
        case 8:
            task8(sortArr);
            break;
        case 9:
            task9(unSortArr);
            break;
        }
        if (variant != 0)
            system("pause");
    } while (variant != 0);
    return 0;
}
