#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_set<string> st;
    st.reserve(n * 2);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        st.insert(s);
    }

    while (m--) {
        string s;
        cin >> s;

        bool found = false;

        for (int i = 0; i < s.size() && !found; i++) {
            char original = s[i];

            for (char c : {'a', 'b', 'c'}) {
                if (c == original) continue;

                s[i] = c;
                if (st.count(s)) {
                    found = true;
                    break;
                }
            }

            s[i] = original;
        }

        cout << (found ? "YES\n" : "NO\n");
    }
}
