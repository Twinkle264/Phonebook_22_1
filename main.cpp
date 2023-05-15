#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void separation(string &request, string &first, string &second) {
    int space;
    space = request.find(' ');

    for (int i = 0; i < space; ++i) {
        first += request[i];
    }
    for (int i = space + 1; i < request.length(); ++i) {
        second += request[i];
    }
}

void
add(map<string, string> &numberToSurname, map<string, vector<string>> &surnameToNumber, string &first, string &second) {
    numberToSurname.insert(make_pair(first, second));
    surnameToNumber[second].resize(surnameToNumber[second].size() + 1);
    auto it = surnameToNumber.find(second);
    it->second[surnameToNumber[second].size() - 1] = first;
}

void findSurname(map<string, string> &numberToSurname, string &request) {
    auto it = numberToSurname.find(request);

    if (it == numberToSurname.end()) {
        cerr << "Error request!" << endl;
    } else {
        cout << it->second;
    }
}

void findNumber(map<string, vector<string>> &surnameToNumber, string &request) {
    auto it = surnameToNumber.find(request);

    if (it == surnameToNumber.end()) {
        cerr << "Error request!" << endl;
    } else if (it->first.length() > 0) {
        for (int i = 0; i < surnameToNumber[request].size(); ++i) {
            cout << it->second[i] << endl;
        }
    }
}

int main() {
    map<string, string> numberToSurname = {{"34-14-48", "Ivanov"},
                                           {"34-14-49", "Ivanov"},
                                           {"34-90-87", "Petrov"},
                                           {"51-48-30", "Sidorov"}};
    map<string, vector<string>> surnameToNumber = {{"Ivanov",  {"34-14-48", "34-14-49"}},
                                                   {"Petrov",  {"34-90-87"}},
                                                   {"Sidorov", {"51-48-30"}}};

    string request;

    cout << "\tTo add an entry, enter the number and surname." << endl;
    cout << "\tFind out the number - enter the last name." << endl;
    cout << "\tFind out the last name - enter the number." << endl;
    cout << "\tType \"exit\" to end the program" << endl;

    while (request != "exit") {
        cout << endl << "Enter a request: ";
        getline(cin, request);

        string first, second;

        if (request != "exit") {
            separation(request, first, second);

            if (!first.empty() and !second.empty()) {
                add(numberToSurname, surnameToNumber, first, second);
            } else if (request[0] >= '0' and request[0] <= '9') {
                findSurname(numberToSurname, request);
            } else {
                findNumber(surnameToNumber, request);
            }
        }
    }

    return 0;
}
