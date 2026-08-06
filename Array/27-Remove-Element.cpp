class Solution {
public:
    int removeElement(vector<int>& a, int v) {
        int k = 0;
        for (int x : a)
            if (x != v) a[k++] = x;
        return k;
    }
};