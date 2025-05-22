/*Cho dãy a = a1, a2, ..., an. Một dãy con của dãy a được định nghĩa là 1 dãy gồm các phần tử liên tiếp đứng cạnh nhau của a (ai, ai+1,..., aj). 
Hãy tìm dãy con tăng dần có số phần tử lớn nhất.
Input
Dòng 1: số nguyên dương n (2 <= n <= 100000)
Dòng 2: dãy a1, a2, . . ., an (1 <= ai <= 1000000)
Output
Ghi ra số phần tử của dãy con tìm được.
Example
Input 
10
10 2 3 4 5 9 8 5 8 10 
20
1 2 3 4 5 6 7 8 9 10 45 1 2 3 4 5 6 7 8 9
Output 
5*/
#include <bits/stdc++.h>

using namespace std;

void max_seq(vector<int>& a) {
    int n = a.size();
    vector<int> dp(n, 1);
    

    cout << *max_element(dp.begin(), dp.end()) << endl;
}

int  main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    max_seq(a);

    return 0;
}