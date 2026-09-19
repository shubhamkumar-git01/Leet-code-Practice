// Problem: 1401. Circle and Rectangle Overlapping
// Runtime: 0 ms (Beats 100.00%)
// Memory: 7.7 MB (Beats 95.38%)

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        return dx * dx + dy * dy <= radius * radius;
    }
};