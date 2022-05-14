#include <vector>

using namespace std;

class Solution {
private:
    int orgColor;
    int newColor;
    int m, n;

    void dfs(vector<vector<int>>& image, int x, int y) {
        // If the index is out of bound, or the color of the current grid is the same as the new color
        // or the current grid's color is not the original color of the initial grid, skip the current
        // grid
        if(x < 0 || x >= m || y < 0 || y >= n || image[x][y] == newColor || image[x][y] != orgColor) {
            return;
        }

        // Change the current grid's color to the new color
        image[x][y] = newColor;

        // Visit the 4 grids surrounding the current grid
        dfs(image, x - 1, y);
        dfs(image, x + 1, y);
        dfs(image, x, y - 1);
        dfs(image, x, y + 1);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Save the new color
        this->newColor = newColor;

        // Get the dimension of the image
        m = image.size();
        n = image[0].size();
        
        // Save the original color of the initial grid
        orgColor = image[sr][sc];

        // Use dfs to mark all grids that has the same color as the initial grid and
        // is connected to it
        dfs(image, sr, sc);

        return image;
    }
};
