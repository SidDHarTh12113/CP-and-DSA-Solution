#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define mod 1000000007
bool Cycle_Detection_helper(map<int, vector<int>>m, bool *visited, int src, int parent) {
    visited[src] = true;
    for (auto nbr : m[src]) {
        if (visited[nbr] == false) {
            bool cycle_found = Cycle_Detection_helper(m, visited, nbr, src);
            if (cycle_found) {
                return true;
            }
        }
        else if (nbr != parent) {
            return true;
        }
    }

    return false;
}
bool Cycle_Detection(map<int, vector<int>>m, int n) {
    bool visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    int src;
    cin >> src;
    return Cycle_Detection_helper(m, visited, src, -1);
}
int main() {
    fio;
    int n;
    cin >> n;
    map<int, vector<int>>m;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        m[x].push_back(y);
        m[y].push_back(x);
    }
    if (Cycle_Detection(m, n)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    for (auto p : m) {
        cout << p.first << "-->";
        for (auto p1 : p.second) {
            cout << p1 << " ";
        }
        cout << endl;
    }
    return 0;
}