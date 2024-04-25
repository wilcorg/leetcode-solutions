#include <bits/stdc++.h>

using namespace std;

class TimeMap {
public:
    TimeMap() = default;

    void set(const string &key, const string &value, int timestamp) {
        this->db[key].emplace_back(timestamp, value);
   }

    string get(const string &key, int timestamp) {
        auto& db_key = db[key];

        if (db_key.empty()) {
            return "";
        } else {
            int left = 0;
            int right = (int) db_key.size() - 1;

            while (left <= right) {
                int mid = (left + right) / 2;
                int cur = db_key[mid].first;

                if (timestamp == cur) {
                    return db_key[mid].second;
                } else if (timestamp < cur) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            // by default left points >= pair.first
            // if the key for selected timestamp is absent
            // we should decrease index by one to ensure that pair.first < timestamp
            if (left == 0) {
                return "";
            } else {
                return db_key[left - 1].second;
            }
        }
    }

private:
    unordered_map<string, vector<pair<int, string>>> db;
};

int main() {
    auto *obj = new TimeMap();

    obj->set("love", "high", 10);
    obj->set("love", "low", 20);
    cout << obj->get("love", 5) << endl;
    cout << obj->get("love", 10) << endl;
    cout << obj->get("love", 15) << endl;
    cout << obj->get("love", 20) << endl;
    cout << obj->get("love", 25) << endl;

    free(obj);
    return 0;
}