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



    /* 
    https://codegolf.stackexchange.com/questions/241219/mat-printing-matrix 
    */ 

    void fill_first_char(char **mat, int width, int height, char sign)
    {
        int p = 0, q = 0;
        bool flag = true ;
        while (p < width / 2 || q < height / 2)
        {
            for (int i = p; i < width - p && p < height; i++)
            {
                mat[i][q] = sign;
                mat[i][height - q - 1] = sign;
            }
            for (int i = q; i < height - q  && q < width; i++)
            {

                mat[p][i] = sign;
                mat[width - p - 1][i] = sign;
            }
            p += 2;
            q += 2;
        }
        if(width == height && width % 4 == 1){
            mat[width/2][width/2]=sign;
        }
    }

    void allocate_mat(char **mat, int width, int height)
    {
        char *MAT_DATA = new char[width * height];
        cout << "size is " << width *height << endl ; 
        for (int i = 0; i < width; i++)
        {
            mat[i] = MAT_DATA + i * height;
        }
    }


    string make_carpet(char **mat , int width , int height )
    { 
    string t ="" ; 
   for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                t = t + mat[i][j]; 
            }
            t = t + "\n";
        }
    return t ; 

    }

    

    string mat(int width, int height, char first, char second)
    {
        if (width * height % 2 == 0 )
        {
            throw runtime_error("carpet shoud be odd ! ");
           
        }
        if (first == second){ 
            throw runtime_error("the same char "); 
        }
        if (first < 33 || second < 33 ){ 
            throw runtime_error("invalid char"); 
        }
        if (width < 0 || height < 0 ){ 
            throw runtime_error("you cannot use negative numbers !"); 
        }


        int temp = width;
        width = height;
        height = temp;
        char **Matrix;
        Matrix = new char *[width];

        allocate_mat(Matrix, width, height);
        fill_second_char(Matrix, width, height, second);
        fill_first_char(Matrix, width, height, first);
        string resulat = make_carpet(Matrix,width,height);
        delete [] Matrix[0];
        delete [] Matrix;

        return resulat;
    }
}