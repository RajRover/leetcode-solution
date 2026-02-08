struct cmp {
    bool operator()(const pair<int,char>& a,
                    const pair<int,char>& b) const {
        if (a.first != b.first) return a.first < b.first; // max heap
        return a.second < b.second;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> f;
        for (char ch : s) {
            f[ch]++;
        }

        priority_queue<pair<int,char>,
                       vector<pair<int,char>>,
                       cmp> pq;

        // push frequencies into heap
        for (auto &it : f) {
            pq.push({it.second, it.first});
        }

        string res = "";
        int seat = 0;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            if (seat == 0 || res[seat - 1] != curr.second) {
                res.push_back(curr.second);
                seat++;
                curr.first--;
                if (curr.first > 0) pq.push(curr);
            } 
            else {
                if (pq.empty()) return "";

                auto p2 = pq.top();
                pq.pop();

                res.push_back(p2.second);
                seat++;
                p2.first--;
                if (p2.first > 0) pq.push(p2);

                pq.push(curr);
            }
        }
        return res;
    }
};

