#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to check if the current position is valid to move
bool isValidMove(int x, int y, vector<vector<int>>& mat, vector<vector<bool>>& visited, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n && mat[x][y] == 1 && !visited[x][y]);
}

// Backtracking function to find all paths
void findPaths(int x, int y, vector<vector<int>>& mat, int n, vector<vector<bool>>& visited, string path, vector<string>& result) {
    // If we reach the destination, store the current path
    if (x == n - 1 && y == n - 1) {
        result.push_back(path);
        return;
    }

    // Mark the current cell as visited
    visited[x][y] = true;

    // Move Down
    if (isValidMove(x + 1, y, mat, visited, n)) {
        findPaths(x + 1, y, mat, n, visited, path + 'D', result);
    }

    // Move Left
    if (isValidMove(x, y - 1, mat, visited, n)) {
        findPaths(x, y - 1, mat, n, visited, path + 'L', result);
    }

    // Move Right
    if (isValidMove(x, y + 1, mat, visited, n)) {
        findPaths(x, y + 1, mat, n, visited, path + 'R', result);
    }

    // Move Up
    if (isValidMove(x - 1, y, mat, visited, n)) {
        findPaths(x - 1, y, mat, n, visited, path + 'U', result);
    }

    // Backtrack: unmark the current cell
    visited[x][y] = false;
}

// Main function to find all possible paths from (0, 0) to (n-1, n-1)
vector<string> ratInMaze(vector<vector<int>>& mat, int n) {
    vector<string> result;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    if (mat[0][0] == 1) {
        findPaths(0, 0, mat, n, visited, "", result);
    }

    return result;
}

int main() {
    int n = 4;
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> paths = ratInMaze(mat, n);

    if (paths.empty()) {
        cout << "No path found." << endl;
    } else {
        for (const string& path : paths) {
            cout << path << " ";
        }
    }

    return 0;
}
