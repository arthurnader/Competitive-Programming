#include<bits/stdc++.h>

#define F first
#define S second
#define pb push_back

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}

int findRoom(vector<vector<int>> rooms, pair<int, int> indexes, int id, int size){

	int l = indexes.first;
	int r = indexes.second; 


	if(l == r and rooms.size() > 1){
		if( r == rooms.size()-1){
			l--;
		}
		else{
			r++;
		}
	}

	while(l >=0 or r < rooms.size()){

		if(l==-1){
			if(rooms[r][1] >= size){
				return rooms[r][0];
			}
			else{
				r++;
			}
		}
		else if(r==rooms.size()){
			if(rooms[l][1] >= size){
				return rooms[l][0];
			}
			else{
				l--;
			}
		}
		else{
			if(abs(rooms[l][0] - id) <= abs(rooms[r][0] - id)){
				if(rooms[l][1] >= size){
					return rooms[l][0];
				}
				else{
					l--;
				}
			}
			else{
				if(rooms[r][1] >= size){
					return rooms[r][0];
				}
				else{
					r++;
				}
			}
		}
	}


	return -1;
}	


pair<int, int> findIndices(vector<vector<int>> rooms, int id){

	int left_close = 0;
	int right_close = rooms.size()-1;
	int l = 0;
	int r = rooms.size()-1;

	while(l <= r){

		int mid = (l+r)/2;

		if (rooms[mid][0] == id){
			return make_pair(mid, mid);
		}
		else if(rooms[mid][0] > id){
			right_close = mid;
			r = mid - 1;
		}
		else{
			left_close = mid;
			l = mid + 1;
		}
	}

	return make_pair(left_close-1, right_close-1);
}


vector<int> closestRoom(vector<vector<int>> rooms, vector<vector<int>> queries) {

	vector<int> ans;

	sort(rooms.begin(), rooms.end(), compare);


	for (int i = 0; i < queries.size(); i++){

		int id = queries[i][0];
		int size = queries[i][1];
 
		pair<int, int> indexes = findIndices(rooms, id);
		

/*		cout << "Parameters of findRoom - ID: " << id << ", Size: " << size << endl;

		// Imprimir os elementos do vetor rooms
		cout << "Rooms: ";
		for (const auto& room : rooms) {
		    cout << "[" << room[0] << ", " << room[1] << "] ";
		}
		cout << endl;

		// Imprimir os elementos da pair indexes
		cout << "Indexes: [" << indexes.first << ", " << indexes.second << "]" << endl;*/


		int res = findRoom(rooms, indexes, id, size);
		ans.push_back(res);
	}

    return ans;    
}




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	vector<vector<int>> rooms, queries;

	int num_rooms, num_queries, aux;
	cin >> num_rooms;

	for (int i=0; i < num_rooms; i++){
		
		vector<int> aux_list;
		cin >> aux;
		aux_list.push_back(aux);
		cin >> aux;
		aux_list.push_back(aux);
		rooms.push_back(aux_list);
	}

	cin >> num_queries;
	for (int i=0; i < num_queries; i++){
		
		vector<int> aux_list;
		cin >> aux;
		aux_list.push_back(aux);
		cin >> aux;
		aux_list.push_back(aux);
		queries.push_back(aux_list);
	}

	vector<int> answer = closestRoom(rooms, queries);
	
	for(auto e: answer){
		cout << e << " ";
	}

	return 0;
}

/*
Closest Room
There is a hotel with n rooms. The rooms are represented by a 2D integer array rooms where 
rooms[i] = [roomIdi, sizei] denotes that there is a room with room number roomIdi and size 
equal to sizei. Each roomIdi is guaranteed to be unique.
You are also given k queries in a 2D array queries where queries[j] = [preferredj, minSizej].
The answer to the jth query is the room number id of a room such that:
The room has a size of at least minSizej, and
abs(id - preferredj) is minimized, where abs(x) is the absolute value of x.
If there is a tie in the absolute difference, then use the room with the smallest such id. 
If there is no such room, the answer is -1.
Return an array answer of length k where answer[j] contains the answer to the jth query.

Constraints:

n == rooms.length

1 <= n <= 10^5

k == queries.length

1 <= k <= 10^4

1 <= roomIdi, preferredj <= 10^7

1 <= sizei, minSizej <= 10^7

Example :

Input: rooms = [[2,2],[1,2],[3,2]], queries = [[3,1],[3,3],[5,2]]
 
Output: [3,-1,3]
 
Explanation: The answers to the queries are as follows:
Query = [3,1]: Room number 3 is the closest as abs(3 - 3) = 0, and its size of 2 is at least 1.
The answer is 3.
Query = [3,3]: There are no rooms with a size of at least 3, so the answer is -1.
Query = [5,2]: Room number 3 is the closest as abs(3 - 5) = 2, and its size of 2 is at least 2.
he answer is 3.
*/