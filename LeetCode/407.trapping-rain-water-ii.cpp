/*
 * @lc app=leetcode id=407 lang=cpp
 *
 * [407] Trapping Rain Water II
 */

// @lc code=start
/*
方法1：优先队列 
*/
/*
typedef pair<int, pair<int, int>> pii;
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int width = heightMap.size();
        int length = heightMap[0].size();
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<vector<bool>> visit(width, vector<bool> (length, false));
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < length; j++) {
                if (i == 0 || i == width - 1 || j == 0 || j == length - 1) {
                    pq.push({heightMap[i][j], {i, j}});
                    visit[i][j] = true;
                }
            }
        }

        int res = 0;
        int dir[4][2] = {{1, 0},{-1, 0}, {0, 1}, {0, -1}};
        while (!pq.empty()) {
            pii curr = pq.top();
            pq.pop();
            for (int i = 0; i < 4; i++) {
                int nx = curr.second.first + dir[i][0];
                int ny = curr.second.second + dir[i][1];
                if (nx >= 0 && nx < width && ny >= 0 && ny < length && visit[nx][ny] == false) {
                    int tmp_height = max(heightMap[nx][ny], curr.first);
                    visit[nx][ny] = true;
                    pq.push({tmp_height, {nx, ny}});
                    int tmp = curr.first - heightMap[nx][ny];
                    res += (tmp > 0) ? tmp : 0;
                }
            }
        }
        return res;
    }
};
*/
/*
方法2： BFS
通过寻找map的最高高度，然后将每一个方格作为一堵墙，分别访问墙的四周是否满足条件
*/
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int width = heightMap.size();
        int length = heightMap[0].size();
        int maxHeight = 0;
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int i = 0; i < width; i++) {
            maxHeight = max(maxHeight, *max_element(heightMap[i].begin(), heightMap[i].end()));
        }

        vector<vector<int>> water(width, vector<int>(length, maxHeight));
        queue<pair<int, int>> qu;
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < length; j++) {
                if (i == 0 || i == width - 1 || j == 0 || j == length - 1) {
                    if (water[i][j] > heightMap[i][j]) {
                        water[i][j] = heightMap[i][j];
                        qu.push(make_pair(i, j));
                    }
                }
            }
        }
        while (!qu.empty()) {
            int x = qu.front().first;
            int y = qu.front().second;
            qu.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if (nx < 0 || nx >= width || ny < 0 || ny >= length) {
                    continue;
                }
                if (water[x][y] < water[nx][ny] && heightMap[nx][ny] < water[nx][ny]) {
                    water[nx][ny] = max(water[x][y], heightMap[nx][ny]);
                    qu.push(make_pair(nx, ny));
                }
            }
        }

        int res = 0;
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < length; j++) {
                res += water[i][j] - heightMap[i][j];
            }
        }
        return res;
    }
};
// @lc code=end
