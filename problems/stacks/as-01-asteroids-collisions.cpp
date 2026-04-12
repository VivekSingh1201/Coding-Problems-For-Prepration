// Asteroid Collision

// We are given an array asteroids of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.
// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

// Example 4:

// Input: asteroids = [3,5,-6,2,-1,4]​​​​​​​
// Output: [-6,2,4]
// Explanation: The asteroid -6 makes the asteroid 3 and 5 explode, and then continues going left.
// On the other side, the asteroid 2 makes the asteroid -1 explode and then continues going right, without reaching asteroid 4.

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> st;

    for (int a : asteroids)
    {
        bool alive = true;

        while (alive && a < 0 && !st.empty() && st.top() > 0)
        {
            if (st.top() < abs(a))
            {
                st.pop();
            }
            else if (st.top() == abs(a))
            {
                st.pop();
                alive = false;
            }
            else
            {
                alive = false;
            }
        }

        if (alive)
            st.push(a);
    }

    vector<int> res(st.size());
    for (int i = st.size() - 1; i >= 0; i--)
    {
        res[i] = st.top();
        st.pop();
    }
    return res;
}

int main()
{
    vector<int> asteroids = {3, 5, -6, 2, -1, 4};
    vector<int> res = asteroidCollision(asteroids);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}

// time complexity: O(n)
// space complexity: O(n)