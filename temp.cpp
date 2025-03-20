// Comprehensive C++ Template for Competitive Programming
// Includes essential libraries, macros, data structures, and algorithms

#include <bits/stdc++.h>
using namespace std;

// Common type definitions to save typing time
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef set<int> si;
typedef set<ll> sll;

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-9;

// Macros for faster coding
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, n - 1, 0)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl "\n"

// Fast I/O operations
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// -------------------------- UTILITY FUNCTIONS ---------------------------

// GCD (Greatest Common Divisor) using Euclidean algorithm
// Use case: Find GCD of two numbers
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

// LCM (Least Common Multiple)
// Use case: Find LCM of two numbers
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

// Fast power calculation (a^b % mod)
// Use case: Calculate large powers quickly for modular arithmetic
ll powmod(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// Check if a number is prime
// Use case: Primality testing
bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

// Sieve of Eratosthenes for generating primes up to n
// Use case: Generate all primes up to a limit
vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}

// Generate all prime numbers up to n
// Use case: Get a list of all primes up to a limit
vi getPrimes(int n) {
    vector<bool> isPrime = sieve(n);
    vi primes;
    for (int i = 2; i <= n; i++)
        if (isPrime[i])
            primes.push_back(i);
    return primes;
}

// Number of divisors of n
// Use case: Count how many divisors a number has
int countDivisors(int n) {
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if (i != n / i)
                cnt++;
        }
    }
    return cnt;
}

// Sum of all divisors of n
// Use case: Calculate the sum of all divisors
int sumDivisors(int n) {
    int sum = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i)
                sum += n / i;
        }
    }
    return sum;
}

// -------------------------- DATA STRUCTURES ---------------------------

// Disjoint Set Union (DSU) / Union-Find
// Use case: Connected components, MST algorithms like Kruskal's
class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;
        
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else {
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY])
                rank[rootX]++;
        }
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

// Fenwick Tree / Binary Indexed Tree (BIT)
// Use case: Range sum queries and point updates in O(log n)
class FenwickTree {
private:
    vector<int> bit;
    int n;
    
public:
    FenwickTree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }
    
    void update(int idx, int val) {
        idx++; // 1-indexed
        while (idx < n) {
            bit[idx] += val;
            idx += idx & -idx; // Add LSB
        }
    }
    
    int query(int idx) {
        idx++; // 1-indexed
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx; // Remove LSB
        }
        return sum;
    }
    
    // Range sum [l, r] (0-indexed)
    int rangeSum(int l, int r) {
        return query(r) - query(l - 1);
    }
};

// Segment Tree for range queries
// Use case: Range minimum/maximum/sum queries and point updates
class SegmentTree {
    vector<int> tree;
    int n;
    
public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }
    
    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1]; // Change for min/max
        }
    }
    
    void update(int idx, int val, int node = 1, int start = 0, int end = -1) {
        if (end == -1) end = n - 1;
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(idx, val, 2 * node, start, mid);
        else
            update(idx, val, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1]; // Change for min/max
    }
    
    int query(int l, int r, int node = 1, int start = 0, int end = -1) {
        if (end == -1) end = n - 1;
        if (r < start || l > end) return 0; // Change for min/max
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        int left = query(l, r, 2 * node, start, mid);
        int right = query(l, r, 2 * node + 1, mid + 1, end);
        return left + right; // Change for min/max
    }
};

// Sparse Table for static range queries (RMQ)
// Use case: Fast O(1) range minimum/maximum queries on static arrays
class SparseTable {
    vector<vector<int>> table;
    vector<int> log_2;
    
public:
    SparseTable(const vector<int>& arr) {
        int n = arr.size();
        int max_log = 32 - __builtin_clz(n);
        table.resize(max_log);
        for (int i = 0; i < max_log; i++)
            table[i].resize(n);
        
        // Build sparse table
        for (int i = 0; i < n; i++)
            table[0][i] = arr[i];
        
        for (int i = 1; i < max_log; i++)
            for (int j = 0; j + (1 << i) <= n; j++)
                table[i][j] = min(table[i-1][j], table[i-1][j + (1 << (i-1))]);
        
        // Precompute log values
        log_2.resize(n + 1);
        log_2[1] = 0;
        for (int i = 2; i <= n; i++)
            log_2[i] = log_2[i/2] + 1;
    }
    
    // Range Minimum Query [l, r]
    int query(int l, int r) {
        int len = r - l + 1;
        int k = log_2[len];
        return min(table[k][l], table[k][r - (1 << k) + 1]);
    }
};

// -------------------------- GRAPH ALGORITHMS ---------------------------

// Dijkstra's algorithm for shortest paths
// Use case: Find shortest path from a source to all vertices
void dijkstra(vector<vector<pair<int, int>>>& graph, int src, vector<int>& dist) {
    int n = graph.size();
    dist.assign(n, INF);
    dist[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

// Breadth-First Search (BFS)
// Use case: Shortest path in unweighted graph, connected components
vector<int> bfs(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, -1);
    queue<int> q;
    
    dist[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : graph[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    return dist;
}

// Depth-First Search (DFS)
// Use case: Connected components, cycle detection, topological sort
void dfs(vector<vector<int>>& graph, int u, vector<bool>& visited) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(graph, v, visited);
        }
    }
}

// Find all connected components in an undirected graph
// Use case: Identify isolated groups in a graph
vector<vector<int>> findConnectedComponents(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<vector<int>> components;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> component;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                component.push_back(u);
                
                for (int v : graph[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            
            components.push_back(component);
        }
    }
    
    return components;
}

// Kahn's algorithm for topological sort
// Use case: Find an ordering of tasks with dependencies
vector<int> topologicalSort(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> inDegree(n, 0);
    for (int u = 0; u < n; u++) {
        for (int v : graph[u]) {
            inDegree[v]++;
        }
    }
    
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> topoOrder;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);
        
        for (int v : graph[u]) {
            if (--inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    // If graph has a cycle, topoOrder will not have all vertices
    return topoOrder.size() == n ? topoOrder : vector<int>();
}

// -------------------------- MAIN FUNCTION ---------------------------

void solve() {
    // Your solution code goes here
    
    // Example: Read input
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Example: Process and output results
    sort(arr.begin(), arr.end());
    cout << arr[n/2] << endl;
}

int main() {
    fastIO();
    
    int t = 1;
    cin >> t;  // Comment this line if only one test case
    
    while (t--) {
        solve();
    }
    
    return 0;
}