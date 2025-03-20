// C++ Template for handling various output types in Competitive Programming
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

// ---------------------- BASIC OUTPUT FUNCTIONS ----------------------

// Output a single value with newline
template<typename T>
void println(T x) {
    cout << x << endl;
}

// Output a single value without newline
template<typename T>
void print(T x) {
    cout << x;
}

// Output a value with specific precision
void printFloat(double x, int precision = 6) {
    cout << fixed << setprecision(precision) << x << endl;
}

// ---------------------- ARRAY OUTPUT FUNCTIONS ----------------------

// Output an array with space separation
template<typename T>
void printArray(const vector<T>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << " ";
    }
    cout << endl;
}

// Output an array with custom separator
template<typename T>
void printArrayWithSep(const vector<T>& arr, string sep = " ") {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << sep;
    }
    cout << endl;
}

// Output each element of an array on a new line
template<typename T>
void printArrayPerLine(const vector<T>& arr) {
    for (const T& element : arr) {
        cout << element << endl;
    }
}

// Output a 2D matrix
template<typename T>
void printMatrix(const vector<vector<T>>& matrix) {
    for (const vector<T>& row : matrix) {
        for (int i = 0; i < row.size(); i++) {
            cout << row[i];
            if (i < row.size() - 1) cout << " ";
        }
        cout << endl;
    }
}

// Output a 2D matrix with custom separators
template<typename T>
void printMatrixWithSep(const vector<vector<T>>& matrix, string elemSep = " ", string rowSep = "\n") {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j];
            if (j < matrix[i].size() - 1) cout << elemSep;
        }
        cout << (i < matrix.size() - 1 ? rowSep : "");
    }
    cout << endl;
}

// Output a character grid
void printCharGrid(const vector<vector<char>>& grid) {
    for (const vector<char>& row : grid) {
        for (char c : row) {
            cout << c;
        }
        cout << endl;
    }
}

// ---------------------- DATA STRUCTURE OUTPUT FUNCTIONS ----------------------

// Output a pair
template<typename T1, typename T2>
void printPair(const pair<T1, T2>& p) {
    cout << p.first << " " << p.second << endl;
}

// Output an array of pairs
template<typename T1, typename T2>
void printPairArray(const vector<pair<T1, T2>>& arr) {
    for (const pair<T1, T2>& p : arr) {
        cout << p.first << " " << p.second << endl;
    }
}

// Output a set
template<typename T>
void printSet(const set<T>& s) {
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it;
        if (next(it) != s.end()) cout << " ";
    }
    cout << endl;
}

// Output a multiset
template<typename T>
void printMultiset(const multiset<T>& ms) {
    for (auto it = ms.begin(); it != ms.end(); ++it) {
        cout << *it;
        if (next(it) != ms.end()) cout << " ";
    }
    cout << endl;
}

// Output a map
template<typename K, typename V>
void printMap(const map<K, V>& m) {
    for (const auto& pair : m) {
        cout << pair.first << " " << pair.second << endl;
    }
}

// Output a map horizontally
template<typename K, typename V>
void printMapHorizontal(const map<K, V>& m) {
    bool first = true;
    for (const auto& pair : m) {
        if (!first) cout << " ";
        cout << pair.first << ":" << pair.second;
        first = false;
    }
    cout << endl;
}

// ---------------------- GRAPH OUTPUT FUNCTIONS ----------------------

// Output an adjacency list (unweighted graph)
void printGraph(const vector<vector<int>>& graph) {
    for (int i = 1; i < graph.size(); i++) {  // Assuming 1-indexed
        cout << "Node " << i << ": ";
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j];
            if (j < graph[i].size() - 1) cout << " ";
        }
        cout << endl;
    }
}

