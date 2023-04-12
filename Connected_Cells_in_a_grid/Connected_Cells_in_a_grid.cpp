//Consider a matrix where each cell contains either a 0 or a 1. Any cell containing a  is called a filled cell.
//Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally.
//In the following grid, all cells marked X are connected to the cell marked Y.
//
//If one or more filled cells are also connected, they form a region.
//Note that each cell in a region is connected to zero or more cells in the region but is not necessarily directly connected to all the other cells in the region.
//
//Given an n x m matrix, find and print the number of cells in the largest region in the matrix.
//Note that there may be more than one region in the matrix.
//
//For example, there are two regions in the following 3 x 3 matrix. The larger region at the top left contains 3  cells.
//The smaller one at the bottom right contains 1.
/* 110
 * 100
 * 001
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <istream>

void printv( std::vector<std::string> s ){
    for( int i = 0; i < 4; i++ ){
        std::cout << s[ i ] << std::endl;
    }
}

void print( char **ar, int n, int m ){
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < m; j++ )
            std::cout << ar[ i ][ j ];
        std::cout << std::endl;
    }
}

int calc( char **ar, int ax, int ay, int n, int m, int &cnt ){

    int X[ ] = { 1,  1,  0, -1, -1, -1, 0, 1 };
    int Y[ ] = { 0, -1, -1, -1,  0,  1, 1, 1 };

    if( '1' == ar[ ax ][ ay ] ){
        ar[ ax ][ ay ] = 'x';
        cnt++;
        for( int i = 0; i < 8; i++ ){
            int nX = ax + X[ i ];
            int nY = ay + Y[ i ];
            if(   nY >= 0 && nX >= 0 && nX < n && nY < m && '1' == ar[ nX ][ nY ]  ){
                calc( ar, nX, nY, n, m, cnt );
                }
        }
    }
    return cnt;
}


int main( ){
    int n;
    std::cin >> n;
    int m;
    std::cin >> m;

    char *ary[ n ];
    for( int a = 0; a < n; a++ )
        ary[ a] = new char[ m ];


    std::vector<std::string> v;
    std::string s;
    char c;
    for( int a = 0; a < n; a++ ){
        for( int b = 0; b < m; b++ ){
            std::cin >> c;
            ary[ a ][ b ] = c;
        }
    }



    int k = 0;
    int fin = 0;
    for( int a = 0; a < n; a++ )
        for( int b = 0; b < m; b++ ){
            k = 0;
            calc( ary, a, b, n, m, k );
            if( k > fin )
                fin = k;
        }

    std::cout << fin;
    return 0;
}
