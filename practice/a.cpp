#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define ll long long
#define int long long
#define ld double
#define rand() abs((rand()<<15)|rand())
#define randll() abs(((long long)rand()<<30)|rand())
const int MOD = 1000000007;

int M, N;
vector<pair<int,int>> S;


string testName;

int curBest = -1;
vector<pair<int,int>> st;
set<pair<int,int>> memo;

vector<int> rem;

void solve(int idx, int cur) {
	if(cur > M) return;
	if(cur > curBest) {
		ofstream fout("cur/" + testName + ".out");
		fout << st.size() << endl;
		for(auto p: st)
			fout << p.second << " ";
		fout << endl;
		fout.close();
		curBest = cur;
	}
	if(cur + rem[idx] < curBest) return;
	if(curBest == M) return;
	if(idx == N) return;
	if(memo.count({idx, cur})) return;
	memo.insert({idx, cur});
	// cerr << idx << " " << cur << endl;
	cout << idx << " " << cur << "  " << curBest << endl;

	st.push_back(S[idx]);
	solve(idx+1, cur+S[idx].first);
	st.pop_back();
	solve(idx+1, cur);
}

signed main() {
	vector<string> tests = {
		"a_example",
		"b_small",
		"c_medium",
		"d_quite_big",
		"e_also_big"
	};

	for(string temp: tests) {
		testName = temp;
		ifstream fin(testName + ".in");

		fin >> M >> N;
		S.resize(N);
		for(int i = 0; i < N; i++) {
			int x;
			fin >> x;
			S[i] = {x, i};
		}

		rem.resize(N);
		rem.back() = S.back().first;
		for(int i = N-2; i >= 0; i--) {
			rem[i] = S[i].first + rem[i+1];
		}

		memo.clear();
		st.clear();
		curBest = -1;

		sort(S.rbegin(), S.rend());

		solve(0, 0);
	}
}