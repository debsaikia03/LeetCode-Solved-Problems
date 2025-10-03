class Solution {
public:

// small helper class to store a cell with its height and coordinates
class Cell{
    int height, row, col;
public:
    Cell(int h, int r, int c): height(h), row(r), col(c) {}
    int getHeight() const { return height; }
    int getRow() const { return row; }
    int getCol() const { return col; }

    // NOTE: priority_queue in C++ is a max-heap by default.
    // To make it behave like a min-heap (smallest height on top),
    // we define operator< to return true when this.height > other.height.
    // That flips the ordering.
    bool operator<(const Cell& other) const { return height > other.height; }
};

int trapRainWater(vector<vector<int>>& heightMap) {

    // Guard: empty or ill-formed input
    if (heightMap.empty() || heightMap[0].empty()) return 0;

    int rows = heightMap.size();
    int cols = heightMap[0].size();

    // If grid is too small to trap water
    if (rows < 3 || cols < 3) return 0;

    int water = 0;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    priority_queue<Cell> pq; // min-heap behavior due to operator< above

    // 1) Push all leftmost and rightmost boundary cells
    for (int i = 0; i < rows; ++i) {
        pq.push(Cell(heightMap[i][0], i, 0));
        pq.push(Cell(heightMap[i][cols - 1], i, cols - 1));
        visited[i][0] = true;
        visited[i][cols - 1] = true;
    }

    // 2) Push top and bottom boundary cells, but avoid re-pushing corners already marked visited
    for (int j = 0; j < cols; ++j) {
        if (!visited[0][j]) {
            pq.push(Cell(heightMap[0][j], 0, j));
            visited[0][j] = true;
        }
        if (!visited[rows - 1][j]) {
            pq.push(Cell(heightMap[rows - 1][j], rows - 1, j));
            visited[rows - 1][j] = true;
        }
    }

    // 4-directional vectors (left, right, up, down)
    int dR[4] = {0, 0, -1, 1};
    int dC[4] = {-1, 1, 0, 0};

    // Main loop: expand from the smallest boundary cell outward
    while (!pq.empty()) {
        Cell cur = pq.top();
        pq.pop();

        int curH = cur.getHeight();
        int r = cur.getRow();
        int c = cur.getCol();

        // Check 4 neighbors
        for (int d = 0; d < 4; ++d) {
            int nr = r + dR[d];
            int nc = c + dC[d];

            // If neighbor inside grid and not visited
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc]) {
                // If neighbor is lower than current boundary, it can trap water
                int trapped = max(0, curH - heightMap[nr][nc]);
                water += trapped;

                // The neighbor's effective height becomes the max of its own height
                // and the current boundary height (water fills to curH if lower).
                int newHeight = max(heightMap[nr][nc], curH);

                // Push neighbor into PQ as part of the expanding boundary
                pq.push(Cell(newHeight, nr, nc));

                // Mark visited so we don't process it again
                visited[nr][nc] = true;
            }
        }
    }

    return water;
}

};
