/*
Description
Given a TEXT which consists of a sequence of words. Each word is defined to be a sequence of contiguous characters of the alphabet (a, ..., z, A, ..., Z) and digits (0, 1, ..., 9). Other special characters are considered as delimiters between words. 
Write a program to count the number of occurrences o(w) of each word w of the given TEXT.
Input
The TEXT (each word of the TEXT has length <= 20)

Output
Each line contains a word w and o(w) (separated by a SPACE). The words (printed to lines of the stdout) are sorted in a lexicographic order. 

Example
Input
abc  def abc 
abc abcd def 

Output 
abc 3
abcd 1
def 2
*/
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text, word;
    map<string, int> word_count;

    // Đọc toàn bộ văn bản đầu vào
    while (getline(cin, text)) {
        for (char &c : text) {
            if (!isalnum(c)) c = ' '; // Chuyển ký tự đặc biệt thành dấu cách
        }

        // Dùng stringstream để tách từ
        stringstream ss(text);
        while (ss >> word) {
            word_count[word]++;
        }
    }

    // In kết quả theo thứ tự từ điển
    for (const auto &entry : word_count) {
        cout << entry.first << " " << entry.second << '\n';
    }

    return 0;
}
