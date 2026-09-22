class Solution {
public:
    struct Node {
        int prod = 1;
        long long cnt[5] = {};

        Node() {}

        Node(int v, int k) {
            prod = v % k;
            cnt[prod] = 1;   // the only non-empty prefix
        }
    };

    int n, k;
    vector<int> nums;
    vector<Node> seg;

    Node merge(const Node& A, const Node& B) {
        Node C;

        // Product of the whole concatenated segment
        C.prod = (A.prod * B.prod) % k;

        // Prefixes completely inside A
        for (int x = 0; x < k; ++x) {
            C.cnt[x] += A.cnt[x];
        }

        // Prefixes that contain all of A and then a prefix of B
        //
        // If prefix of B has product y,
        // total product = A.prod * y % k.
        //
        // We need:
        // A.prod * y % k = x
        for (int y = 0; y < k; ++y) {
            int x = (A.prod * y) % k;
            C.cnt[x] += B.cnt[y];
        }

        return C;
    }

    void build(int p, int l, int r) {
        if (l == r) {
            seg[p] = Node(nums[l], k);
            return;
        }

        int m = (l + r) / 2;

        build(p * 2, l, m);
        build(p * 2 + 1, m + 1, r);

        seg[p] = merge(seg[p * 2], seg[p * 2 + 1]);
    }

    void update(int p, int l, int r, int idx, int val) {
        if (l == r) {
            seg[p] = Node(val, k);
            return;
        }

        int m = (l + r) / 2;

        if (idx <= m)
            update(p * 2, l, m, idx, val);
        else
            update(p * 2 + 1, m + 1, r, idx, val);

        seg[p] = merge(seg[p * 2], seg[p * 2 + 1]);
    }

    Node query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[p];

        int m = (l + r) / 2;

        if (qr <= m)
            return query(p * 2, l, m, ql, qr);

        if (ql > m)
            return query(p * 2 + 1, m + 1, r, ql, qr);

        Node left = query(p * 2, l, m, ql, qr);
        Node right = query(p * 2 + 1, m + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(
        vector<int>& nums_,
        int k_,
        vector<vector<int>>& queries
    ) {
        nums = nums_;
        k = k_;
        n = nums.size();

        seg.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            nums[index] = value;
            update(1, 0, n - 1, index, value);

            // Remaining array is nums[start ... n-1].
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};