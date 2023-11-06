#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
    string X, Y;
    cin >> X >> Y;
    int lengthX = X.length();
    int lengthY = Y.length();

    int dp[lengthX + 1][lengthY + 1];
    for (int i = 0; i <= lengthY; i++){
        dp[0][i] = 0;
    }
    for (int i = 0; i <= lengthX; i++){
        dp[i][0] = 0;
    }

    for (int i = 1; i <= lengthX; i++){
        for (int j = 1; j <= lengthY; j++){
            if (X[i - 1] == Y[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // Do dai con chung lon nhat
    cout << dp[lengthX][lengthY] << endl;

    // Bang buoc lam quy hoach dong
    for (int i = 0; i <= lengthX; i++){
        for (int j = 0; j <= lengthY; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
