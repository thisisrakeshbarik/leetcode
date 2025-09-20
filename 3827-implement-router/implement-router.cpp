class Router {
private:
    int memoryLimit;
    queue<array<int,3>> q;
    unordered_set<string> seen;
    unordered_map<int, vector<int>> destTimes;
    unordered_map<int, int> startIdx; // sliding window for each destination

    string makeKey(int s, int d, int t) {
        return to_string(s) + "#" + to_string(d) + "#" + to_string(t);
    }

public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);
        if (seen.count(key)) return false;

        if ((int)q.size() == memoryLimit) {
            auto old = q.front(); q.pop();
            string oldKey = makeKey(old[0], old[1], old[2]);
            seen.erase(oldKey);
            startIdx[old[1]]++; // move start index forward
        }

        q.push({source, destination, timestamp});
        seen.insert(key);
        destTimes[destination].push_back(timestamp);
        if (!startIdx.count(destination)) startIdx[destination] = 0;
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};
        auto pkt = q.front(); q.pop();
        string key = makeKey(pkt[0], pkt[1], pkt[2]);
        seen.erase(key);
        startIdx[pkt[1]]++; // remove oldest timestamp logically
        return {pkt[0], pkt[1], pkt[2]};
    }

    int getCount(int destination, int startTime, int endTime) {
        if (!destTimes.count(destination)) return 0;
        auto &vec = destTimes[destination];
        int st = startIdx[destination];
        auto it1 = lower_bound(vec.begin() + st, vec.end(), startTime);
        auto it2 = upper_bound(vec.begin() + st, vec.end(), endTime);
        return it2 - it1;
    }
};
