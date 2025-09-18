class TaskManager {
    using T = tuple<int,int,int>; // {priority, taskId, userId}
    struct Comp {
        bool operator()(const T& a, const T& b) const {
            if (get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b); // higher priority first
            return get<1>(a) > get<1>(b); // higher taskId first
        }
    };

    unordered_map<int, pair<int,int>> info; // taskId -> {userId, priority}
    set<T, Comp> st;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int u = t[0], id = t[1], p = t[2];
            info[id] = {u, p};
            st.insert({p, id, u});
        }
    }

    void add(int userId, int taskId, int priority) {
        info[taskId] = {userId, priority};
        st.insert({priority, taskId, userId});
    }

    void edit(int taskId, int newPriority) {
        auto [u, oldP] = info[taskId];
        st.erase({oldP, taskId, u});
        info[taskId] = {u, newPriority};
        st.insert({newPriority, taskId, u});
    }

    void rmv(int taskId) {
        auto [u, p] = info[taskId];
        st.erase({p, taskId, u});
        info.erase(taskId);
    }

    int execTop() {
        if (st.empty()) return -1;
        auto [p, id, u] = *st.begin();
        st.erase(st.begin());
        info.erase(id);
        return u;
    }
};
