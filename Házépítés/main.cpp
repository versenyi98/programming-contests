#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

map <int, vector<int>> elotte_van;
map <int, vector<int>> utana_van;

bool erintve[10000];

stack<int> b_utani_munkak;
queue<int> a_elotti_munkak;

int szamol_utana(int n) {

	if (erintve[n - 1]) return 0;

	erintve[n - 1] = true;
	int count = 0;

	for (int i = 0; i < utana_van[n].size(); i++) {
		count += szamol_utana(utana_van[n][i]);
	}

	a_elotti_munkak.push(n);
	return 1 + count;
}

int szamol_elotte(int n) {

	if (erintve[n - 1]) return 0;

	erintve[n - 1] = true;
	int count = 0;

	for (int i = 0; i < elotte_van[n].size(); i++) {
		count += szamol_elotte(elotte_van[n][i]);
	}

	b_utani_munkak.push(n);
	return 1 + count;
}

int varosok, megelozesek, a_munka, b_munka;

int main() {

	cin >> varosok >> megelozesek >> a_munka >> b_munka;

	while (megelozesek--) {
		int x, y;
		cin >> x >> y;
		elotte_van[y].push_back(x);
		utana_van[x].push_back(y);
	}

/*
	for (auto i : elotte_van) {
		cout << i.first << ":";
		for (auto j : i.second) {
			cout << j << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (auto i : utana_van) {
		cout << i.first << ":";
		for (auto j : i.second) {
			cout << j << " ";
		}
		cout << endl;
	}
*/
	int a_elott = szamol_elotte(a_munka);
	int b_utan = szamol_utana(b_munka);

	while (!a_elotti_munkak.empty()) {
		cout << a_elotti_munkak.front() << endl;
		a_elotti_munkak.pop();
	}
	cout << endl;
	while (!b_utani_munkak.empty()) {
		cout << b_utani_munkak.top() << endl;
		b_utani_munkak.pop();
	}
}
