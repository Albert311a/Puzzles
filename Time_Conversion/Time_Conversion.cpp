#include <iostream>
#include <string>

std::string timeConversion(std::string s) {
    std::string sh = s, out;
    int hour;
    if( sh[ 8 ] == 'P' ){
        hour = stoi( sh.substr( 0, 2 ) );
        if( hour < 12 )
            hour += 12;
        sh.erase( 8, 2 );
        sh.replace( 0, 2, std::to_string( hour ) );
    }
    if( sh[ 8 ] == 'A' ){
        if( sh[ 0 ] == '1' && sh[ 1 ] == '2'){
            std::string k = "00";
            sh.replace( 0, 2, k );
        }
        sh.erase( 8, 2 );
    }
    return sh;
}

int main() {
    std::string s;
    std::cin >> s;
    std::string result = timeConversion(s);
    std::cout << result << std::endl;
    return 0;
}

