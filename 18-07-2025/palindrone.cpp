#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        int v=x;
        int a;
        long long sum=0;
        while(x>0)
        {
            a=x%10;
            sum=sum*10+a;
            x=x/10;
        }
        if(v==sum) return true;
        else{ return false;}
        return false;
    }
};
int main() {
    Solution sol;
    int number;
    cout << "Enter an integer: ";
    cin >> number;
    if (sol.isPalindrome(number)) {
        cout << number << " is a palindrome." << endl;
    } else {
        cout << number << " is not a palindrome." << endl;
    }
    return 0;
}