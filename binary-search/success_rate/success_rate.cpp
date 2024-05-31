#include<bits/stdc++.h>

#define F first
#define S second
#define pb push_back

using namespace std;

int check(int den, int x, int y, int p, int q){

	int should_be = (den*p)/q;

	if(x < should_be and should_be < (x + den - y)){
		return true;
	}

	return false;
}

long long solve(int x,int y,int p, int q){
    
	int l = 1;
	int r = y;


	int ans = -1;

	while(l <= r){

		int mid = (l+r)/2;
		bool resp = check(mid*q, x, y, p, q);

		if(resp){
			ans = mid*q - y;
			r = mid-1;
		}
		else{
			l = mid+1;
		}

	}

	return ans;

}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	int x, y, p, q;
	cin >> x >> y >> p >> q;
    
	long long res = solve(x, y, p ,q);
	cout << res;


	return 0;
}



/*
Success Rate


You are an experienced Coding Minutes user. Today you found out that during your activity 
on Coding Minutes you have made y submissions, out of which x have been successful. 
Thus, your current success rate on Coding Minutes is equal to x / y
Your favorite rational number in the [0,1] range is p / q. Now you wonder: what is the 
smallest number of submissions you have to make if you want your success rate to be p / q.
Return the minimum number of submissions you need to make if you want your success rate to 
be equal to your favorite rational number or -1 if this is impossible to achieve.
Note: It is guaranteed that p / q is an irreducible fraction.

Constraints:

0 <= x < y <= 10^9

0 <= p < q <= 10^9

y>0 , q>0

Example 1:

Input: x= 7, y= 14, p= 3, q= 8
 
Output: 10
 
Explanation: You have to make 2 successful and 8 unsuccessful submissions. 
Your success rate will be equal to 9/24, or 3/8.
Example 2:

Input: x= 5, y= 6, p= 1, q= 1
 
Output: -1
 
Explanation: The only unsuccessful submission breaks your hopes of having the success 
rate equal to 1.

*/