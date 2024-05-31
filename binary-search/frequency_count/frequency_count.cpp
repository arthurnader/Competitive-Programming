#include<bits/stdc++.h>

#define F first
#define S second
#define pb push_back

using namespace std;


int lower_bound(vector<int> l, int k){

	int left = 0;
	int right = l.size()-1;
	int mid = 0;

	int ans = -1;

	while(left <= right){

		mid = (left+right)/2;

		if(l[mid] == k){
			ans = mid;
			right = mid-1;
		}
		else if(l[mid] > k){
			right = mid-1;
		}
		else{
			left = mid+1;
		}
	}

	return ans;
}

int upper_bound(vector<int> l, int k){

	int left = 0;
	int right = l.size()-1;
	int mid = 0;

	int ans = -1;

	while(left <= right){

		mid = (left+right)/2;

		if(l[mid] == k){
			ans = mid;
			left = mid+1;
		}
		else if(l[mid] > k){
			right = mid-1;
		}
		else{
			left = mid+1;
		}
	}

	return ans;
}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	int key, aux;
	cin >> key;

	vector<int> v;

	while(cin >> aux){

		v.push_back(aux);

	}


	int freq = upper_bound(v, key) - lower_bound(v, key) + 1;
	cout << freq;


	return 0;
}

/*
Given a sorted array which can contain repeated elements, and an element K, we need to find
the frequency of the given element.

Input array:
[0,1,1,1,1,2,2,2,3,4,4,5,10]
Key = 3
Output: 3
*/