// Output an adjacency list (weighted graph)
void printWeightedGraph(const vector<vector<pair<int, int>>>& graph) {
    for (int i = 1; i < graph.size(); i++) {  // Assuming 1-indexed
        cout << "Node " << i << ": ";
        for (int j = 0; j < graph[i].size(); j++) {
            cout << "(" << graph[i][j].first << ", " << graph[i][j].second << ")";
            if (j < graph[i].size() - 1) cout << " ";
        }
        cout << endl;
    }
}

// Output an adjacency matrix
void printAdjacencyMatrix(const vector<vector<int>>& adjMatrix) {
    int n = adjMatrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j];
            if (j < n - 1) cout << " ";
        }
        cout << endl;
    }
}

// ---------------------- SPECIALIZED OUTPUT FUNCTIONS ----------------------

// Output "YES" or "NO" for boolean result (common in many problems)
void printYesNo(bool condition) {
    cout << (condition ? "YES" : "NO") << endl;
}

// Output "Yes" or "No" for boolean result (alternative form)
void printYesNoCapital(bool condition) {
    cout << (condition ? "Yes" : "No") << endl;
}

// Output binary representation of a number
void printBinary(int n, int bits = 0) {
    if (bits == 0) {
        bits = 32 - __builtin_clz(n);  // Minimum required bits
        if (bits == 0) bits = 1;  // For n=0 case
    }
    for (int i = bits - 1; i >= 0; i--) {
        cout << ((n >> i) & 1);
    }
    cout << endl;
}

// Output multiple values in one line
template<typename... Args>
void printLine(Args... args) {
    ((cout << args << " "), ...);
    cout << endl;
}

// Output array with custom format (e.g., with brackets and commas)
template<typename T>
void printFormattedArray(const vector<T>& arr, string start = "[", string sep = ", ", string end = "]") {
    cout << start;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << sep;
    }
    cout << end << endl;
}

// Output a grid with borders
void printBorderedGrid(const vector<vector<char>>& grid) {
    int rows = grid.size();
    if (rows == 0) return;
    int cols = grid[0].size();
    
    // Top border
    cout << "+";
    for (int j = 0; j < cols; j++) cout << "-";
    cout << "+" << endl;
    
    // Grid content with side borders
    for (int i = 0; i < rows; i++) {
        cout << "|";
        for (int j = 0; j < cols; j++) {
            cout << grid[i][j];
        }
        cout << "|" << endl;
    }
    
    // Bottom border
    cout << "+";
    for (int j = 0; j < cols; j++) cout << "-";
    cout << "+" << endl;
}

// ---------------------- ANSWER FORMAT FUNCTIONS ----------------------

// Output the result of each test case with proper formatting
void printTestCaseResult(int testCase, auto result) {
    cout << "Case #" << testCase << ": " << result << endl;
}

// Output the result of each test case with proper formatting (Google Code Jam style)
template<typename T>
void printCodeJamResult(int testCase, T result) {
    cout << "Case #" << testCase << ": " << result << endl;
}

// Output the result of each test case with proper formatting (ICPC style)
template<typename T>
void printICPCResult(T result) {
    cout << result << endl;
}

// ---------------------- MAIN FUNCTION ----------------------

int main() {
    fastIO();
    
    // Example usage:
    int t = 1; // Number of test cases
    cin >> t;
    
    for(int tc = 1; tc <= t; tc++) {
        // Read input
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        // Process the input and generate output
        sort(arr.begin(), arr.end());
        
        // Output examples
        cout << "Test Case " << tc << ":" << endl;
        
        // Basic array output
        cout << "Array: ";
        printArray(arr);
        
        // Formatted array output
        cout << "Formatted: ";
        printFormattedArray(arr);
        
        // Custom output
        cout << "Minimum: " << arr[0] << ", Maximum: " << arr[n-1] << endl;
        
        // Boolean answer
        bool hasDuplicates = false;
        for(int i = 1; i < n; i++) {
            if(arr[i] == arr[i-1]) {
                hasDuplicates = true;
                break;
            }
        }
        cout << "Has duplicates: ";
        printYesNo(hasDuplicates);
        
        cout << endl;  // Separate test cases
    }
    
    return 0;
}