#include <iostream>
#include <map>

using namespace std;

int n, m;
map<int, int> mp;
string result;

int main() {

    while (cin >> n >> m, m != 0) {

        mp.clear();

        result = to_string(n) + "/" + to_string(m) + " = ";
        result += to_string(n/m);

        if (n % m != 0) {
            string sub_result = "";
            
            int remainder = n % m;
            int index = 1;

            while (remainder != 0) {
                mp[remainder] = index;

                remainder *= 10;
                sub_result += to_string(remainder / m);
                remainder = remainder % m;

                if (mp[remainder] != 0) {
                    sub_result = sub_result.substr(0, mp[remainder] - 1) + "(" + sub_result.substr(mp[remainder] - 1) + ")";
                    break;
                }

                index++;
            }
            result += "." + sub_result;
        }

        for (int i = 0; i < result.length(); i++) {
            if (i && i % 50 == 0) {
                cout << endl;
            }
            cout << result[i];
        }
        cout << endl << endl;
        
    }
}