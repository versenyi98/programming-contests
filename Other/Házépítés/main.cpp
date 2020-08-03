#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

map <int, vector<int>> megelozo;
map <int, vector<int>> rakovetkezo;

bool erintve[10000];

stack<int> b_utani_munkak;
queue<int> a_elotti_munkak;
queue<int> b_elotti_munkak;
queue<int> maradek;

int munkak, megelozesek, a_munka, b_munka;

int mennyi_elotte(int n, int bound, queue<int>& q) {

	if (n == bound) return -1;
	if (erintve[n - 1] && n != b_munka) return 0;

	erintve[n - 1] = true;
	int count = 0;

	for (int i = 0; i < megelozo[n].size(); i++) {
		count += mennyi_elotte(megelozo[n][i], bound, q);
	}

	if (n == b_munka) return count;
	q.push(n);
	return 1 + count;
}

void kezel_maradek(int n) {

	if (erintve[n - 1]) return;
	erintve[n - 1] = true;

	for (int i = 0; i < megelozo[n].size(); i++) {
		kezel_maradek(megelozo[n][i]);
	}

	maradek.push(n);
}

int mennyi_utana(int n) {

	if (erintve[n - 1]) return 0;

	erintve[n - 1] = true;
	int count = 0;

	for (int i = 0; i < rakovetkezo[n].size(); i++) {
		count += mennyi_utana(rakovetkezo[n][i]);
	}

	b_utani_munkak.push(n);
	return 1 + count;
}

int main() {

	cin >> munkak >> megelozesek >> a_munka >> b_munka;

	while (megelozesek--) {
		int x, y;
		cin >> x >> y;
		megelozo[y].push_back(x);
		rakovetkezo[x].push_back(y);
	}

	int a_elott = mennyi_elotte(a_munka, -1, a_elotti_munkak);
	int b_utan = mennyi_utana(b_munka);
	int b_elott = mennyi_elotte(b_munka, a_munka, b_elotti_munkak);

	for (int i = 0; i < munkak; i++) {
		kezel_maradek(i + 1);
	}

	cout << munkak - a_elott - b_utan << endl;
	bool ws = false;
	while (!a_elotti_munkak.empty()) {
		if (ws) cout << " ";
		cout << a_elotti_munkak.front();
		a_elotti_munkak.pop();
		ws = true;
	}

	while (!b_elotti_munkak.empty()) {
		cout << " " << b_elotti_munkak.front();
		b_elotti_munkak.pop();
	}

	while (!maradek.empty()) {
		cout << " " << maradek.front();
		maradek.pop();
	}

	while (!b_utani_munkak.empty()) {
		cout << " " << b_utani_munkak.top();
		b_utani_munkak.pop();
	}
	cout << endl;
}