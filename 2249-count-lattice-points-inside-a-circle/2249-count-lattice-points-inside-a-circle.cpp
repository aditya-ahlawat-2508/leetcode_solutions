class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int n = circles.size();
        int max_X = INT_MIN;
        int max_Y = INT_MIN;
        int max_R = INT_MIN;
        for (int i = 0; i < n; i++) {
            max_X = max(max_X, circles[i][0]);
            max_Y = max(max_Y, circles[i][1]);
            max_R = max(max_R, circles[i][2]);
        }
        max_X = max_X + max_R;
        max_Y = max_Y + max_R;

        int count = 0;
        // vector<vector<int>> mat(max_X + 1, vector<int>(max_Y + 1, 0));
        for (int i = 0; i <= max_X; i++) {
            for (int j = 0; j <= max_Y; j++) {
                for (int k = 0; k < circles.size(); k++) {
                    int dx = circles[k][0] - i;
                    int dy = circles[k][1] - j;
                    int dist = dx * dx + dy * dy;
                    int r = circles[k][2];
                    if (dist <= r * r) {
                        // if (mat[dx][dy] == 0) {
                            // mat[dx][dy] = 1;
                            count++;
                            break;
                        // }
                    }
                }
            }
        }
        return count;
    }
};