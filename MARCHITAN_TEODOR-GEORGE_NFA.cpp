#include <bits/stdc++.h>
using namespace std;

ifstream in("date.in");
ofstream out("date.out");

int stareInitiala, nrStariFinale, nrTranzitii, nrCuvinte;
vector< int > stari, stariFinale;
vector< char > alfabet;
map < pair< int, char >, vector< int > > tranzitii;

vector< int > delta(int stare, char c) {
	return tranzitii[make_pair(stare, c)];
}

bool deltaTilda(int stare, char s[]) {
	if(strlen(s) == 0) {
		for(auto it: stariFinale) {
			if(stare == it) {
				return 1;
			}
		}
		return 0;
	}

	bool flag = 0;
	vector< int > v = delta(stare, s[0]);
	for(auto it: v) {
		flag |= deltaTilda(it, s + 1);
	}
	return flag;
}

int main() {

	int numarStari; in >> numarStari;
	stari.resize(numarStari);

	for(auto& it: stari) {
		in >> it;
	}

	int nrLitere; in >> nrLitere;
	alfabet.resize(nrLitere);

	for(auto& it: alfabet) {
		in >> it;
	}

	in >> stareInitiala >> nrStariFinale;
	stariFinale.resize(nrStariFinale);

	for(auto& it: stariFinale) {
		in >> it;
	}

	in >> nrTranzitii;
	for(int i = 0; i < nrTranzitii; ++i) {
		int x, y; char c;
		in >> x >> c >> y;
		tranzitii[make_pair(x, c)].push_back(y);
	}

	in >> nrCuvinte;
	for(int i = 0; i < nrCuvinte; ++i) {
		char cuvant[1001]; in >> cuvant;

		out << (deltaTilda(stareInitiala, cuvant) ? "DA" : "NU") << '\n';
	}

	return 0;
}