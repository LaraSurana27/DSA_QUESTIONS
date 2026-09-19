class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        //nearest point
        int xi;
        int yi;

        if(x1 > xCenter)
        {
            xi = x1;
        }
        else if(x2 < xCenter)
        {
            xi = x2;
        }
        else
        {
            xi = xCenter;
        }


        if(y1 > yCenter)
        {
            yi = y1;
        }
        else if(y2 < yCenter)
        {
            yi = y2;
        }
        else
        {
            yi = yCenter;
        }

        int d =  sqrt((xi - xCenter) * (xi - xCenter) + (yi - yCenter) * (yi - yCenter));

        return d <= radius;
    }
};

/*
Approach: Nearest Point (Clamping)

Find point on rectangle closest to circle's center
If that closest point is inside circle → overlap exists (since it's the best case)

Step 1: Find nearest X

If xCenter < x1 → nearest x = x1 (center is left of rect)
If xCenter > x2 → nearest x = x2 (center is right of rect)
Else → nearest x = xCenter (center already within x-range)

Step 2: Find nearest Y

Same logic on y-axis using y1, y2

→ This is basically: xi = clamp(xCenter, x1, x2)
→ yi = clamp(yCenter, y1, y2)

Step 3: Distance Check

Compute distance between (xi, yi) and (xCenter, yCenter)
If distance <= radius → overlap = true
Else → false
*/