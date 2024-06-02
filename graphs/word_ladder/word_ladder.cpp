#include<bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define print(a)       for(auto x : a) cout << x << " "; cout << endl

using namespace std;

bool compareTwoWords(string w1, string w2){

	int dif = 0;
	
	for(int i = 0; i != w1.size(); i++){
		if (w1[i]!=w2[i]){
			dif++;
		}
		if (dif > 1){
			return false;
		}
	}

	return true;

}

int ladderLength(string beginWord, string endWord, vector<string> wordList) {
	unordered_set<string> wordSet(wordList.begin(), wordList.end());
	queue<pair<string, int>> q;
	q.push({beginWord,1});

	while(!q.empty()){

		auto current = q.front();
		q.pop();
		string current_string = current.F;
		int current_distance = current.S;

		if (current_string == endWord){
			return current_distance;
		}

		for (auto it = wordSet.begin(); it != wordSet.end();) {
            
            if (compareTwoWords(current_string, *it)) {
                q.push({*it, current_distance + 1});
                it = wordSet.erase(it);
            } 
            else {
                it++;
            }
        }

	}

	return 0;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif

    string beginWord, endWord;
    string auxWord;

    vector<string> words;

    cin >> beginWord >> endWord;

    while (cin >> auxWord){

    	words.pb(auxWord);

    }

    int res = ladderLength(beginWord, endWord, words);

    cout << res;

    return 0;
}