class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int startR = -1, startC = -1;
        vector<pair<int, int>> litters;
        
        // 1. Locate starting position and assign indices to litter items
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    startR = i;
                    startC = j;
                } else if (classroom[i][j] == 'L') {
                    litters.push_back({i, j});
                }
            }
        }
        
        int totalLitters = litters.size();
        int targetMask = (1 << totalLitters) - 1;
        
        // Helper to quickly find a litter index by grid position
        auto getLitterIndex = [&](int r, int c) {
            for (int i = 0; i < totalLitters; ++i) {
                if (litters[i].first == r && litters[i].second == c) return i;
            }
            return -1;
        };

        // 4D Visited array: visited[r][c][current_energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m, vector<vector<vector<bool>>>(
                n, vector<vector<bool>>(
                    energy + 1, vector<bool>(1 << totalLitters, false)
                )
            )
        );
        
        // BFS Queue stores: {row, col, current_energy, mask, moves}
        queue<tuple<int, int, int, int, int>> q;
        
        // Initial setup for the starting position
        int initialMask = 0;
        int idx = getLitterIndex(startR, startC);
        if (idx != -1) {
            initialMask |= (1 << idx);
        }
        
        q.push({startR, startC, energy, initialMask, 0});
        visited[startR][startC][energy][initialMask] = true;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        // 2. Begin BFS
        while (!q.empty()) {
            auto [r, c, currEnergy, mask, moves] = q.front();
            q.pop();
            
            // Goal reached: All litter items have been collected
            if (mask == targetMask) {
                return moves;
            }
            
            // If energy is 0, we can only move if we are currently standing on a reset area
            if (currEnergy == 0 && classroom[r][c] != 'R') {
                continue;
            }
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                // Out of bounds or obstacle check
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') {
                    continue;
                }
                
                // Cost to step into the next cell is 1 energy unit
                int nextEnergy = currEnergy - 1;
                if (nextEnergy < 0) continue; 
                
                // If the next cell is a reset area, restore energy immediately
                if (classroom[nr][nc] == 'R') {
                    nextEnergy = energy;
                }
                
                // Check if the next cell contains uncollected litter
                int nextMask = mask;
                int lIdx = getLitterIndex(nr, nc);
                if (lIdx != -1) {
                    nextMask |= (1 << lIdx);
                }
                
                if (!visited[nr][nc][nextEnergy][nextMask]) {
                    visited[nr][nc][nextEnergy][nextMask] = true;
                    q.push({nr, nc, nextEnergy, nextMask, moves + 1});
                }
            }
        }
        
        return -1; // Return -1 if it is impossible to clean the classroom
    }
};
