#include<bits/stdc++.h>

#define F first
#define S second
#define pb push_back

using namespace std;

bool minEatingSpeed(vector<int> piles,int k, int h) {
    
	int hours_needed = 0;

	int n = piles.size()-1;

	for (int i=0; i <= n; i++){
		
		hours_needed += piles[i]/k;
		if (piles[i]%k > 0){
			hours_needed++;
		}

	}

    return hours_needed <= h;
}

int binarySearch(vector<int> piles, int upper, int h){

	int l = 1;
	int r = upper;
	int ans = -1;

	while(l <= r){

		int mid = (l+r)/2;

		bool isPossible = minEatingSpeed(piles, mid, h);

		if (isPossible){
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

	int h = 0;
	cin >> h ;

	int aux;
	vector<int> piles;

	int max = -1;

	while(cin >> aux){
		piles.push_back(aux);
		if (aux > max){
			max = aux;
		}
	}

	int res = binarySearch(piles, max, h);
	cout << res;

	return 0;
}

/*
Koko Eating Bananas


Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. 
The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. 
Each hour, she chooses some pile of bananas and eats k bananas from that pile.
If the pile has less than k bananas, she eats all of them instead and will not eat any more
bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the 
guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.

Constraints:

1 <= piles.length <= 10^4

piles.length <= h <= 10^9

1 <= piles[i] <= 10^9

Example :

Input: piles = [30,11,23,4,20], h = 5
 
Output: 30
*/