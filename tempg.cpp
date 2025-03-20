#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Comprehensive Competitive Programming Templates
int main() {
    // 1. Array Input/Output
    // Use case: When number of elements is fixed, and random access is required.
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Array: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;

    // 2. Vector Input/Output
    // Use case: Dynamic arrays that can grow/shrink in size.
    vector<int> vec = {10, 20, 30, 40, 50};
    cout << "Vector: ";
    for (int num : vec) cout << num << " ";
    cout << endl;

    // 3. Queue Input/Output (FIFO structure)
    // Use case: BFS, scheduling problems.
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Queue Front: " << q.front() << " Queue Back: " << q.back() << endl;
    q.pop();
    cout << "Queue Front after pop: " << q.front() << endl;

    // 4. Stack Input/Output (LIFO structure)
    // Use case: DFS, backtracking problems.
    stack<int> s;
    s.push(100);
    s.push(200);
    s.push(300);
    cout << "Stack Top: " << s.top() << endl;
    s.pop();
    cout << "Stack Top after pop: " << s.top() << endl;

    // 5. Set Input/Output
    // Use case: Storing unique elements in sorted order.
    set<int> st = {50, 20, 40, 10, 30};
    cout << "Set: ";
    for (int num : st) cout << num << " ";
    cout << endl;

    // 6. Map Input/Output (Key-Value Pairs)
    // Use case: Storing frequency counts, dictionary-like structures.
    map<string, int> mp;
    mp["Alice"] = 25;
    mp["Bob"] = 30;
    cout << "Map: " << endl;
    for (auto &p : mp) cout << p.first << " -> " << p.second << endl;

    // 7. Sorting a Vector
    // Use case: Sorting elements for binary search, two-pointer problems.
    vector<int> nums = {5, 2, 8, 1, 3};
    sort(nums.begin(), nums.end());
    cout << "Sorted Vector: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    // 8. Binary Search
    // Use case: Finding an element in sorted array in O(log n) time.
    int target = 3;
    bool found = binary_search(nums.begin(), nums.end(), target);
    cout << "Binary Search for 3: " << (found ? "Found" : "Not Found") << endl;

    // 9. Graph Representation using Adjacency List (BFS & DFS)
    // Use case: Traversing graphs.
    vector<vector<int>> graph(5);
    graph[0].push_back(1);
    graph[1].push_back(2);
    graph[2].push_back(3);
    graph[3].push_back(4);
    cout << "Graph Adjacency List: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Node " << i << ": ";
        for (int neighbor : graph[i]) cout << neighbor << " ";
        cout << endl;
    }

    // 10. Greedy Algorithm Example (Activity Selection)
    // Use case: Selecting non-overlapping activities.
    vector<pair<int, int>> activities = {{1, 3}, {2, 5}, {4, 7}, {1, 8}};
    sort(activities.begin(), activities.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    int count = 0, end_time = 0;
    for (auto act : activities) {
        if (act.first >= end_time) {
            count++;
            end_time = act.second;
        }
    }
    cout << "Max Activities Selected: " << count << endl;

    return 0;
}
