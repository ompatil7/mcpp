// C++ Template for handling various input types in Competitive Programming
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef set<int> si;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// ---------------------- BASIC INPUT FUNCTIONS ----------------------

// Read a single integer
int readInt() {
    int x;
    cin >> x;
    return x;
}

// Read a single long long
ll readLong() {
    ll x;
    cin >> x;
    return x;
}

// Read a single double/float
double readDouble() {
    double x;
    cin >> x;
    return x;
}

// Read a single string
string readString() {
    string s;
    cin >> s;
    return s;
}

// Read a line (including spaces)
string readLine() {
    string s;
    getline(cin, s);
    return s;
}

// Read a character
char readChar() {
    char c;
    cin >> c;
    return c;
}

// ---------------------- ARRAY INPUT FUNCTIONS ----------------------

// Read an array of integers
vi readIntArray(int n) {
    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return arr;
}

// Read an array of long longs
vll readLongArray(int n) {
    vll arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return arr;
}

// Read an array of strings
vs readStringArray(int n) {
    vs arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return arr;
}

// Read an array of characters
vector<char> readCharArray(int n) {
    vector<char> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return arr;
}

// ---------------------- 2D ARRAY INPUT FUNCTIONS ----------------------

// Read a 2D integer matrix
vvi readIntMatrix(int rows, int cols) {
    vvi matrix(rows, vi(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

// Read a 2D character grid
vector<vector<char>> readCharGrid(int rows, int cols) {
    vector<vector<char>> grid(rows, vector<char>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }
    return grid;
}

// Read a grid where each row is a string
vector<string> readStringGrid(int rows) {
    vector<string> grid(rows);
    for (int i = 0; i < rows; i++) {
        cin >> grid[i];
    }
    return grid;
}

// ---------------------- GRAPH INPUT FUNCTIONS ----------------------

// Read an undirected graph (adjacency list representation)
vector<vector<int>> readUndirectedGraph(int n, int m) {
    // n: number of nodes, m: number of edges
    vector<vector<int>> graph(n + 1); // 1-indexed
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // For undirected graph
    }
    return graph;
}

// Read a directed graph (adjacency list representation)
vector<vector<int>> readDirectedGraph(int n, int m) {
    // n: number of nodes, m: number of edges
    vector<vector<int>> graph(n + 1); // 1-indexed
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    return graph;
}

// Read a weighted undirected graph
vector<vector<pair<int, int>>> readWeightedUndirectedGraph(int n, int m) {
    // n: number of nodes, m: number of edges
    vector<vector<pair<int, int>>> graph(n + 1); // 1-indexed
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // For undirected graph
    }
    return graph;
}

// Read a weighted directed graph
vector<vector<pair<int, int>>> readWeightedDirectedGraph(int n, int m) {
    // n: number of nodes, m: number of edges
    vector<vector<pair<int, int>>> graph(n + 1); // 1-indexed
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    return graph;
}

// ---------------------- TREE INPUT FUNCTIONS ----------------------

// Read a tree (undirected graph with n-1 edges)
vector<vector<int>> readTree(int n) {
    vector<vector<int>> tree(n + 1); // 1-indexed
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    return tree;
}

// Read a weighted tree
vector<vector<pair<int, int>>> readWeightedTree(int n) {
    vector<vector<pair<int, int>>> tree(n + 1); // 1-indexed
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }
    return tree;
}

// ---------------------- SPECIALIZED INPUT FUNCTIONS ----------------------

// Read a set of integers
set<int> readIntSet(int n) {
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    return s;
}

// Read a map (key-value pairs)
map<int, int> readIntMap(int n) {
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int key, value;
        cin >> key >> value;
        m[key] = value;
    }
    return m;
}

// Read an array of pairs
vector<pair<int, int>> readPairArray(int n) {
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    return arr;
}

// Read array where values are space-separated on a single line
vi readSpaceSeparatedInts() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vi arr;
    int x;
    while (ss >> x) {
        arr.push_back(x);
    }
    return arr;
}

// Read integers until end of line
vi readIntsUntilEOL() {
    vi arr;
    int x;
    string line;
    getline(cin, line);
    stringstream ss(line);
    while (ss >> x) {
        arr.push_back(x);
    }
    return arr;
}

// ---------------------- SPECIAL FORMATS ----------------------

// Read comma-separated integers
vi readCommaSeparatedInts() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vi arr;
    string token;
    while (getline(ss, token, ',')) {
        arr.push_back(stoi(token));
    }
    return arr;
}

// Read specific number of integers from single line
vi readNIntsFromLine(int n) {
    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return arr;
}

// Read a binary string and convert to integer
int readBinaryAsInt() {
    string s;
    cin >> s;
    return stoi(s, nullptr, 2);
}

// Read hexadecimal and convert to integer
int readHexAsInt() {
    string s;
    cin >> s;
    return stoi(s, nullptr, 16);
}

// ---------------------- MAIN FUNCTION ----------------------

int main() {
    fastIO();
    
    // Example usage:
    int t = readInt(); // Number of test cases
    
    while (t--) {
        // For single value inputs
        int n = readInt();
        
        // For reading an array
        vi arr = readIntArray(n);
        
        // For reading a matrix
        int m = readInt();
        vvi matrix = readIntMatrix(n, m);
        
        // For reading a graph
        int edges = readInt();
        auto graph = readUndirectedGraph(n, edges);
        
        // Your solution code here
        
        // Example output
        cout << "Processed test case" << endl;
    }
    
    return 0;
}