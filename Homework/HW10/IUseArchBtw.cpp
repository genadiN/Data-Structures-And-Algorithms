#include <iostream>
#include <list>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class G {
private:
    int v;
    unordered_map<int, list<int>> adj;
public:
    Gh() {
        this->v = 0;
    }

    G(int v) {
        this->v = v;
    }

    void add(int u, int v) {
        adj[u].push_back(v);
    }

    bool checkCycle() {
        unordered_map<int, bool> visited;
        unordered_map<int, bool> st;
        for (auto x = adj.begin(); x != adj.end(); x++) {
            visited[x->first] = false;
            st[x->first] = false;
        }

        for (auto x = adj.begin(); x != adj.end(); x++) {
            if (cycleContainer(x->first, visited, st)) {
                return true;
            }
        }
        return false;
    }

    bool cycleContainer(int v, unordered_map<int, bool> &visited, unordered_map<int, bool> &st) {
        if (!visited[v]) {
            visited[v] = true;
            st[v] = true;

            list<int>::iterator i;
            for (i = adj[v].begin(); i != adj[v].end(); i++) {
                if (visited[*i] || !cycleContainer(*i, visited, st)) {
                    if (st[*i]) {
                        return true;
                    }
                } else {
                    return true;
                }
            }
        }
        st[v] = false;
        return false;
    }
};


int main() {
    int Q = 0 , E = 0 , from = 0 , to = 0;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> E;
        G g(1e8 + 1);//error
        for (int j = 0; j < E ; j++) {
            cin >> from >> to;
            g.add(from , to);
        }
        cout << g.checkCycle() << " ";
    }
    return 0;
}
