#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Fraction {
    long long numerator;
    long long denominator;
    
    Fraction(long long num, long long denom) : numerator(num), denominator(denom) {
        simplify();
    }
    
    void simplify() {
        long long g = __gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
    }
    
    bool operator<(const Fraction &other) const {
        return numerator * other.denominator < denominator * other.numerator;
    }
};

Fraction maxBeauty(vector<int> &heights, int n) {
    stack<int> st;
    Fraction maxFraction(0, 1); // initialize with 0
    
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && heights[st.top()] < heights[i]) {
            int j = st.top();
            st.pop();
            
            int dist = i - j;
            int heightDiff = heights[i] - heights[j];
            Fraction currentFraction(dist - 1, heightDiff);
            
            if (maxFraction < currentFraction) {
                maxFraction = currentFraction;
            }
        }
        st.push(i);
    }
    return maxFraction;
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }
    
    Fraction best = maxBeauty(heights, n);
    
    // Print the best beauty score
    if (best.denominator == 1) {
        cout << best.numerator << endl;
    } else {
        cout << best.numerator << "/" << best.denominator << endl;
    }
    
    return 0;
}
