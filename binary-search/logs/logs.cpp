#include<bits/stdc++.h>

#define F first
#define S second
#define pb push_back

using namespace std;

bool isPossible(int m,int k, vector<int> a){
    
	int cuts = 0;

	int n = a.size() - 1;
	for (int i=0; i <= n; i++){
		cuts += a[i]/m;
		if (a[i]%m == 0){
			cuts--;
		}
	}

	return cuts <= k;
}

int solve(int n,int k, vector<int> a){

	int r = -1;
	int l = 0;
	int ans = -1;

	for(auto e: a){
		if (e>r){
			r = e;
		}
	}

	while (l<=r){

		int mid = (l+r)/2;

		bool eval = isPossible(mid, k, a);

		if (eval){
			ans = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}

	return ans;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	int k, aux;
	cin >> k;
	vector<int> a;

	while(cin >> aux){
		a.push_back(aux);
	}

	int res = solve(a.size(), k, a);
	cout << res;

	return 0;
}




/*
Logs


We have n logs of lengths a1,a2,⋯an.
We can cut these logs at most k times in total. When a log of length L is cut at a point 
whose distance from an end of the log is t (0<t<L), it becomes two logs of lengths t and L−t.
Find the shortest possible length of the longest log after at most k cuts, and return it after
rounding up to an integer.

Constraints:

1 <= n <= 2*10^5

0 <= k <= 10^9

1 <= ai <= 10^9

Example:

Input: n= 2, k =3, a= [7, 9]
 
Output: 4
Explanation: 
First, we will cut the log of length 7 at a point whose distance from an end of the log is 3.5,
resulting in two logs of length 3.5 each. Next, we will cut the log of length 9 at a point 
whose distance from an end of the log is 3, resulting in two logs of length 3 and 6.
Lastly, we will cut the log of length 6 at a point whose distance from an end of the log is 3.3,
resulting in two logs of length 3.3 and 2.7 .
In this case, the longest length of a log will be 3.5, which is the shortest possible result. 
After rounding up to an integer, the output should be 4.




*/