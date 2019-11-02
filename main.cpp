#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    string line, word1, word2;
    int blanklines=0;
    int i=0;
    size_t pos_start, pos_end, delim_len=1;
    unordered_map<string, string> dictionary;

    while(getline(cin, line)) {
        if ( line.empty() ) {
            ++blanklines;
        }

        pos_start = 0;
        i=0;

        while ((pos_end = line.find(" ", pos_start)) != string::npos) {
            if(i == 0)
                word1 = line.substr(pos_start, pos_end - pos_start);
            else
                word2 = line.substr(pos_start, pos_end - pos_start);

            pos_start = pos_end + delim_len;

            ++i;
        }

        if(!blanklines) {
            word2 = line.substr(pos_start);
            dictionary.insert({word2, word1});
        } else {
            word1 = line.substr(pos_start);
            if(!word1.empty()) {
                auto result = dictionary[word1];
                if(result.empty())
                    result = "eh";

                cout<< result << endl;
            }
        }

        if(blanklines == 2)
            break;
    }
}