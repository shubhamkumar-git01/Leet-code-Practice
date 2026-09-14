// Problem: 836. Rectangle Overlap
// Runtime: 0 ms (Beats 100.00%)
// Memory: 9.9 MB (Beats 11.03%)

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return rec1[0] < rec2[2] &&
               rec2[0] < rec1[2] &&
               rec1[1] < rec2[3] &&
               rec2[1] < rec1[3];
    }
};