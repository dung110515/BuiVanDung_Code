#include <stdio.h>
#include <stdlib.h>

double det(double A[3][3]) {
    return A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) -
           A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0]) +
           A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
}

void giaihpt3x3(double A[3][3], double B[3], double* x) {
    double detA = det(A);

    double A0[3][3] = {{B[0], A[0][1], A[0][2]},
                       {B[1], A[1][1], A[1][2]},
                       {B[2], A[2][1], A[2][2]}};

    double A1[3][3] = {{A[0][0], B[0], A[0][2]},
                       {A[1][0], B[1], A[1][2]},
                       {A[2][0], B[2], A[2][2]}};

    double A2[3][3] = {{A[0][0], A[0][1], B[0]},
                       {A[1][0], A[1][1], B[1]},
                       {A[2][0], A[2][1], B[2]}};

    double detA0 = det(A0);
    double detA1 = det(A1);
    double detA2 = det(A2);

    x[0] = detA0 / detA;
    x[1] = detA1 / detA;
    x[2] = detA2 / detA;
}

int main() {
    double Sx = 0.0, Sxx = 0.0, Sxxx = 0.0, Sxxxx = 0.0;
    double Sy = 0.0, Sxy = 0.0, Sx2y = 0.0;
    double x[30], y[30];
    int n;

    printf("Nhap so luong phan tu x: \t");
    scanf("%d", &n);

    printf("Nhap cac cap phan tu  ( x y ): \n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i] ); 
    }

    

    for (int i = 0; i < n; i++) {
        Sx += x[i];
        Sxx += x[i] * x[i];
        Sxxx += x[i] * x[i] * x[i];
        Sxxxx += x[i] * x[i] * x[i] * x[i];
        Sy += y[i];
        Sxy += x[i] * y[i];
        Sx2y += x[i] * x[i] * y[i];
    }

    double arrA[3][3] = {
        {n, Sx, Sxx},
        {Sx, Sxx, Sxxx},
        {Sxx, Sxxx, Sxxxx}
    };

    double arrB[3] = {Sy, Sxy, Sx2y};
    double ketqua[3];

    giaihpt3x3(arrA, arrB, ketqua);

    printf("Ket qua la: y = %.4lf + %.4lf*x + %.4lf*x^2\n",
           ketqua[0], ketqua[1], ketqua[2]);

    return 0;
}
