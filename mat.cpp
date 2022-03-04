#include <iostream>
#include "mat.hpp"
using namespace std;
namespace ariel
{

    void fill_second_char(char **mat, int width, int height, char sign)
    {
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                mat[i][j] = sign;
            }
        }
    }

    void fill_first_char(char **mat, int width, int height, char sign)
    {
        int p = 0, q = 0;
        while (p < width / 2 || q < height / 2)
        {
            for (int i = p; i < width - p; i++)
            {
                mat[i][q] = sign;
                mat[i][height - q - 1] = sign;
            }
            for (int i = q; i < height - q; i++)
            {
                mat[p][i] = sign;
                mat[width - p - 1][i] = sign;
            }
            p += 2;
            q += 2;
        }
    }

    void allocate_mat(char **mat, int width, int height)
    {
        char *MAT_DATA = new char[width * height];

        for (int i = 0; i < width; i++)
        {
            mat[i] = MAT_DATA + i * height;
        }
    }

    void print_mat(char **mat, int width, int height)
    {
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                cout << mat[i][j];
            }
            cout << endl;
        }
    }

    string mat(int width, int height, char first, char second)
    {
        if (width * height % 2 == 0)
        {

            throw;

            // return "";
        }
        int temp = width;
        width = height;
        height = temp;
        char **Matrix = NULL;
        Matrix = new char *[width];

        allocate_mat(Matrix, width, height);
        fill_second_char(Matrix, width, height, second);
        fill_first_char(Matrix, width, height, first);
        print_mat(Matrix, width, height);

        for (int i = 0; i < width; i++)
        {
            delete [] Matrix[i];
        }
        delete [] Matrix;

        return "";
    }
}