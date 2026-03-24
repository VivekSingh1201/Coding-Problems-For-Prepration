// Image Rotation by 90 degrees
// Given a square matrix, return the transpose of the matrix. The transpose of a matrix is obtained by swapping the rows and columns of the matrix. For example, the transpose of the matrix [[1,2,3],[4,5,6],[7,8,9]] is [[1,4,7],[2,5,8],[3,6,9]].

// #include <iostream>
// using namespace std;

// int main() {
    
//     int arr[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
//     int res[4][4];
    
//     for(int i=0;i<4;i++){
//         for(int j=0;j<4;j++){
//             res[j][4-i-1]=arr[i][j];
//         }
//     }
    
//     for(int i=0;i<4;i++){
//         for(int j=0;j<4;j++){
//             cout<<res[i][j]<<' ';
//         }
//         cout<<endl;
//     }
    
//     return 0;
// }

// time complexity : O(n^2) because we are traversing the matrix twice, once to find the transpose and once to print the transpose. Space complexity : O(n^2) because we are using an extra matrix to store the transpose of the original matrix.


// Optimal approach : We can rotate the matrix in place by first transposing the matrix and then reversing each row of the transposed matrix. This way we can achieve the same result without using extra space.
#include <iostream>
using namespace std;

vector<vector<int>> rotate90(vector<vector<int>>& arr) {
    int n = arr.size();
    vector<vector<int>> res(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[j][n - i - 1] = arr[i][j];

    return res;
}

void print(vector<vector<int>>& mat) {
    for (auto& row : mat) {
        for (int x : row) cout << x << ' ';
        cout << '\n';
    }
}

int main() {
    vector<vector<int>> arr = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9,  10, 11, 12},
        {13, 14, 15, 16}
    };

    auto res = rotate90(arr);
    print(res);
    return 0;
}



// ## Dry Run — 3×3 for clarity, `n=3`
// ```
// arr = { {1,2,3},
//         {4,5,6},
//         {7,8,9} }

// Formula: res[j][n-i-1] = arr[i][j]

// i=0,j=0: res[0][2] = 1
// i=0,j=1: res[1][2] = 2
// i=0,j=2: res[2][2] = 3

// i=1,j=0: res[0][1] = 4
// i=1,j=1: res[1][1] = 5
// i=1,j=2: res[2][1] = 6

// i=2,j=0: res[0][0] = 7
// i=2,j=1: res[1][0] = 8
// i=2,j=2: res[2][0] = 9

// res = { {7, 4, 1},
//         {8, 5, 2},
//         {9, 6, 3} }  ✅




// Optimal in-place approach : Transpose the matrix and then reverse each row to get the rotated matrix without using extra space.

// void rotate90InPlace(vector<vector<int>>& mat) {
//     int n = mat.size();

//     // Step 1: Transpose
//     for (int i = 0; i < n; i++)
//         for (int j = i + 1; j < n; j++)
//             swap(mat[i][j], mat[j][i]);

//     // Step 2: Reverse each row
//     for (int i = 0; i < n; i++)
//         reverse(mat[i].begin(), mat[i].end());
// }
// ```
// ```
// Original:          After Transpose:    After Row Reverse:
// 1  2  3            1  4  7             7  4  1
// 4  5  6    →       2  5  8      →      8  5  2
// 7  8  9            3  6  9             9  6  3  ✅