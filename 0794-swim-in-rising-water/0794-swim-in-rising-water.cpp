class Solution {
public:
    //directions for moving up, down, left, right
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    //dfs
    bool possibleToReach(vector<vector<int>>& grid, int i, int j, int mid, vector<vector<bool>>& visited, int n) {
        //base cases: out of bounds, already visited, or cell elevation > current water level
        if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || grid[i][j] > mid)
            return false;

        //mark current cell as visited
        visited[i][j] = true;

        //if reached bottom-right corner
        if (i == n - 1 && j == n - 1)
            return true;

        //explore all 4 directions
        for (auto& dir : directions) {
            int newI = i + dir[0];
            int newJ = j + dir[1];
            if (possibleToReach(grid, newI, newJ, mid, visited, n))
                return true;
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        int l = grid[0][0];
        int r = n * n - 1;
        int result = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            vector<vector<bool>> visited(n, vector<bool>(n, false));

            //pass n and visited by reference
            if (possibleToReach(grid, 0, 0, mid, visited, n)) {
                result = mid;
                r = mid - 1; // try smaller time
            } else {
                l = mid + 1; // need more time
            }
        }

        return result;
    }
};
