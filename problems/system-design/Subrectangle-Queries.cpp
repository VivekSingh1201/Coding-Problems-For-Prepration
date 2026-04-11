// Subrectangle Queries

// Implement the class SubrectangleQueries which receives a rows x cols rectangle as a matrix of integers in the constructor and supports two methods:

// 1. updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)
// Updates all values with newValue in the subrectangle whose upper left coordinate is (row1,col1) and bottom right coordinate is (row2,col2).
// 2. getValue(int row, int col)

// Returns the current value of the coordinate (row,col) from the rectangle.

#include <iostream>
#include <vector>

using namespace std;

class SubrectangleQueries {
    vector<vector<int>> grid;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        grid = rectangle;
    }

    void updateSubrectangle(int r1, int c1, int r2, int c2, int newVal) {
        for (int r = r1; r <= r2; r++)
            for (int c = c1; c <= c2; c++)
                grid[r][c] = newVal;
    }

    int getValue(int row, int col) {
        return grid[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */

int main() {
    vector<vector<int>> rectangle = {{1, 2, 1}, {4, 3, 4}, {3, 2, 1}, {1, 1, 1}};
    SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
    cout << obj->getValue(0, 2) << endl; // Output: 1
    obj->updateSubrectangle(0, 0, 3, 2, 5);
    cout << obj->getValue(0, 2) << endl; // Output: 5
    cout << obj->getValue(3, 1) << endl; // Output: 5
    obj->updateSubrectangle(3, 0, 3, 2, 10);
    cout << obj->getValue(3, 1) << endl; // Output: 10
    return 0;
}

