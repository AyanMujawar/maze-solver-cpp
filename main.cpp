#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class MazeSolver {
private:
    int rows, cols;
    vector<vector<int>> maze;
    vector<vector<bool>> visited;
    int startX, startY, goalX, goalY;

public:
    MazeSolver(int r, int c, vector<vector<int>> m, int sx, int sy, int gx, int gy) {
        rows = r;
        cols = c;
        maze = m;
        startX = sx;
        startY = sy;
        goalX = gx;
        goalY = gy;

        visited.resize(rows);
        for (int i = 0; i < rows; i++) {
            visited[i].resize(cols, false);
        }
    }

    void resetVisited() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                visited[i][j] = false;
            }
        }
    }

    bool isValid(int x, int y) {
        if (x >= 0 && x < rows && y >= 0 && y < cols) {
            if (maze[x][y] == 1 && visited[x][y] == false) {
                return true;
            }
        }
        return false;
    }

    void printMaze() {
        cout << "\nMaze:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << maze[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool bfs() {
        resetVisited();

        queue<pair<int, int>> q;
        q.push(make_pair(startX, startY));
        visited[startX][startY] = true;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();

            int x = current.first;
            int y = current.second;

            if (x == goalX && y == goalY) {
                cout << "Goal reached using BFS at: " << x << ", " << y << endl;
                return true;
            }

            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (isValid(newX, newY)) {
                    visited[newX][newY] = true;
                    q.push(make_pair(newX, newY));
                }
            }
        }

        cout << "Goal not found using BFS.\n";
        return false;
    }

    bool dfs() {
        resetVisited();

        stack<pair<int, int>> s;
        s.push(make_pair(startX, startY));
        visited[startX][startY] = true;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!s.empty()) {
            pair<int, int> current = s.top();
            s.pop();

            int x = current.first;
            int y = current.second;

            if (x == goalX && y == goalY) {
                cout << "Goal reached using DFS at: " << x << ", " << y << endl;
                return true;
            }

            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (isValid(newX, newY)) {
                    visited[newX][newY] = true;
                    s.push(make_pair(newX, newY));
                }
            }
        }

        cout << "Goal not found using DFS.\n";
        return false;
    }
};

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> maze(rows, vector<int>(cols));
    cout << "Enter the maze (1 for open, 0 for blocked):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> maze[i][j];
        }
    }

    int startX, startY, goalX, goalY;
    cout << "Enter starting point (x y): ";
    cin >> startX >> startY;
    cout << "Enter goal point (x y): ";
    cin >> goalX >> goalY;

    MazeSolver solver(rows, cols, maze, startX, startY, goalX, goalY);

    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Print the maze\n";
        cout << "2. Solve using BFS\n";
        cout << "3. Solve using DFS\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            solver.printMaze();
        } else if (choice == 2) {
            solver.bfs();
        } else if (choice == 3) {
            solver.dfs();
        } else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
