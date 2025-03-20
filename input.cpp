#include <bits/stdc++.h>
using namespace std;

// Macros for Competitive Programming
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()

/****************** Fast Input/Output ******************/
// This improves the speed of cin/cout significantly
int main() {
    fast_io;
    
    /****************** Sorting ******************/
    vector<int> arr = {4, 2, 5, 1, 3};
    sort(arr.begin(), arr.end());  // Ascending order
    sort(arr.rbegin(), arr.rend()); // Descending order
    
    // Custom comparator sorting (Descending order)
    sort(arr.begin(), arr.end(), [](int a, int b) { return a > b; });
    
    /****************** Binary Search ******************/
    auto binary_search_custom = [](vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return mid;
            else if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1; // Element not found
    };
    
    /****************** Graph BFS & DFS ******************/
    const int N = 1001;
    vector<int> adj[N];
    bool visited[N] = {false};
    
    // BFS Function
    auto bfs = [&](int start) {
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    };
    
    // DFS Function
    auto dfs = [&](int node) {
        visited[node] = true;
        cout << node << " ";
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor);
            }
        }
    };
    
    /****************** Two Pointers / Sliding Window ******************/
    auto findSubarray = [](vector<int>& arr, int target) {
        int left = 0, sum = 0;
        for (int right = 0; right < arr.size(); right++) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left++];
            }
            if (sum == target) {
                return make_pair(left, right); // Found subarray
            }
        }
        return make_pair(-1, -1); // No subarray found
    };
    
    /****************** Greedy Algorithm (Activity Selection) ******************/
    vector<pair<int, int>> activities = {{1, 3}, {2, 5}, {4, 6}, {6, 8}, {5, 7}};
    sort(activities.begin(), activities.end(), [](auto &a, auto &b) {
        return a.second < b.second; // Sorting by ending time
    });
    
    int count = 1, last_end = activities[0].second;
    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].first >= last_end) {
            count++;
            last_end = activities[i].second;
        }
    }
    cout << "Max Activities: " << count << endl;
    
    /****************** GCD & LCM ******************/
    auto gcd = [](int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    };
    auto lcm = [&](int a, int b) {
        return (a / gcd(a, b)) * b;
    };
    
    cout << "GCD of 36 and 60: " << gcd(36, 60) << endl;
    cout << "LCM of 36 and 60: " << lcm(36, 60) << endl;
    
    return 0;
}
