// Find the sum of digits of a number until the sum becomes a single digit.

// For example, if the input number is 3333, then the sum of digits is 3+3+3+3=12, and then the sum of digits of 12 is 1+2=3, which is a single digit. So the output will be 3.

// #include <iostream>
// #include<vector>
// #include<string>
// using namespace std;

// int main() {
//     int n=1234;
//     int sum = 0;
//     while(n%10!=n){
//         int sum=0;
//         while(n>0){
//             int r = n%10;
//             n /= 10;
//             sum += r;
//         }
//         n=sum;
//     }
    
//     cout<<n;
    
//     return 0;
// }



// But it can be optimized 

#include <iostream>
using namespace std;

int main() {
    int n=1234;
    int sum = 0;
    while(n>0 || sum>9){
        if(n==0){
            n=sum;
            sum=0;
        }
        sum += n%10;
        n /= 10;
    }
    
    cout<<sum;
    
    return 0;
}

// time complexity : O(log n) because we are dividing the number by 10 in each iteration of the while loop.
// space complexity : O(1) because we are not using any extra space to store the result of the sum of digits of the number.

// Digital root of a number can be found using the formula: digital_root(n) = 1 + (n - 1) % 9, which gives the same result as the above code but in O(1) time complexity.

// int digitalRoot(int n) {
//     if(n == 0) return 0;
//     return 1 + (n - 1) % 9;
// }