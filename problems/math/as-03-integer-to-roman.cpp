// Integer to Roman


#include <iostream>
#include <string>
#include <vector>
using namespace std;

string toRoman(int num) {
    vector<pair<int,string>> vals = {
        {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},
        {100,"C"}, {90,"XC"},{50,"L"}, {40,"XL"},
        {10,"X"},  {9,"IX"}, {5,"V"},  {4,"IV"},{1,"I"}
    };

    string result = "";
    // Iterate through the values and symbols in the vector.
    for (auto& [val, sym] : vals) {
        // While the number is greater than or equal to the current value, append the symbol to the result and subtract the value from the number.
        // esspecially for cases like 1993, which is MCMXCIII (1000 + 900 + 90 + 1 + 1 + 1).
        while(num >= val) {
            result += sym;
            num -= val;
        }
    }
    return result;
}

int main() {
    int num = 1993;
    string roman = toRoman(num);
    cout << roman; // Output: MCMXCIII
    return 0;
}

//Time complexity: O(n), where n is the number of symbols in the Roman numeral representation. In practice, this is a constant time operation since the number of symbols is limited.
//Space complexity: O(1), since the space used for the result string is proportional to the number of symbols in the Roman numeral representation, which is limited and does not grow with the input number.