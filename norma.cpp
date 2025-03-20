#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

// Basic Input/Output for Data Structures in C++
int main() {
    // 1. Array Input/Output
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Array: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;

    // 2. Vector Input/Output
    vector<int> vec = {10, 20, 30, 40, 50};
    cout << "Vector: ";
    for (int num : vec) cout << num << " ";
    cout << endl;

    // 3. Queue Input/Output
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Queue Front: " << q.front() << " Queue Back: " << q.back() << endl;
    q.pop();
    cout << "Queue Front after pop: " << q.front() << endl;

    // 4. Stack Input/Output
    stack<int> s;
    s.push(100);
    s.push(200);
    s.push(300);
    cout << "Stack Top: " << s.top() << endl;
    s.pop();
    cout << "Stack Top after pop: " << s.top() << endl;

    // 5. Set Input/Output (Unique Elements, Sorted Order)
    set<int> st = {50, 20, 40, 10, 30};
    cout << "Set: ";
    for (int num : st) cout << num << " ";
    cout << endl;

    // 6. Map Input/Output (Key-Value Pairs)
    map<string, int> mp;
    mp["Alice"] = 25;
    mp["Bob"] = 30;
    cout << "Map: " << endl;
    for (auto &p : mp) cout << p.first << " -> " << p.second << endl;

    // 7. Sorting a Vector
    vector<int> nums = {5, 2, 8, 1, 3};
    sort(nums.begin(), nums.end());
    cout << "Sorted Vector: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}

// Step-by-Step Guide to Solving a Competitive Programming Problem

/*
1. **Read the Problem Statement Carefully**  
   - Understand what the problem is asking.
   - Identify inputs, outputs, and constraints.
   - Check for edge cases (smallest, largest, negative, empty, etc.).

2. **Break Down the Problem Requirements**  
   - What data structures may be needed? (Array, Map, Set, Graph, etc.)
   - What algorithms fit the problem? (Sorting, Binary Search, DFS/BFS, Dynamic Programming, etc.)

3. **Analyze Constraints and Choose an Optimal Approach**  
   - If n is small (≤10^3), O(n^2) solutions might work.
   - If n is large (~10^6), aim for O(n log n) or O(n).
   - If n is huge (~10^9), consider O(log n) solutions (Binary Search, Bit Manipulation).

4. **Think of a Brute Force Solution First**  
   - If stuck, try a naive solution first, even if it’s inefficient.
   - This helps in identifying a pattern or optimization strategy.

5. **Optimize Step by Step**  
   - Reduce nested loops using better data structures.
   - Use sorting, prefix sums, or binary search if applicable.
   - Apply memoization or tabulation for Dynamic Programming problems.

6. **Write a Clean, Modular Code**  
   - Use functions for repetitive tasks.
   - Write comments to make debugging easier.

7. **Test with Sample and Edge Cases**  
   - Use given test cases first.
   - Try edge cases (min/max values, empty inputs, large inputs).
   - Debug unexpected results by printing intermediate outputs.

8. **If Stuck, Try the Following:**  
   - Re-read the problem carefully; sometimes key details are missed.
   - Check constraints again; maybe an optimization is possible.
   - Think of related problems you’ve solved before.
   - If time permits, take a short break and revisit the problem with a fresh mind.

9. **After Solving, Analyze and Learn**  
   - Compare with editorial and top solutions to find better approaches.
   - Identify weaknesses (Data Structures, DP, Graphs, etc.) and practice more problems in those areas.

10. **Keep Practicing and Stay Consistent!**  
   - Competitive programming requires patience and regular practice.
   - Aim for solving at least 1-2 problems daily with different difficulty levels.
*/


