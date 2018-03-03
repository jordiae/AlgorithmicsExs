#include <iostream>
#include <vector>
#include <set>

using namespace std;

int induced_subgraphs(vector<vector<int> > g, int s) {
	vector<int> degrees(g.size());
	for (int i = 0; i < degrees.size(); i++)
		degrees[i] = g[i].size();
    int ss = g.size();
    int d = 0;
    while (ss >= s) {
    	pair<int,int> min_deg = make_pair(-1,-1);
    	for (int i = 0; i < g.size(); i++) {
    		if ((min_deg.first == -1 or degrees[i] < min_deg.second) and degrees[i] >= 0) {
    			min_deg.first = i;
    			min_deg.second = degrees[i];
    		}
    	}
    	if (min_deg.second > d)
    		d = min_deg.second;
    	// esborrar el node en questio:
    	degrees[min_deg.first] = -1;
    	for (int i = 0; i < g[min_deg.first].size(); i++)
    	    degrees[g[min_deg.first][i]] -= 1;
    	ss--;
    }
	return d;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<vector<int> > g(n);
		
		for (int i = 0; i < m; i++) {
			int e0, e1;
			cin >> e0 >> e1;
			g[e0].push_back(e1);
			g[e1].push_back(e0);
		}
		int s;
		
		cin >> s;
		int d = induced_subgraphs(g,s);
		cout << d << endl;
	}
}
