class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int colorTarget, int beforeColor) {
        if (sr < 0 
        || sc < 0 
        || sr >= image.size() 
        || sc >= image[0].size() 
        || beforeColor != image[sr][sc] 
        || image[sr][sc] == colorTarget) return;

        int bfr = image[sr][sc];
        image[sr][sc] = colorTarget;

        dfs(image, sr+1, sc, colorTarget, bfr);
        dfs(image, sr-1, sc, colorTarget, bfr);
        dfs(image, sr, sc+1, colorTarget, bfr);
        dfs(image, sr, sc-1, colorTarget, bfr);
    }
};