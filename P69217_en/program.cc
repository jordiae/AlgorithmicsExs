#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {
	queue<string> Q;
	vector<queue<string> > v('z'-'a'+1,Q);
	string s;
	while (cin >> s)
		Q.push(s);
	for(int i = Q.front().size() - 1; i >= 0; i--) { // Assumim que totes les paraules tindran la mateixa mida
		while (not Q.empty()) {
			string w = Q.front();
			Q.pop();
			v[w[i]-'a'].push(w);
		}
	    for (int j = 0; j < v.size(); j++) {
		    while (not v[j].empty()) {
		        Q.push(v[j].front());
		        v[j].pop();
	        }
	    }
	}
	
	bool first = true;
	while (not Q.empty()) {
		if (not first)
			cout << " ";
		else
			first = false;
		cout << Q.front();
		Q.pop();
	}
	cout << endl;
}