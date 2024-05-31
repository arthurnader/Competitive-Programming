#include<bits/stdc++.h>

#define F first
#define S second
#define pb push_back

using namespace std;


bool check_distance(vector<int> nests, int num_birds, int distance){

	int birds_in_nests = 1;
	int last_nest_occuped = 0;

	for(int i=1; i < nests.size(); i++){

		if(nests[i] - nests[last_nest_occuped] >= distance){
			last_nest_occuped = i;
			birds_in_nests++;
		}

		if(birds_in_nests == num_birds){
			return true;
		}
	}

	return false;
}

int binary_search(vector<int> nests, int birds){

	sort(nests.begin(), nests.end());

	int l = 1;
	int r = nests[nests.size()-1] - nests[0];

	int largest = -1;

	while (l <= r){

		int mid = (l+r)/2;
		bool ans = check_distance(nests, birds, mid);

		if (ans){
			l = mid+1;
			largest = mid;
		}

		else{
			r = mid-1;
		}

	}


	return  largest;
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	int num_birds = 0;
	cin >> num_birds;

	int aux = 0;
	vector<int> nests;
	while (cin >> aux){
		nests.push_back(aux);
	}

	int res = binary_search(nests, num_birds);
	cout << res;

	return 0;
}

/*
There is a long wire along a straight line, which contains N bird nests 
at positions x1, x2, ..., xN.
There are B (B<=N) birds, which become angry towards each other once put into a nest.
To put the birds from hurting each other, you want to assign birds to nests such that minimun
distance between any two bird is as large as possible. What is the largest minimum distance?

Binary search on the distance

3
1 11 14 15 20 21

*/