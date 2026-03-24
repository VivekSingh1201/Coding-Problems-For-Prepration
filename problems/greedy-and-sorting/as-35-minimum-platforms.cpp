// Given arrival and departure times of all trains that reach a railway station, find the minimum number of platforms required for the railway station so that no train waits. Consider that all the trains arrive and depart on the same day. 
// Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.


// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main() {
    
//     vector<int> arrival = {900,940,950,1100,1500,1800};
//     vector<int> departure = {910,1200,1120,1130,1900,2000};
//     vector<int> platforms;
    
//     int n = arrival.size();
//     int max_p = 0;
    
//     for(int i = 0; i < n; i++){
//         sort(platforms.begin(), platforms.end());
        
//         while(!platforms.empty() && platforms.back() < arrival[i]){
//             platforms.pop_back();
//         }
        
//         platforms.push_back(departure[i]);
        
//         max_p = max(max_p, (int)platforms.size());
//     }
    
//     cout << max_p;
//     return 0;
// }

// time complexity : O(n^2 log n) because we are sorting the platforms vector in each iteration.
// space complexity : O(n) because in worst case, we may need n platforms.






// Optimal approach : 
// Sort the arrival and departure times separately and then use two pointers to find the maximum number of platforms needed at any time.
  

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    vector<int> arrival = {900,940,950,1100,1500,1800};
    vector<int> departure = {910,1200,1120,1130,1900,2000};
    
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    
    int n = arrival.size();
    int curr = 0, max_p;
    int i=0, j=0;
    
    while(i<n && j<n){
        if(arrival[i] <= departure[j]){
            curr++;
            max_p=max(curr,max_p);
            i++;
        }
        else{
            curr--;
            j++;
        }
    }
    
    cout << max_p<<endl;
    return 0;
}

// time complexity : O(n log n) because we are sorting the arrival and departure arrays.
// space complexity : O(1) because we are using constant extra space.