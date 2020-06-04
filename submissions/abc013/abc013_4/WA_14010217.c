#include <stdio.h>
#include <stdlib.h>
#define si(x) scanf("%d", &x);
int main()
{
    int n, m, d;
    si(n);
    si(m);
    si(d);

    int a[m];
    int i, j;
    for (int i = 0; i < m; i++)
    {
        si(a[i]);
        a[i]--;
    }
    int order[30][n];
    int cur[n];

    for (i = 0; i < n; i++)
    {
        order[0][i] = i;
        cur[i] = i;
    }

    for (i = m - 1; i >= 0; i--)
    {
        int tmp = order[0][a[i]];
        order[0][a[i]] = order[0][a[i] + 1];
        order[0][a[i] + 1] = tmp;
    }
    for (i = 0; i < 30 - 1; i++)
    {
        for (j = 0; j < n; j++)
        {
            order[i + 1][j] = order[i][order[i][j]];
        }
    }
    i = 0;
    while (d != 0)
    {
        if (d % 2 == 1)
        {
            int tmp[n];
            for (j = 0; j < n; j++)
            {
                tmp[j] = cur[j];
            }
            for (j = 0; j < n; j++)
            {
                   cur[order[i][tmp[j]]] = j;      }
        }
        d /= 2;
        i++;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d\n", cur[i] + 1);
    }

    return 0;
}
