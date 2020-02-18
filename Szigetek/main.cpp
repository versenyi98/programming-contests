#include <bits/stdc++.h>

using namespace std;

long long childs_num[20000];
bool taken[20000];
long long primes_until_20k[20000];
long long primes_size = 0;
vector<long long> childs[20000];

map<long long, long long> in_productum;

void calc_primes() {

    long long i = 2;
    while (i != 20000) {
        long long div = 0;
        for (long long k = 2; k <= sqrt(i); k++) {
            if (i % k == 0) {
                div++;
                break;
            }
        }

        if (div == 0) {
            primes_until_20k[primes_size++] = i;
        }
        i++;
    }
}

void divide_to_primes(long long num, long long val) {

    long long ind = 0;
    while (num != 1) {
        if (num % primes_until_20k[ind] == 0) {
            in_productum[primes_until_20k[ind]] += val;
            num = num / primes_until_20k[ind];
        } else {
            ind++;
        }
    }
}

long long get_size_of_childs(long long i) {

    if (taken[i]) return childs_num[i];
    taken[i] = true;

    long long ret = childs[i].size();

    for (auto j : childs[i]) {
        ret += get_size_of_childs(j);
    }

    childs_num[i] = ret;

    return childs_num[i];
}

long long pow(long long n, long long k) {

    long long prod = 1;

    for (long long i = 0; i < k; i++) {
        prod = (prod * n) % 1000000007;
    }

    return prod;
}

int main() {

    calc_primes();

    long long n;
    cin >> n;

    for (long long i = 0; i < n; i++) {
        long long t;
        cin >> t;
        taken[i] = false;

        for (long long j = 0; j < t; j++) {
            long long l;
            cin >> l;

            childs[i].push_back(l - 1);
        }
    }

    for (long long i = 0; i < n; i++) {
        get_size_of_childs(i);
    }

    for (long long i = 0; i < n; i++) {
        divide_to_primes(++childs_num[i], -1);
    }

    for (long long i = 1; i <= n; i++) {
        divide_to_primes(i, +1);
    }

    long long prod = 1;

    for (auto i : in_productum) {
        prod = prod * pow(i.first, i.second);
        prod = prod % 1000000007;
    }

    cout << prod << endl;

    return 0;
}