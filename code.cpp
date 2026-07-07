#include <bits/stdc++.h>
using namespace std;

struct Node {
    int count;
    Node *childNode[2];

    Node() {
        count = 0;
        childNode[0] = childNode[1] = NULL;
    }
};

class Trie {
    int N = 30;
    Node *root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int x, int y = 1) {
        Node *curNode = root;
        for (int i = N; i >= 0; i--) {
            bool k = (x & (1LL << i));

            if (curNode->childNode[k] == NULL) {
                Node *newNode = new Node();
                curNode->childNode[k] = newNode;
            }

            curNode = curNode->childNode[k];
            curNode->count += y;
        }
    }

    void erase(int x, int y = 1) {
        Node *curNode = root;
        for (int i = N; i >= 0; i--) {
            bool k = (x & (1LL << i));

            curNode = curNode->childNode[k];
            curNode->count -= y;
        }
    }

    int count(int x) {
        Node *curNode = root;
        for (int i = N; i >= 0; i--) {
            bool k = (x & (1LL << i));

            if (curNode->childNode[k] == NULL) return 0;
            curNode = curNode->childNode[k];
        }

        return curNode->count;
    }

    int findSmallest(int k = 1) {
        int ans = 0;
        Node *curNode = root;
        for (int i = N; i >= 0; i--) {
            int left = (curNode->childNode[0] ? curNode->childNode[0]->count : 0);

            if (left >= k) curNode = curNode->childNode[0];
            else {
                ans += (1LL << i), k -= left;
                curNode = curNode->childNode[1];
            }
        }

        return ans;
    }

    void eraseSmallest(int k = 1) {
        Node *curNode = root;
        for (int i = N; i >= 0; i--) {
            int left = (curNode->childNode[0] ? curNode->childNode[0]->count : 0);

            if (left >= k) curNode = curNode->childNode[0];
            else {
                k -= left;
                curNode = curNode->childNode[1];
            }

            curNode->count--;
        }
    }

    int findGreatest(int k = 1) {
        int ans = 0;
        Node *curNode = root;
        for (int i = N; i >= 0; i--) {
            int right = (curNode->childNode[1] ? curNode->childNode[1]->count : 0);

            if (right < k) k -= right, curNode = curNode->childNode[0];
            else {
                ans += (1LL << i);
                curNode = curNode->childNode[1];
            }
        }

        return ans;
    }

    void eraseGreatest(int k = 1) {
        Node *curNode = root;
        for (int i = N; i >= 0; i--) {
            int right = (curNode->childNode[1] ? curNode->childNode[1]->count : 0);

            if (right < k) k -= right, curNode = curNode->childNode[0];
            else curNode = curNode->childNode[1];

            curNode->count--;
        }
    }

    int countSmaller(int x, int y = 0) {
        int ans = 0;
        Node *curNode = root;
        for (int i = N; i >= 0; i--) {
            bool k = (x & (1LL << i));

            if (k == 1 && curNode->childNode[0]) ans += curNode->childNode[0]->count;

            if (curNode->childNode[k] == NULL) return ans;
            curNode = curNode->childNode[k];
        }

        return ans + (y == 1 ? curNode->count : 0);
    }

    int countGreater(int x, int y = 0) {
        int ans = 0;
        Node *curNode = root;
        for (int i = N; i >= 0; i--) {
            bool k = (x & (1LL << i));

            if (k == 0 && curNode->childNode[1]) ans += curNode->childNode[1]->count;

            if (curNode->childNode[k] == NULL) return ans;
            curNode = curNode->childNode[k];
        }

        return ans + (y == 1 ? curNode->count : 0);
    }

    int minxor(int x) {
        int ans = 0;
        Node *curNode = root;
        for (int i = N; i >= 0; i--) {
            bool k = (x & (1LL << i));

            if (curNode->childNode[k] && curNode->childNode[k]->count > 0)
                curNode = curNode->childNode[k];

            else {
                ans += (1LL << i);
                curNode = curNode->childNode[k ^ 1];
            }
        }

        return ans;
    }

    int maxxor(int x) {
        int ans = 0;
        Node *curNode = root;
        for (int i = N; i >= 0; i--) {
            bool k = (x & (1LL << i));

            if (curNode->childNode[k ^ 1] && curNode->childNode[k ^ 1]->count > 0) {
                ans += (1LL << i);
                curNode = curNode->childNode[k ^ 1];
            }

            else curNode = curNode->childNode[k];
        }

        return ans;
    }

    void sorted(Node *curNode, int bit, int num, vector<int> &ans) {
        if (bit == -1) ans.push_back(num);

        for (int i = 0; i < 2; i++) {
            if (curNode->childNode[i]) {
                sorted(curNode->childNode[i], bit - 1, num + i * (1LL << bit), ans);
            }
        }
    }

    vector<int> sorted() {
        vector<int> ans;
        sorted(root, N, 0, ans);
        return ans;
    }
};