#include <iostream>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W; 
    
    int n;
    cin >> n;
    
    int totalArea = 0; 
    
    for (int i = 0; i < n; i++) {
        int hi, wi;
        cin >> hi >> wi;
        totalArea += hi * wi; 
    }
    

    if (totalArea == H * W) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl; 
    }
    
    return 0;
}

