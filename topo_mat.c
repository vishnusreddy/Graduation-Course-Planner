#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
    int i, j, k, m, n = 4, am[10][10], y[10], z[10], c = 0; //CodeWithC.com am= adjacency matrix
    clrscr();
    printf("ENTER THE ADJACENT MATRIX\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &am[i][j]);

    for (i = 0; i < n; i++)
    {
        y[i] = 0;
        z[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            y[i] = y[i] + am[j][i];
        }
        printf("\n%d\n", y[i]);
    }
    clrscr();
    printf("THE ENTERED MATRIX IS\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d", am[i][j]);
        }
        printf("\n");
    }
    printf("THE TOPOLOGY SORTED IS\n");
    while (c <= n)
    {
        for (k = 0; k < n; k++)
        {
            if ((y[k] == 0) && (z[k] == 0))
            {
                printf("\n%d\n", k);
                z[k] = 1;
                for (i = 0; i < n; i++)
                {
                    if (am[k][i] == 1)
                        am[k][i] = am[k][i] - 1;
                }
                for (i = 0; i < n; i++)
                {
                    y[i] = 0;
                }

                for (m = 0; m < n; m++)
                {
                    for (j = 0; j < n; j++)
                    {
                        y[m] = y[m] + am[j][m];
                    }
                }
            }
        }
        c++;
    }
    getch();
}
