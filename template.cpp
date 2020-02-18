#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;
#define endl '\n'
#define ll long long
#define int long long
#define ld double
#define rand() abs((rand()<<15)|rand())
#define randll() abs(((long long)rand()<<30)|rand())
const int MOD = 1000000007;

string curTestName;
vector<string> nameOfTests = {
	"a_example",
	"b_small",
	"c_medium",
	"d_quite_big",
	"e_also_big"
};

int N, M;
vector<int> a;

set<pair<int, int>> memo;
int curBest = -1;
vector<int> solution;

// Recursive solve template
void solve(int idx, int cur) {
	// Base cases
	if(idx == N) return;
	// Memoize
	if(memo.count({idx, cur})) return;
	memo.insert({idx, cur});
	// Check if best
	if(cur > curBest) {
		curBest = cur;
		// Actively update the output file
		ofstream fout("outputs/" + curTestName + ".out");

		// output
		fout << cur << endl;
		for(auto x: solution)
			fout << x << " ";
		fout << endl;

		fout.close();
		// Keep track of our result in terminal
		cerr << idx << " " << cur << endl;
	}

	// Try recurse down
	// Take current
	solution.push_back(idx);
	solve(idx+1, cur+a[idx]);
	solution.pop_back();
	// Don't take current
	solve(idx+1, cur);

	return;
}


signed main() {
	for(string temp: nameOfTests) {
		auto start = high_resolution_clock::now();

		curTestName = temp;
		ifstream fin("../inputs/" + curTestName + ".in");

		// Reset Memory
		memo.clear();
		curBest = -1;

		// Take in input using fin
		fin >> N >> M;
		a.resize(N);
		for(auto &x: a)
			fin >> x;

		// Manipulate input
		sort(a.begin(), a.end());


		// Solve
		solve(0, 0);


		auto stop = high_resolution_clock::now();
		auto milli = duration_cast<milliseconds>(stop - start).count();

		cerr << "Time for " << curTestName << " was " << milli << endl;
	}
}
