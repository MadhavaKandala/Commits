#include <iostream>  
#include <string>  

using namespace std;  

bool canMakeEqual(const string& S, const string& T) {  
    int countA_S = 0, countB_S = 0;  
    int countA_T = 0, countB_T = 0;  

    // Count occurrences of 'a' and 'b' in S  
    for (char c : S) {  
        if (c == 'a') countA_S++;  
        else countB_S++;  
    }  

    // Count occurrences of 'a' and 'b' in T  
    for (char c : T) {  
        if (c == 'a') countA_T++;  
        else countB_T++;  
    }  

    // To make S equal to T, the number of 'b's must match  
    // The number of 'a's in S can be converted to 'ab's hence:  
    // countA_S + countB_S must be equal to countA_T + countB_T  
    return (countB_S >= countB_T) && (countA_S + countB_S >= countA_T + countB_T);  
}  

int main() {  
    int T;  
    cin >> T;  
    while (T--) {  
        int N, M;  
        cin >> N >> M;  
        string S, T;  
        cin >> S >> T;  

        if (canMakeEqual(S, T)) {  
            cout << "Yes" << endl;  
        } else {  
            cout << "No" << endl;  
        }  
    }  
    return 0;  
}