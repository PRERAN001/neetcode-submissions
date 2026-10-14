class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string temp = "";

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int n = temp.size();

            if (n >= 2 &&
                temp[n - 1] == it.second &&
                temp[n - 2] == it.second) {

                if (pq.empty()) break;

                auto second = pq.top();
                pq.pop();

                temp += second.second;
                second.first--;

                if (second.first > 0)
                    pq.push(second);

                pq.push(it);
            } else {
                temp += it.second;
                it.first--;

                if (it.first > 0)
                    pq.push(it);
            }
        }

        return temp;
    }
};