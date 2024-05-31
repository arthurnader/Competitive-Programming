#include<bits/stdc++.h>

#define F first
#define S second
#define pb push_back

using namespace std;

bool check_value(vector<int> coins, int value, int K){

	int c = 0;
	int acum = 0;
	
	for (int i = 0; i < coins.size(); i++){

		acum += coins[i];

		if (acum >= value){
			c++;
			acum = 0;
			if (c == K){
				return true;
			}
		}
	}

	return false;
}

int binary_search(vector<int> coins, int K, int lower, int upper){

	int l = lower;
	int r = upper;

	int ans = -1;

	while (l<=r){

		int mid = (l+r)/2;

		bool res = check_value(coins, mid, K); 

		if (res){
			ans = mid;
			l = mid+1;
		}

		else{
			r = mid-1;
		}
	}

	return ans;
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	int K;
	cin >> K;

	vector<int> coins;

	int aux;

	cin >> aux;
	coins.push_back(aux);

	int s = aux; 
	int m = aux;

	while (cin >> aux){

		coins.push_back(aux);
		
		s += aux;
		if (aux < m){
			m = aux;
		}
	}

	int r = binary_search(coins, K, m, s);
	cout << r;


	return 0;
}




/*
You are playing a game with your k friends. You have an array of N coins, at each index i
you have a coin of value a[i]. Your task is to divide the coins, among a group of k friends
by doing consecutives segments (k-subarrays) of the array. Each friend will get a total sum
of the coins in tha subarray. Since all your friends are greedy, and they will pick the 
largest k-1 segments and you will get the smallest segment. Find out the maximum value you
can make by making an optimal partition.

We need to maximize the min partition.

Search space: 
- minimum is the smallest element in array.
- maximum is the sum of all elements.

*/