#include <iostream>
#include <vector>

// In this challenge, you are required to calculate and print the sum of the elements in an array, keeping in mind that some of those integers may be quite large.
long aVeryBigSum(int n, std::vector <long> ar) {
    // Complete this function
    long sum = 0;
    for( int i = 0; i < n; i++ )
        sum += ar[ i ];
    return sum;
}


int main( int argc, char *argv[ ] ){

    int n;
    std::cin >> n;
    std::vector<long> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       std::cin >> ar[ar_i];
    }
    long result = aVeryBigSum(n, ar);
    std::cout << result << std::endl;

	return 0;
}

