   for (int i = temp.size() - 1; i >= 1; i--) {
    for (int j = 0; j < i; j++) {
      if (temp[j] > temp[j + 1])
        swap(temp[j], temp[j + 1]);
    }
  }