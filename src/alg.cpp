// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int cnt1 = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i; j < len; j ++) {
      if ((arr[i] + arr[j]) == value)
        cnt1 += 1;
    }
  }
  return cnt1;
}

int countPairs2(int *arr, int len, int value) {
  int cnt2 = 0;
  int l = 0;
  int r = len - 1;
  while (arr[r] > value)
    r--;
  for (int i = 0; i < len; i++) {
    for (int j = r; j > i; j--) {
      if ((arr[i] + arr[j]) == value)
        cnt2 += 1;
    }
  }
  return cnt2;
}

int binar(int* arr, int len, int value) {
  int cntbin = 0;
  int index1 = 0;
  int index2 = len - 1;
  while (index1 <= index2) {
    int center = index1 + (index2 - index1) / 2;
    if (arr[center] == value) {
      cntbin += 1;
      int l = center - 1;
      while (l >= 0 && arr[l] == value) {
        cntbin += 1;
        l -= 1;
      }
      int r = center + 1;
      while (r < len && arr[r] == value) {
        cntbin += 1;
        r += 1;
      }
      return cntbin;
    } else if (arr[center] < value) {
      index1 = center + 1;
    } else {
      index2 = center - 1;
    }
}
return 0;
}

int countPairs3(int *arr, int len, int value) {
  int cnt3 = 0;
  for (int i = 0; i < len; i++) {
    cnt3 += binar(&arr[i + 1], len - i - 1, value - arr[i]);
  }
  return cnt3;
}
