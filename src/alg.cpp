// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int cnt1 = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i; j < len; j ++) {
      if ((arr[i] + arr[j] == value) && (arr[i] >= 0 && arr[j] >= 0)) {
        cnt1 += 1;
      }
    }
  }
  return cnt1;
}

int countPairs2(int *arr, int len, int value) {
  int cnt2 = 0;
  int r = len - 1;
  while (arr[r] > value)
    r--;
  for (int i = 0; i < r; i++) {
    for (int j = r; j > i; j--) {
      if ((arr[i] + arr[j] == value) && (arr[i] >= 0 && arr[j] >= 0)) {
        cnt2 += 1;
      } else if (arr[i] + arr[j] < value) {
        break;
      }
    }
  }
  return cnt2;
}

int countPairs3(int *arr, int len, int value) {
  int cnt3 = 0;
  for (int i = 0; i < len; i++) {
    int l = i;
    int r = len;
    while (l < r - 1) {
      int centre = (r + l) / 2;
      if (arr[i] + arr[centre] == value) {
        cnt3 += 1;
        int temp = centre - 1;
        while ((arr[i] + arr[temp] == value) && (temp > l)) {
          cnt3++;
          temp--;
        }
        break;
      } else if (arr[i] + arr[centre] > value) {
        r = centre;
      } else {
        l = centre;
      }
    }
  }
  return cnt3;
}
