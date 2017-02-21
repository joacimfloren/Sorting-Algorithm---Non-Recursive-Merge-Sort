#include "stdafx.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

void Merge(float * v, int start, int mid, int end, float * temp) {
    int left = start, right = mid + 1, k = start;

    while (left <= mid && right <= end)
    {
        if (v[left] <= v[right]) {
            temp[k] = v[left];
            left++;
        }

        else {
            temp[k] = v[right];
            right++;
        }

        k++;
    }

    while (left <= mid) {
        temp[k] = v[left];
        left++;
        k++;
    }

    while (right <= end) {
        temp[k] = v[right];
        right++;
        k++;
    }
}

void main() {
    srand(time(NULL));

    int size = 1024;
    float * v = new float[size];

    cout << "-------------- Unsorted float array --------------" << endl;
    
    for (int i = 0; i < size; ++i) {
        v[i] = (float)rand() / ((float)RAND_MAX / 100);
        cout << v[i] << endl;
    }
    
    cout << "--------------  Sorted float array  --------------" << endl;
    
    float * temp = new float[size];

    for (int runWidth = 1; runWidth < size; runWidth = 2 * runWidth)
    {
        for (int eachRunStart = 0; eachRunStart < size; eachRunStart = eachRunStart + 2 * runWidth)
        {
            int start = eachRunStart;
            int mid = min(eachRunStart + (runWidth - 1), size - 1);
            int end = min(eachRunStart + ((2 * runWidth) - 1), size - 1);

            Merge(v, start, mid, end, temp);
        }

        for (int i = 0; i < size; i++)
            v[i] = temp[i];
    }

    for (int i = 0; i < size; i++)
        cout << v[i] << endl;

    delete[] temp;
    delete[] v;
}