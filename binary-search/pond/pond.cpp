#include<bits/stdc++.h>

#define F first
#define S second
#define pb push_back

using namespace std;


bool check(int mid,int k, vector<vector<int>> grid){

	vector<vector<int>> prefix_sum;

	int n = grid.size();
	for (int i=0; i < n; i++){
		vector<int> aux(n+1, 0);
		prefix_sum.push_back(aux);
	}

	for (int i=0; i < n; i++){
		for (int j=0; j < n; j++){
			prefix_sum[i][j+1] = prefix_sum[i][j] + (grid[i][j] <= mid);
 		}	
	}

	for (int i=0; i < n - k + 1; i++){
		for (int j=0; j < n - k + 1; j++){
			int count = 0;
			for (int r=i; r < i+k; r++){
				count += prefix_sum[r][j+k] - prefix_sum[r][j];
			}
			if (count >= (k*k+1)/2){
				return true;
			}
 		}	
	}

	return false;
}


int solve(int n,int k, vector<vector<int>> grid){
    
	int l = grid[0][0];
	int r = grid[0][0];

	for (auto e: grid){
		for(auto ele: e){
			if (ele < l){
				l = ele;
			}
			if(ele > r){
				r = ele;
			}
		}
	}


	while(l < r){

		int mid = (l+r)/2;
		bool isPossible = check(mid, k, grid);

		if (isPossible){
			r = mid;
		}
		else{
			l = mid +1;
		}
	}

	return l;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;

	vector<vector<int>> grid;

	
	for (int i=0; i < n; i++){
		
		vector<int> aux;
		int ele;
		for (int j=0; j < n; j++){
			cin >> ele;
			aux.push_back(ele);
		}	

		grid.push_back(aux);
	}

	int res = solve(n, k, grid);
	cout << res;

	return 0;
}





/*
Pond
The land of a park  is an n×n grid with east-west rows and north-south columns. The height of the 
square at the i-th row from the north and j-th column from the west is given as grid i,j.
Takahashi, the manager, has decided to build a square pond occupying K×K squares in this park.
To do this, he wants to choose a square section of K×K squares completely within the park whose 
median of the heights of the squares is the lowest. Find the median of the heights of the squares
in such a section.
Here, the median of the heights of the squares in a K×K section is the height of the (⌊k^2/2⌋+1)-th 
highest square among the K^2 squares in the section, where ⌊x⌋ is the greatest integer not exceeding x.

Return the lowest median of the heights of the square.

Constraints:

1 <= n, k <= 800

0 <= grid[i][j] <= 10^9

Example:

Input: n= 3, k= 2, grid= [[1,7,0],[5,8,11],[10,4,2]]
 
Output: 4
 
Explanation: 
Let (i,j) denote the square at the i-th row from the north and j-th column from the west.for r in range(i, i + k)
We have four candidates for the 2×2 section occupied by the pond: 
{(1,1),(1,2),(2,1),(2,2)},{(1,2),(1,3),(2,2),(2,3)},{(2,1),(2,2),(3,1),(3,2)},{(2,2),(2,3),(3,2),(3,3)}.
When K=2, since ⌊ (2^2)/2 ⌋+1=3, the median of the heights of the squares in a section is 
the height of the 3-rd highest square, which is 5, 7, 5, 4 for the candidates above, respectively.
We should print the lowest of these: 4.
*/