// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int l = 0, r = len - 1;
  while (l < r - 1) {
    int m = (r + l) / 2;
    if (arr[m] <= value)
      l = m + 1;
    else
    r = m;
  }
  len = r;
  for (int i = 0; i < len; i++) {
    for (int j = len; j > i; j--) {
      if (arr[i] + arr[j] > value) continue;
      if (arr[i] + arr[j] < value) break;
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;

  for (int i = 0; i < len - 1; i++) {
    int num = value - arr[i];
    int l = i + 1, r = len - 1;
    while (l < r) {
      int m = (l + r) / 2;
      if (arr[m] < num)
        l = m + 1;
      else
        r = m;
    }
    if (arr[l] == num) {
      while (arr[l] == num) {
        count++;
        l++;
      }
    }
  }
  return count;
}
