class Solution {
public:

    int countOverlaps(vector<vector<int>>& A, vector<vector<int>>& B, int rowOff, int colOff)
    {
        int n = A.size();
        int count = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // A[i][j] = B[i+rowOff][j+colOff]

                int B_i = i + rowOff;
                int B_j = j + colOff;

                if(B_i < 0 || B_i >= n || B_j < 0 || B_j >= n) continue;

                if(A[i][j] == 1 && B[B_i][B_j] == 1) count++;
            }
        }
        return count;
    }
   
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int maxOverlap = 0;

        for(int rowOff = -n+1; rowOff < n; rowOff++)
        {
            for(int colOff = -n+1; colOff < n; colOff++)
            {
                int count = countOverlaps(A, B, rowOff, colOff);

                maxOverlap = max(maxOverlap, count);
            }
        }
        return maxOverlap;
    }
};

/*
A ko (rowOff, colOff) shift karne par:
A[i][j] ↔ B[i+rowOff][j+colOff]
Har possible shift try karo, best overlap nikaalo
Range: rowOff, colOff ∈ [-(n-1), n-1]

Steps
countOverlaps(A, B, rowOff, colOff)
Poori matrix A traverse karo (i, j)
B_i = i+rowOff, B_j = j+colOff
Boundary check → out of range ho to continue
A[i][j]==1 && B[B_i][B_j]==1 → count++
Return count
largestOverlap(A, B)
Do nested loops: sab rowOff × sab colOff try karo
Har shift pe countOverlaps() call karo
maxOverlap update karte raho
Return maxOverlap
*/