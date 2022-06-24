#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <numeric>
#include <string_view>
#include <ctype.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(vector<int> arr) {
    double numPos = 0;
    double numNeg = 0;
    double numZer = 0;
    double arrLen = arr.size();
    int ind = 0;
    while (ind < arrLen) {
        if (arr[ind] > 0) {
            numPos++;
        }
        else if (arr[ind] < 0) {
            numNeg++;
        }
        else {
            numZer++;
        }
        ind++;
    }
    cout << numPos/arrLen << setprecision(6) << endl;
    cout << numNeg/arrLen << setprecision(6) << endl;
    cout << numZer/arrLen << setprecision(6) << endl;
}

int main()
{
    string n_temp;
    cout << "Please input the number of integers: ";
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    cout << "Please input the integers: ";
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    plusMinus(arr);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](int c) {return !isspace(c);})
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(),  [](int c) {return !isspace(c);}).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
