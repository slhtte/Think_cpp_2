void mult(int a[rows][cols], int x[cols], int y[cols]) {
  for (int i = 0; i < rows; ++i) {
      y[i] = 0;
      for (int j = 0; j < cols; ++j)
        y[i] += a[i][j]*x[j];
  }
}