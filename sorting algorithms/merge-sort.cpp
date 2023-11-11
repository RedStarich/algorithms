#include <iostream>
#include <vector>
using namespace std;

vector<int> merge_fun(vector<int> &v1, vector<int> &v2) {
    vector<int> merge;

    int l = 0;
    int r = 0;
    int n = v1.size();
    int m = v2.size();

    while (l < n && r < m) {
        if (v1[l] < v2[r]) {
            merge.push_back(v1[l]);
            l++;
        } else {
            merge.push_back(v2[r]);
            r++;
        }
    }

    while (l < n) {
        merge.push_back(v1[l]);
        l++;
    }

    while (r < m) {
        merge.push_back(v2[r]);
        r++;
    }
    return merge;
}

void split(vector<int> &v) {
    int n = v.size();
    if (n > 1) {
        int mid = n / 2;

        vector<int> l(v.begin(), v.begin() + mid);
        vector<int> r(v.begin() + mid, v.end());

        split(l);
        split(r);

        v = merge_fun(l, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    split(arr);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    }
}
