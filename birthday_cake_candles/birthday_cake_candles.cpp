// You are in charge of the cake for a child's birthday.
// You have decided the cake will have one candle for each year of their total age.
// They will only be able to blow out the tallest of the candles. Count how many candles are tallest.

#include <iostream>
#include <vector>

int birthdayCakeCandles(int n, std::vector <int> ar) {
    int c = 1;
    int high = ar[ 0 ];
    for( int i = 1; i < n; i++ ){
        if( ar[ i ] > high ){
            high = ar[ i ];
            c = 1;
        }else if( ar[ i ] == high ) c++;
    }
    return c;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       std::cin >> ar[ar_i];
    }
    int result = birthdayCakeCandles(n, ar);
    std::cout << result << std::endl;
    return 0;
}
