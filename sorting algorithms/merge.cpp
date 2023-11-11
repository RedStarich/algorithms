#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    int n;
    cin>>n;
    vector <int> v1;

    for(int i=0; i<n; i++) {
        int tmp;
        cin>>tmp;
        v1.push_back(tmp);
    }

    int m;
    cin>>m;
    vector <int> v2;

    for (int j=0; j<m; j++) {
        int tmp;
        cin>>tmp;
        v2.push_back(tmp);
    }

    vector <int> merge;

    int l=0;
    int r=0;

    while (l<n && r<m) {
        if (v1[l]<v2[r]) {
            merge.push_back(v1[l]);
            l++;
        }
        else {
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


    for (int z=0; z<n+m; z++) {
        cout<<merge[z]<<' ';
    }
}