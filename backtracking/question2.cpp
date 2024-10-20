#include <iostream>
#include <vector>

using namespace std;

// Directions for moving in the 2D grid (Up, Down, Left, Right)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Function to check if the cell is valid and contains a tree ('T')
bool isValid(int x, int y, vector<vector<char>>& field, vector<vector<bool>>& visited, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m && field[x][y] == 'T' && !visited[x][y]);
}

// DFS function to explore the forest
int dfs(int x, int y, vector<vector<char>>& field, vector<vector<bool>>& visited, int n, int m) {
    visited[x][y] = true;
    int size = 1;

    // Explore all four possible directions
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (isValid(newX, newY, field, visited, n, m)) {
            size += dfs(newX, newY, field, visited, n, m);
        }
    }
    return size;
}

// Function to find the size of the largest forest
int largestForest(vector<vector<char>>& field, int n, int m) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int maxSize = 0;

    // Traverse the entire field
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == 'T' && !visited[i][j]) {
                // Find the size of the current forest
                int size = dfs(i, j, field, visited, n, m);
                maxSize = max(maxSize, size);
            }
        }
    }

    return maxSize;
}

int main() {
    int n = 5, m = 5;
    vector<vector<char>> field = {
        {'T', 'T', 'W', 'W', 'T'},
        {'W', 'T', 'W', 'W', 'T'},
        {'W', 'W', 'W', 'T', 'T'},
        {'T', 'T', 'T', 'W', 'W'},
        {'W', 'W', 'T', 'T', 'T'}
    };

    cout << "Size of the largest forest: " << largestForest(field, n, m) << endl;

    return 0;
}
