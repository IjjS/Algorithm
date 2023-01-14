#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return (a.second == b.second) ? a.first < b.first : a.second < b.second;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> conf;

    int start, end;
    for (int i=0; i<n; i++) {
        cin >> start >> end;
        conf.push_back({start, end});
    }

    sort(conf.begin(), conf.end(), cmp);

    pair<int, int> currentConf = *conf.begin();
    int count = 1;

    for (vector<pair<int, int>>::iterator ir = conf.begin() + 1; ir != conf.end(); ir++) {
        if (currentConf.second <= (*ir).first) {
            currentConf = *ir;
            count++;
        }
    }

    cout << count;
}