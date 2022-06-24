for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (mat[i][k] + mat[k][j] < mat[i][j])
                mat[i][j] = mat[j][i] = mat[i][k] + mat[k][j];

