#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

bool isPerfectSquare(int num) {
    
    int l = 1;
    int r = 65536;
    
    
    while(l<=r){
        
        int mid = (l+r)/2;
        
        int res = mid*mid;
        
        if (res == num){
            return true;
        }
        
        else if(res<num){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    
    
    return false;
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	int num;
	cin >> num;

	bool ans = isPerfectSquare(num);
	cout << ans;


	return 0;
}




/*
Valid Perfect Square


Given a positive integer num, write a function which returns True if num is a perfect square else False.

NOTE: Do not use any built-in library function such as sqrt.

Constraints:

1 <= num <= 2^31 - 1

Example 1:

Input: num = 16
 
Output: true
Example 2:

Input: num = 8
 
Output: false
*/