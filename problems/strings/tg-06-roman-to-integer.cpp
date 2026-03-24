// Convert Roman to Integer
// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M. Each symbol has a value as follows: I is 1, V is 5, X is 10, L is 50, C is 100, D is 500 and M is 1000. For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

// Online C++ compiler to run C++ program online
// #include <iostream>
// #include<vector>
// #include<string>
// using namespace std;

// int main() {
    
//     string s="MCMIV";
//     int n=s.length();
//     int res=0;
    
//     for(int i=0;i<n;i++){
//         if(s[i]=='I'){
//             if(i+1<n && s[i+1]=='V'){
//                 res += 4;
//                 i++;
//             }
//             else if(i+1<n && s[i+1]=='X'){
//                 res +=9;
//                 i++;
//             }
//             else{
//                 res += 1;
//             }
//         }
        
//         else if(s[i]=='V'){
//             res+=5;
//         }
        
//         else if(s[i]=='X'){
//             if(i+1<n && s[i+1]=='L'){
//                 res += 40;
//                 i++;
//             }
//             else if(i+1<n && s[i+1]=='C'){
//                 res +=90;
//                 i++;
//             }
//             else{
//                 res += 10;
//             }
//         }
        
//         else if(s[i]=='L'){
//             res+=50;
//         }
        
//         else if(s[i]=='C'){
//             if(i+1<n && s[i+1]=='D'){
//                 res += 400;
//                 i++;
//             }
//             else if(i+1<n && s[i+1]=='M'){
//                 res +=900;
//                 i++;
//             }
//             else{
//                 res += 100;
//             }
//         }
//         else if(s[i]=='D'){
//             res+=500;
//         }
//         else if(s[i]=='M'){
//             res+=1000;
//         }
//     }
    
//     cout<<res<<endl;

//     return 0;
// }


// Time complexity: O(n) where n is the length of the input string.
// Space complexity: O(1) since we are using a constant amount of space to store the result and the loop variables.






//there is another way to do it although it also has same time and space complexity.

#include <iostream>
#include <string>
using namespace std;

int value(char r){
    if(r=='I') return 1;
    if(r=='V') return 5;
    if(r=='X') return 10;
    if(r=='L') return 50;
    if(r=='C') return 100;
    if(r=='D') return 500;
    if(r=='M') return 1000;
    
    return -1; // Invalid character
    
}

int main(){
    string s="MCMIV";
    int n=s.length();
    int res=0;
    
    for(int i=0;i<n;i++){
        int s1 = value(s[i]);
        
        if(i+1<n){
            int s2 = value(s[i+1]);
            
            if(s1>=s2){
                res += s1;
            }
            else{
                res += (s2 - s1);
                i++;
            }
        }
        else{
            res += s1;
        }
    }
    
    cout<<res<<endl;

    return 0;
}

// Time complexity: O(n) where n is the length of the input string.
// Space complexity: O(1) since we are using a constant amount of space to store the result and the loop variables.