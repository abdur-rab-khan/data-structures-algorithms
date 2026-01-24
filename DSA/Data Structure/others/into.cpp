#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define SQ(a) a* a

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
    // Make input and output more efficient.
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a = 123456789;
    long long b =
        a * a;  // 64bit >> ❌ Wrong Answer -- Because the return type of a * a is int. There is to
                // solution make "a" to long long -- use typecasting "(long long)a * a"

    double floatValue;             // 64-bit
    long double floatValueSecond;  // 80-bit

    floatValue = 0.3 * 3 + 0.1;

    printf("%.9f \n",
           floatValue);  // ❌ Getting not accurate answer because it goes beyond to "%.9f" that
                         // causing "ROUND ERROR".

    printf("%.20f \n", floatValue);  // ❌ To print these large float numbers, We can't use "cout"
                                     // because it does not properly work with these large numbers.

    // cout << pow(10, 5) << "\n"; It does not work properly as we know in the above why.

    printf("%llu \n", pow(10, 5));

    // It is ricky to compare two floating number with == operators.
    // Because may be the value is equal but they are not because of precision errors.
    // A better way is to assume the difference between two numbers are equal if the difference
    // between them is less the ∈, where ∈ is a small number.

    if (abs(a - b) < 1e-9) {
        cout << "Number is equal" << endl;
    }

    /*
    SHORTENING CODE
    >> In scenario where you want to build program fast as possible. So for that you can use
    "typedef" to define shorter names for datatypes.
    >> typedef long long ll --> We can you ll instead of long long

    >> It can you use in complex types. For Example, In the below vi for vector<int> and pi for
    pair<int,int>.
    */

    long long a1 = 123456789;
    ll b1 = 987654321;

    cout << a1 * b1 << "\n";

    vi nums;

    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.PB(4);

    for (int const n : nums) {
        cout << n << " ";
    }

    cout << endl;

    /*
    MACROS

    >> A macro means that certain string in the code will be changed before the compilation.
    >> For Example:

    #define F first
    #define S second
    #define PB push_back

    ----------------- MACRO CAN ALSO ACCEPT PARAMETERS ------------------------------

    #define REP(i,a,b) for(int i = a; i <=b i++)

    v.PB(1); >> Instead of v.push_back(1);

    int i = 0
    REP(i,1,5){
        cout << i << endl;
    }
    */

    REP(i, 1, 5) {
        cout << i << " ";
    }

    cout << endl << SQ(2) << endl;

    return 0;
}