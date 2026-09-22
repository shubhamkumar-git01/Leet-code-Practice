// Problem: 3525. Find X Value of Array II
// Runtime: 256 ms (Beats 65.45%)
// Memory: 272.1 MB (Beats 89.09%)

class Solution {
public:
    struct Node {
        int prod;
        array<int, 5> cnt;

        Node() {
            prod = 1;
            cnt.fill(0);
        }
    };

    int K;

    Node mergeNode(const Node& a, const Node& b) {
        Node res;

        res.prod = (a.prod * b.prod) % K;

        // Prefixes completely inside a
        for (int r = 0; r < K; r++) {
            res.cnt[r] = a.cnt[r];
        }

        // Prefixes that continue into b
        for (int r = 0; r < K; r++) {
            int nr = (a.prod * r) % K;
            res.cnt[nr] += b.cnt[r];
        }

        return res;
    }

    vector<int> resultArray(vector<int>& nums,
                            int k,
                            vector<vector<int>>& queries) {
        
        K = k;
        int n = nums.size();

        // Iterative segment tree
        int size = 1;
        while (size < n)
            size <<= 1;

        vector<Node> seg(2 * size);

        // Build leaves
        for (int i = 0; i < n; i++) {
            int rem = nums[i] % K;

            seg[size + i].prod = rem;
            seg[size + i].cnt[rem] = 1;
        }

        // Build tree
        for (int i = size - 1; i >= 1; i--) {
            seg[i] = mergeNode(seg[i << 1], seg[i << 1 | 1]);
        }

        auto update = [&](int pos, int val) {
            int p = size + pos;
            int rem = val % K;

            seg[p] = Node();
            seg[p].prod = rem;
            seg[p].cnt[rem] = 1;

            p >>= 1;

            while (p >= 1) {
                seg[p] = mergeNode(seg[p << 1], seg[p << 1 | 1]);
                p >>= 1;
            }
        };

        auto query = [&](int l, int r) {
            Node leftRes;
            Node rightRes;

            l += size;
            r += size;

            while (l <= r) {

                if (l & 1) {
                    leftRes = mergeNode(leftRes, seg[l]);
                    l++;
                }

                if (!(r & 1)) {
                    rightRes = mergeNode(seg[r], rightRes);
                    r--;
                }

                l >>= 1;
                r >>= 1;
            }

            return mergeNode(leftRes, rightRes);
        };

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            update(index, value);

            // Get [start ... n-1]
            Node res = query(start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};