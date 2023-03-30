// Copyright 2021 NNTU-CS
#include <algorithm>
int countPairs1(int* arr, int len, int value) {
    int k = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                k += 1;
            }
        }
    }
    return k;
}

int countPairs2(int* arr, int len, int value) {
int k = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = len - 1; i < j; --j) {
            if (arr[i] + arr[j] == value) {
                k += 1;
            }
        }
    }
  return k;
}

int countPairs3(int* arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; i++) {
    if (std::binary_search(arr + i, arr + len, value - arr[i])) {
      k += std::count(arr + i + 1, arr + len, value - arr[i]);
    }
  }
  return k;
}
