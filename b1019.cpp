#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <algorithm>
  
using namespace std;
  
int main() {
    //input
    int inputInt;
  
    cin >> inputInt;
  
    //process
    while ((inputInt != 6174)) {
        stringstream ss;
        string inputString;
        ss << inputInt;
        ss >> inputString;
        while (inputString.size() < 4) {
            inputString.append("0");
        }
  
        //sort->intLeft.intRight
        sort(inputString.begin(), inputString.end());
        int intRight = atoi(inputString.c_str());
  
        reverse(inputString.begin(), inputString.end());
        int intLeft = atoi(inputString.c_str());
  
        int result = intLeft - intRight;
  
        printf("%04d - %04d = %04d\n", intLeft, intRight, result);
        inputInt = result;
        if (result == 0) {
            return 0;
        }
    }
  
    return 0;
}
