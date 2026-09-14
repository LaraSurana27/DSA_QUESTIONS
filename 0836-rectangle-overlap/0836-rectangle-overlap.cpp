class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

        /*
        x-overlap: rec1[x1] < rec2[x2]  &&  rec2[x1] < rec1[x2]
        y-overlap: rec1[y1] < rec2[y2]  &&  rec2[y1] < rec1[y2]
        */
        bool x_overlap = rec1[0] < rec2[2] && rec2[0] < rec1[2];
        bool y_overlap = rec1[1] < rec2[3] && rec2[1] < rec1[3];

        return x_overlap && y_overlap; 
    }
};