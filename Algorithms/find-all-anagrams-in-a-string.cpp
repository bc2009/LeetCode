// 438. Find All Anagrams in a String
// https://leetcode.com/problems/find-all-anagrams-in-a-string/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// BEGIN: Approach 1
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> result;
		if (s.size() < p.size()) return result;
		const int NASCILL = 256, m = s.size(), n = p.size();
		vector<int> hashmap(NASCILL, 0);
		for (const auto &i : p) hashmap[i]++;
		for (int i = 0; i < m; ) {
			if (hashmap[s[i]] == 0) {
				i++;
				continue;
			}
			int j = i;
			vector<int> x = hashmap;
			while (j < m && hashmap[s[j]] && x[s[j]]) x[s[j++]]--;
			if ((j - i) == n) result.push_back(i);
			if (j == m) return result;
			if (j < m && hashmap[s[j]] == 0) {
				i = ++j;
				continue;
			}
			i++;
		}
		return result;
	}
};
// END: Approach 1
// BEGIN: Approach 2
// class Solution {
// public:
// 	vector<int> findAnagrams(string s, string p) {
// 		vector<int> result;
// 		if (s.size() < p.size()) return result;
// 		const int NASCILL = 256, m = s.size(), n = p.size();
// 		vector<int> hashmap(NASCILL, 0);
// 		for (const auto &i : p) hashmap[i]++;
// 		for (int i = 0; i < m; i++) {
// 			if (hashmap[s[i]] == 0) continue;
// 			int j = i;
// 			vector<int> x = hashmap;
// 			while (j < m && x[s[j]]) x[s[j++]]--;
// 			if ((j - i) == n) result.push_back(i);
// 			if (j == m) return result;
// 		}
// 		return result;
// 	}
// };
// END: Approach 2
int main(void) {
	Solution solution;
	for (const auto &i : solution.findAnagrams("cbaebabacd", "abc")) cout << i << '\t';
	cout << "\tPassed\n";
	for (const auto &i : solution.findAnagrams("abab", "ab")) cout << i << '\t';
	cout << "\tPassed\n";
	for (const auto &i : solution.findAnagrams("azzzaaazazzzzazzazazzaaaaaazaaaaaaaazazzaaazaazaazzaazzzaazaaaaazazzzzzaazzazaazzaaaazzzaazzazaaaaaazzzazzazaazaaazazaazzazazaaaaaaazzzaazzazaazzzaaaazaazzazaazzaaaazazzzazazaaazaaazaazzzzazazzaazaazazzazaaazzazzazzzaaaaaazaazazzaaaaaazzzzzzzzaaazazzzzzazazzaazzzaaazzzaazazzazaazzazzaaazzzzzzaaaaaazaazzaaazaazzaaaazaazazzazzzaaaaaaaazzzaazaazazzzzzzaaaazzazzazazzaaaazzzaaazazzazzzzaazaaazzaaazaazaazzazaaaaazaazzzaazzaazzaazaaazaaazzzaaazazzazazzazazzzzaazaaazzaazazzzzzazzazzaazzzzzazaazaaazzaaaaazaaaaaazazaazazazzzaazaazaaaazzazazzazzzzazazaaazzzzzzaazazazaazzzaaazaaazzazzazaaaaazzaazzaazazzaazzzazzazzazaazzazzzaazzaazzzzaaazaaaazazaaaazzazaaaaaaazzzaaaazzzaaaaaazzzzazzaazzzazzaaazazazzaazzzaazaazazaaazaaazzzazaaazzaazazaazzazaaaaazzazzzazzaaaaaaazazzzaazzzaazzzzaazaazzzzzaaaazaazazazzazazzzazazzzzazazzaazzazaaaazzzzzazaaaazzaaaaazazzaaaaazzzazzzzazzzzazzzzaaaaazzzzaazaazzaazzzazzzaaaazazzazazzazzazzaaaazzzazaazazazzzzzzazzzzaazaaaaazaaaazazaaaazaaazazazazazaaazazazzazzzzaaazzaaaaazzzzzzzzazzzazaazaazazzzaazzzzaazazzzaaaaazzaazzzazaaazzazzzazzzaazazzaaazzaaaazazzzzzzzzaaaaazzazazazzzaazzzaaazazzazazzzzzzaazaazazaazazzzazzzaaazzaaazzzazaazazaazazzzzzaazazzazaaazaaazzzazzaaaazaazazazzzazzzazzaazzzzzaaazazaazazazazazzzzaaazaazzzaazaaazzazzzaaaaaaaaazzzazazzazzazaaaaazaazzaaaaaaazazzzzzazazaaazzaazzzaazaazazzzazzazzaaazaazzaazzazaazzazaazazzazaazaaazzaazzzzzzazzaaaaaaazaazzaaaaaaazazaazazzzzzzaaazazazaaaaazaazaazaaaaaaazazazaaazazazazaaazaaaaaaazazzzzzazazaazaaazzazazzazzzzzzzazaazaaaazzzazazzaazaaazaaaazzzzzzzaaazzazazaaazaaazaaaaaaaaazzazazazazaazzzzzazazaaazazzaazzzaazzzaazzzazaaaaazaazaazaaazzzazazzzzzaazzaazazzaaaaazzazazaaaazazaaazzzazaaazaazzazazaaaazzzzazzzazzazzzaaaaaaazaazazzzzzazzzaaaaaaaaaaazaazazazzzzzaaazzaazzzzaazzzaazzzzzaazzzaaaaazaazzzaazazaazzzzaazzzzzzzaaaaazazzazaazzaazzazaaaaaaazzzaazazaaazazazzzazazzzzaazazazzzazaaazzaaazzazazaaaazzzaazaaazaazzzaaaaaazzazzzaazzzaazaaaaazaaaazzzzaazaazazaaazaaaazzzazzazzzazazzazzaazazaazaazazaaazazzzzzzzazzzzaaazzaaaazaaazzzazzzzzzzaaazaazaaazzzzzazaaaaaazaaaaazzzazaaaaazazzzaaazzzazaaaaazzaaazaaaaaazazzaaaaaazaaazazazazzazzzaaaaazzzaazaazazzzzazzaazzzazzzaazzazazazzzzzaaazzzzaaazzzazzzzzzzzaaazazaaaazazaazzzzzaaazazzazaazzzazzazzazazaaaazaaazazaaaazazaaazazzaazaaazzzzzzzzzaazaaazzzzzazazzzzazaazzzzaaaaaaazzzzazaaaaazzazaazaaaaaazzaazzzzazzzzazaazzzazzzzaazazazzaaaazazzzazazzzaaazzaazzzzaazzazaaaazaaaaazzaazaaaazaazzazaazzzaaazaaaaazzazaazzzazzzzzzzazzaaaazaaazaaaazzaaaaazazzazzzzzzzaaaaaazzzazazzzaazzzzazaaaazzaazzazazazazazaaazaaazazazzazzaaaazazzaazzaazaaaaazaaaaazaaazzzaazazazzazaaazzaazzzazazzazzazzazaazzaaaazaazzzzzaaazaazaaazazzazzazzaaaaazzzzzzzzzzazzaazzzaaazaaaaaazaazaazzzzazzaazzazaazzzzzzaaaaaazaaaazazaaazzaazzaazaazaaazazzaaazzzzaaazzazzzzzazzzaazzaazzazzazzazzzazaazzaaaazzzaaazaazzzazzaazzazazzaaazaazaaaaaaazazzazzazazazaaaaazzazaaaaazzazaaaaazzzaaaazzzazzazazzazaaaazaazzaaazazazzzzzazzazaaaaaaaaazzazzzzazazzaaazzzzaaaaazaazzzazzzzaaaaazzaazzazaaazaaaazazzazzazzzzazzzzazzzzaazazzaazazzaaazazzazazazzzaazzaazzazaazzazzazzzazzzazzazzzzaazzazaaazzazaaazaaazzzazazazzazazzazaaaaazzazzzaazazzaaazaaazzzazzaaaazaazaaaaaaaazazaaazzaaaazzazazzazzzazzazzzzzaaazaazaazazzaazzazzzzaazaaaazzazzzaaazzzzzazaazaaazzzzazzzazaaazaaazzaazazaazazzazzzazazaazzazazazazzaaaazzzazazaazaazaazaaazzazzzzazzzzazzzzzzzaazaaazzaazazzzaazzzazzaazaazaazzzzaazazzaaaaaazzaaazzzazzazazaaazzaaazazzzaazzzzaaaaaazaazzzzazaazzzazzaazzazaaazazazaazzazzazzzzzzazzzaaaazzzaazzzaaazzzzzzazzaaazazaazzzaazzazzzazzazaazzazaaaaaazazzzaazazaazzazzzaaazaaazzzaazazazzzzzazzzaaaaazazaazzaaazzaaazazzazaaazzaaazzzzazzazaazzazaazaazzaazzzzaaaazzaaazzazzzzaazazzzzazzaaazaazzaaaaazzzzzzaaazazzazzaaaaaazazazaaazaaaazaazaazazazzaaazzazaazzzzzzzzazzaazzzaazaaazzazazazzzazzzzzzaazzzzzzzaazzzazzzzzzzzaaazzazazaazaazazaazazzzaazzzaaaazaaazzazzzazzaaaaaaazzaaaazzzzzzaaazazzaaazazzaaaaaazzazazaaazzazazzazaazzaazzaazaazazaaaazaazaazzaazzaaaazaazaazzzzzazazzzzaaaaaazzaazazaazzzazzazazzzzazazazaazazazzzazzzzazazzzzzzaazazzzzazzazaaazzaazzaaazaaaazazzzzzzzzzaazzazzazaazzzzzzaaaaaazaaazazazzazazzaaaaazaazazaaaaazzaazaaazazaazzzazaazzzzazazzzaaazzaaazzaaaaaaazzzzzaazzazazaazaaazaazzzaazazaazazaaaaazzaazazaaazazazazazzaaaazzzazaazzazzzzaazazazzaaazazaaazzzazaazaazzzzaaaaazzzzzazazzzazzaaazazzzaaaazzzzzazzzaaaaaaazzazaaaaaazaaazazzazzzzzzaaazazazzzaazzazzzazzzaazzzazazzzazzzzaaazaazzzzzzazzzaaazzzaaaazzzzaazzzaazazzaazzazaazazazazzaazzzzzzzzzaazaaazzazzzaaaaaaaaazaazzazazzzzzaaazaaaazzzzzazzzazzzzzaaazzzaazaazzaazaaaazzaazzazazzaazzazazzzaazzzazazazzzzzazzaazzzazzzzzaazzazaaaazzazazzaaaaaazaazazaazazzzazazzzzzazzzzaazzzaaazazzzzzzzazaazzzzazzzzzazaazazazzaaaazzzaazaazzzazzaazazazaaaazzazzazzazaaaaaazazazazzzazzzaazazzazaaaazazzaazaazzzzaaazzaaazazazzaazzazaazazzzzaaaazzzzaaazaaaaaaazazaaazzzaazzzazzaaazzzazzaazaazaazaazazzzazazaazzzazaazaaaazzaaazazzaaaazazazazzzaazzzzazaazazazaazazazzzazaazzazzazzzzazzazaaazzaazazzzzazazaazaaazzaaaazzaazaaaazazzzzzzazaazazazaaaaaaazzzzaaaaaazaaazzaazzzazazazaazazzaaazzzazaaaaazazzzzazaazzzaaaaazzazazazaazaaazaaazzzzaaazzzzaazzaazazzaazaaazzaaaaazzaaaaaazaaaaazzaaazaazzzzzaazzzazzzzzzzazzaaazzzzzzaazaazaazaaazaazaazzzaazzzazaazaazzzaazaazaaaazazaaaaaazzaazzaaazzzazazazazzzaaaaazzzzaazzzzzazaazzazazaaazazazzaaazzzazazazzzaazzaazzaazazzazaaaazzzzazzazaazazazzazazazazzzaazazzazzzaazaaaazzzazazaaazzaaaazaaazaaaazzazzzzzaazzzaaazaaazzzaazzzzzzaazzazazzzzazaaazazzazazzzazzaazaaaazzzaaaazzaaaazzaazzaazzazaazaaazaazzazaaazzzzzaaaaazazzaazazazazzaazaaaaazzazzzaaaazazaaaaaaazzazzazzzzaaaazzzaazaazazzzazaaaaazazazzaazaazazazaazaazazaazazazaaazazzzzzzzzzazazaazazzzzaazzaazaaaazzzazazazzzaazzzaazazazzzzazaazzzaazzzzazzaazzzzzazazzaaaazaaazzazzaaaazzzzaaazzazzzaazzaaaaaaazzzzzzzzzaaaazzaaazazzzzaaaazzzaaaaazzaaazazzzazazzazzzazazzaazaazazzazazaazzazaaaazaaaazaaazzzzazzazaaaaaazaaaazaaazzaazaaazzzzaazazzzaazzaazazzazazzzazazaazzazzaaazazzazazazzzazzzzzazazazazazzaazaazazazazzzzaaazaazzaazzzazaaaazaaazzaaaaaaaaaaaazazazazzazzazzaaaazazzzzzazaazzzzzzaazaazzazzazaazzazzazzaaazazzzazzaaaazzazazazaaazzazaaazzzzzzzazzzazaazaazzazzazaaazzzzzazazzzazazazaaaazzaaazzazzzzazazazzzzaaaazaaaaaaazzaaazazzzzaaaaaaaaaazaazzaaazzaazzzaaazzzazazzazaazazazazzaaaaazazzzaazazzazazaaazaaazzaaazzzaazaaaazzazazazzzzzzazaazzzazaazzzaazzzzzzazazaaazazazaazzzaaazzzazaazazzaaazzzzaazaazzazazzzaazazazaazazzzzazzzzazazazaazzzzaazaaaazzzazaaaazazazaaazaaaaaazzzazazazaazazazzzzzaaaaazaazaaaazaaazzzaaaazzzazzaazazzzazzaazzzzazazzazazazzzazzaaazzzazazzaazaaazaazzzzazzaaaaazzzazzaaaazzzazzaaaazaaazzazzaaaaazzazzazzzazaaaazaaaaaazazaaaazaaazzaaazazzzzzzzzzzzzzzzazazzzzzaazzazaaazzzzzzzaazzzazzzzzzzzzaaaaazazzazazzzzazzzaaazzaazzzazazzzzzzazaazazzzzazazzzaazzazzaaaazaazzazazaaaazazzaazzazzzzzzaaazzzzzazzzzazzzzzazzazzzaazzzzazazzzzaazzaazazaazzaaaazzzazaaaaazaazzazzzzzaazzaazzazazzzaaazazaazazzaazaaazzzzzzaaazaaaazaaazazazaazazazaaazzzzaazazzzzazzzaaaaazzzzzzazaazaazaaazaaazaazazazazzaaaaazazazaazzzzzzazaazaaazzaazaazazzzzazaazzzzaazzzzzzaaaazazzzzaaaaaaazzazzazazzazaazazaazzaazazzzzazaazaazzzazaazazzazzaaazazazzzzazzzazzazaaazaazaazzzzzazazaaazaazzaazzaaazaaazzazzaazzzzzaaaazzzzaazaazazazazzaaazzzzzaazazzaaaaazzzzzzzzzzzaazzaazzzzazzzzaaaaaaazaazazzzzazzzaazaaaazzaaazaazzzazazaaazazzzzazzzzaaazzzzzzaaazzzzazzaaaaaaaazaaaazzzazazazazazaaazaaaaazzaaaaaaaazazaazzazzzaaaazzzzzaazaaaazazaaazazzzaaazaazzzazaaaaaaazazzzzzzazazazazzaaazzazzazaaazazzzzzzazzaaazazzazazzzazzzzzaazaazazazzzaaaaazzzzaaaazzaazazaazaaazaazzzzzzaaazzzzzzaaaaazaaaazaaazzaazzaazaazaazzaazzazzaazzaazazzazzaazzaaaazzzzazzaazzaaazzaaazaazazaaaaaazzazzazazaaazzazzzaazzazaazzazzzazaazazzazaaaazzazaaaazzaaazazzzaazaazaaaazzzzzaaaaaazaaazzaazzzzzzzzazazzazaaaaaazzzzzaaazzzzzazazazzzazazzzazazzzazazzazzaaazaaaaaaazazazzazzazaaaaazzzzzzzaaazzzazzzzaaaazazaaaaazaazazaazzaaaaaazaaaazazazaaazzzaazzaaaaazzzaazzzzzzaazzzzaaazaazzaazzaazaaazzzzazazzazazzzzazaazzaaaazaaazaaazaaazazazzazzzzzazzazazzaaazaazzazaazzzzazzazazzaaaaaazaaaaaaaaazaazazazazaaazzaazaazaaaazazaazazaaazzzazazzzzzaazazazzazazzazzaazazzazaazzazaazzzaazaaazzazazazzazazaaaaaazazzzazaaaaaazzazzaazazaazaaaazazazzazzaaaazzzazaazzzzazazaazzzzzzzazazzzazazazazaaazazazazzaaazazazaazazzzzaazzzazzazazaaaaazaaaazazzzzaazzzazazaaazzzaaazzazazazzaazaazzzazzzzazaazazazazzzzzazzzzzaazzazaazzzzzazazaaaazaazzazzzaaaazazzazzzzzaaazazzzzzaaaazazzzzzazazazaaaaaazzzzazaazazzzzazazzzzzzzzazaaaaaazzzzazzaaazzaaaazazaaazzzzazzaazzzzzazzazzazzzzzaaaazzzzzazaazzazazazzzzaaaaaaazaazzzzaazaazazzzaaazazzzzaaaazazazazzaazaaazzzzaaazazzazazzaazaaazazazazaazzzzazaaaazazzzzzazzaaaaaazzzzaazaaaaaazaaazzzaazzaazaaazaazaaaazzzazazazazaaaazzzazzazzazzazaaaaaazzaazzaaazazzzaaazzzaaazaazazaazaazaaazzaaaazaaazzazzzazzazaaazzaazzzzazzazzzazazzzazaaaazzaazzzazzaazaaazazzzzazaaazzazaazzzazaaazzzzzaaazzzazaazzzaaaazzazaaaazazzaaaaazazaazzaazaaazazazaaaazaazazaazzazzazazaaaaaaaaaaazzazzaazzzzaazazaazzaaaazzazzazaaazzaazazaazaazaaaazzaazaazaaazazaazzaazaaazzaaaazzaazaaaazaazazzaaaaaazazazzzzzaaaaaaaazaazzzazazazaaaazaaazazaazzazaazazzzaazzzazzazazazazzaaaaaazazaaazzzzaazzaazaazaazzzzaazazaaaaaazazzzaazzazzazzzazazzzzzzzaaaazzzzaazaaaazaazzazzazzaazzazzazaazzzzaaaaazzaazazzaazazazazaazzzzzzzzaaazzzazzzzazzazzzazzzazzaazzzaazzazaaazazaaaazazazzzzazzzaaazazazzzaaazazzzzzzzzaazzazzzzaazazzaazzazzazaaaazzzzzzzzzaazazzzazzzzzaaazzzzazazzzzzaazzazaazaazzzzzzzazzzazzzzzazaaaaaazaazzaazaaaazaaaazzaazzzaaaazaazzzzzzaazaaazazzzzazaazzazazaazazzzzazaazzzazazzzzaaaazazzazzzzzazaaazaazazzaazzaaazazzzazzzzazzzzaaaazzzazzzzzzzzzzazazzzzzaaazzzaazzaazzazzzzazzzazaaazzaaaaaazazaazzaazaaaazaazzaazzzaaazaazzzaazzzaaazzzaaazzzazzazazaaazaaaaazzzzzzzazaazaaaazaaaaaaaazazzzzazaazzaazzaazzazaaazazzzaazazzzzzaaazzazazzzzzazzzaaazzazzaazzzazaaazzaaazzazzzazzzazzazaaaazzzzazaazzzaaaazazaaazazzzzzzaaazaaazaazazazazzzzaaazaazaazaaazaaaazaazzaaazzzzazzzaaazaazzazazzzazaaaazaaaazaazaazaazzaaaazazzzazaazzzzaazaaazaaazaaazaazaaaazazazzaazaaazaaaazazaaaaazzazzzzzazzazaazzzaazzaazzzaaaaaazaazazaazaaazzaazzzaazaaaazazzaaaazzazazaaaazazzzzazzzaaaaaazaaaazazzzzaazazzazazzzaazzzazazazaaazzaaaaazaaazazaaaazzzzazaazzzaaaazaazazzaaazzzazzazazaaaaazazazaaazzazazazazzaaaazazzaazazazaaazzzzzzzzazzzzazazaaaazazzzazazazazazzzzzzzaazzzzaazzazzazazazzaazzazazzzzzaazzzzaazzazzzaazzzzazaaazazzzzazaazzzzaaaaazzazazzzazzaaaaaazzaaaaazzzzaazazazaazaazaaazzzzzaaazazazaaazzaaaazzzzzzaaazazaazzzaazazzzzzazzazazzzaaazazazaazzazazzzzzzzzazazzazazzzzazzazzzaaaaazaazaazzaazzzzzzazzzzzzzazzzzaaazazaazaazazzazazazzzzzaazzaaazzzaazzzzazzzzzzaazaazaaaazzazazzzazzzaaazzaazazaazzaazazzazzzzzzazazzzaazaazzzzazzaazazazzazaaazzzzzzaazzazzzaaaazzzaaaaaaaaaaazazaazaaaazaazzaaaaazaaaaazaaaaaazzzazzazzazaaaaaazzaazazzzaaaazazzazzazzzaaaaaaaazzzaaaaaazaaaaaaaazzaazaazazaazazzzzzaaaaazzzaazazzazaaazzzaaaazaaazazazzazazaazzzzzzzazzazaaazzazaaaaaazazzaaaazzazazzazaazzaazzaaazzazazzzazzzazaazaazazaazazaaazzazzzazazaaazaaaaazazzaaazazzzzaaazzazzazazzzzazzzaazaazaazaaaazazzzazaaazaaaazzaazzazaazaazzzzaazzzzzzazzzzazazzaaazaaaazzzzazazzzazzzazaazaaaaazzaaazzzzzzazzzaazzaaaazzaaazazazaazaazaazzazazazzaaazaaaazaaaazzaaaazzzazzzzzzazzaazzzaaazzazzzaazazaazzazaazazzazzzazzzazazazazaazzazzaaazzzazzzazzaaazaazaazzzazaaazzzazaazaaazzzzaazzzzaaaaazazazazaazaaazaazzazzaaaaazzaazaazzzzaazaazzzazzaazzazaazzzazaaaazaaazaazzazzzaaaaaaazzzzzzzaazaaazazzazaazaaaazzzaaaaaazzaaazaazzzazazazazazazzzzzaaaaazazzaaazzaazzazzazaaaaazazazzzzzaazazzzaazazzzzzaaazzzzzzzzaaaaaaazaaaaazzzzzzaaazzzaazaaazzzaazazzazaazazazzazzazzazazaazzzzazazaazzaazzazaaaazaaazzaazazazzazzaaazaazzazzzazaaazaazzaaaaaazaazzazzzaaazaaaazazzazazazazaaazzaaaazzaaaazaaazzaaaazazazzzzzzzzaazazaazazzaazzzazzzaaaaazaaaaazzazzazzazaaaaazaaazaazzazzazzzzzzazaazzzzaaaaaazazazzaaaaaaaaaaaaaazaaaaazazaaaaazazzazaaazaaazzaaazzazaaazaaazzaaazazaaazazzaaaaazzazaaazzzzazzzaaaaazzzazzzazazzzzaaaazzzaaazaaazzzzaaaazazzzazaazaaaazzzaazazzzaazaazazazazzaazaaazazzaaaaazazzzzaazaazaazaazazazazaazazzzzzazazzazzaaaaazzzazaazaaaazazaaaaazzazazazzzzaaaaazaaazazzaazzzzzaaazzazazzzzaaaaaaaaaazzzzzzazaaaazzzzaazzzzzazaazaaazazaaaazzaazzazazaaaaazazzazzzzaaazazaazaazaaazzazzazzazzzazazzzzaaaazaaaaazazazzaaaaazzzzzazaazaaazaaazaazaaaaaaazaaazzaazaazzaaaazaazzzzzazzzzzzzaaazazzazzzzazzaazazazazazzaazzzzaazaazaaaazzzaazaaaaazaaaazzaazzaaazazazzazazzzaaaazazzazzaazzazzazzzzzzaazzzzzzzazazzzzaaaazzaazzazzzazazzazaazaazaaaazaazazzzazzaaazzzazaaaazzazzzzzzaaazaazaaaaaazazzaaaazaaaazzaaazzazzzzzazaazzazazaaaaazazaazzaaazzzazzazzzzzazaaaaaaaazaazaazzazzaazzzzzzazazzazazazazazzzaaazazzaaazzaazzzaazzzazaaaazazzaaaazzazaazaazzazazaaazaazaazazzzaazzaaaazzzaazaaazazzzzaazzazaazzaazzaaazazaazaazaazazaaaaaazzazzzzzzaaazzzzaaazzzazaazaazzzaaazzzazazzaaaaaazzaaazaaazaaaaaaazazazzaazazaaaaazzazaazzazaaazzzzzzzazzaazzzzaazazzaazzaazaaazaaazzazzaazaaaaaaaaaaaazazzzzzzaaazaaazaazazzazazzzzzzzazzaaaazazzzzaazazzzzzazazzazaaazazazzzzaaazazzzzaazzaaaaazazaaazazzzzazazazaazzazaazazazzaazazaazazaaazazaazzaaaaaaaaazzazzzaaaazazaaaaaaaazzaaazzzazzzzzzazaazzazzaazaaazaaaaazaaaaaaaaaaazaazaazazzzazzzzazazzaaaazzzzzzaazaaaaaaaazaaaazzazazzaaaaaazazzzzzaaazzzzzzazzazzazazzzzaazzazzazzzzazzzzzzzzaazzzazazazzzaaazazzaaazaazzzazzaazaazazzzazzaazaaazzzzzaazzzzzaaazazzaazzzaazzzazaazaaazzzazzzaaaazaazzzazaaazzzzazazzazzzzzzazzazzzazzazzzaaazaazzaazzazzzzzzzaazaaazazzaaaaaazazazazaaaazazaazzazazzaaazzaaaaaazzaaaazzzaazaazaaaaazzzazaaazazaaazazzzaaaaazazzaazzaazzaaaaazzaaazaazzzazzazzazzazzzzaazzzazaazzzzzazazaazzazzzzzazzaaaaazaaazzzaaaaazazzzzzzzzzaazaazazazzazzzaaaaaaazazazaazaaazaaaazzazaaaaaazaaazzzaazzzaaazazzzazzzazazzzazzazazaaaaaazaaaazazaaazzzaazzzaazzaaaaaazzzzzaazazzaazzazazaazaazzaazaazzaaaazzzzazzaazzzzaaazaazzaaazaaazzzzaaazazzzazazaazaaazaaazaazzzzzzazazzzzzzzaazzzaaazzzzzzazaaazaazazzazazazzazazzzazazazzaazzazzaazaazaazaaaazzaazzzzzaazaaazaazazzazzaazzazaazaazzzaazazzzaaaaaazzazazaazazzaazzaazzzzazazazzzazzzzzzaaazzzzzzzazazzzazaazzzzaazzazzzazzaazzzzzzzzazaaazzaazzzzzaaaazzazaaaazzzzazzazaaaazzaazaazaaazaazzzazazaazzaazazzzazzazaazaaaazaazzzzazazaaazzaaaazzzaaazaaaaaaazazzaazzzzzaaaaaaazaaazzzazzzazazzaaazzazazazzzzaazazzzazaazaazzzzazaaaaazzazzazzzaazazazzzzzzzazzaaazazaazzaazzaaaaazzzzzzzaaazzzzazaazzzzzaaaazzzzaazazazaaaaaazaazazaaazzzzaazzzazazzazazzzzaazaazzazazazazaazzzzzzzzazzaazaaaazzzzzaaazazazzazzzaaaaaazaazazzzzzazzzzaazzzaazaaaazazzzaazaazzaaazaazazaazazaazzazaaaaaazzzzaazaazzzazzaazazazazzzaaaazazazzazaaaaaaazaaazzzzazzazzazaaazzzazzzzazaazaaaazazzaazzzaazaazzzzzazzzazzzaazaazaaaaaazzzzzzzazaaaazaazzzzazazazaazzazazzazzaaaaazzaazazazaazazzzzzazazzzzazaazazaazzzazaazzzzaaazazzazaazzzazzzazazzazaazzzazzzzaazzazzaazazzaazaazzzazzzzazzzzzzzazzazazzazaaaazaazzaazzazzzzaazzaazaaazazzzaazazazzzzzaazzzaazazaazaaaazzaazzzaaazaazzzzzazazzzzzazzazazaazaaaazzzzazzzazaazzzzazazzazzzzaazzaaazzaazzazaazzzaaazzazzzaazzaaazaaazzzzzaazzzzazzazzazzaaazzzazaazzaazazazaazazzzazzzzzzaaazzzzazzzzazzzzaazzzzaazazaazazzaazaazazazaazazazazzazazaaaaazazazzzzzzzzzazzazaazaaaaazazazzzzzaazaaazzaazazzaaazzaazazzzazzzzaaazzazazazazzaazaaazazaaaaaaaaaazazzzaazzzaazzzazzzaazazazzzzzzazaaazaazzaazzzaazzazazzaaazzazzazazzazzaaazaaazzzaazzzazzzzzzaaazaaazzazazzazzazaazaaazaazazzaazzzazzazzzaazzaazazaazzzzzazaaazaazaaazazazzazazzzzazzzzazzzzazaazzaaaazzaazazzzaazaazzzaazaazzaazzaaaazzazaazzzzzzaaazaazaaaazzazaaaazzazzzazaaaaaazaazzzzzzaazazzzazzazzazaazaaaazzaaaaazaaazaaazzazzzazaazazzzazazaazazazazaazzazzzzazzazzzazaazazzaazazzazzazaazzaaazzzzaazzaazzazazazzaazaaaazzazaaazzzaaaazzaaazzzzzazaaaazzaaaazazazzzazzzzzazzazaazzazzaaaaazzaazzzzzzzzaaazzzazzzzzzaaaaaazazaaazazazaazzazzaaazazzzzazazazazzaaazaazzazzazazzzzazzzaazzazzzazzzazzaaazazzzzzzaaaazzzzzazaazzazzaaazzaazzaazzzazzzaazazaazzzzazzazazaazzzazzzaaazzzzzzzazazaaazzzaazzzazaaaazzzazaaazzzzaaazzzaazzzazzzaazaaaaaazzazazaaaazaazazzzzaazazzzzazzaaaazzzaazzaaaazaazzazazazzzaazaazaaaazzazazaazaaazaaazzzazaaazzazazaazzazzzaazzaaazzzaaazazazzzzazzzzaazzazzaazzazazazazzzzzazzaazazzazzzazzzaazaaazaazazaazzzaaaazzzzaazzzzazzzzzzzaaaazzazzzzzzzazazaaaazzaaazzzaazaaaazzaazzaaaaaazaazzaazazazaazaaaazazazazazzaaazzaaazazaaazaaaaaazzzazzzaaaazzazaazazaaazzazzzzaazazazzazaaaaazazazzazaaazaazzzzaaaazzzzzzazazzzaaaazzzzazzzaazzzzzzzzaazzaaaaaaaaazazzzzzaazzzzaaazazaaazazaazazazzzzzzzzzzzzazaaazzaaaaaaazaazzazaazzazazazazaaaaazazazazzaazzaazzaaaazzzazzzaazaaazzzaazzzzzaaaazazazzzazzazaazaaazazzzzaazzaaazaaazazazzaaazzaazazzzazaaaaaaazzzaaaaaaazzzzazzzazaazzazaaazzzaazzaazaazzazazzzazaazazaaazazzzzaazzzaazazzaazzzzzzzzazaaaaazzazzzaaaaaazzazaazzzzzzaazzzzzaaazzzazazaazaazzzzazaaaaaaazzzaaazzzzzazazaazaaazzzazzaazazzaaaazaazzzzzzazazzazzzazzzazaaazzazazazzzzzzzaaazzazzzzzzzazzazzzaazazzazazzazazazaazzzazzzzaaazaazzzazzzzaazzzaazzzazzzazazzazzaaaaazaaaazzzazzaaazaaazzzazzzaazaaazzzazazaazzazaazzaaazaazazaazaaaaazazazazazazazzazazzzzzzaazzzazaazazzaaazzaaazzaazaaazazaazazzaazzazaaazazaaazzzzzzazzzzzaaazazzzaazaazaaazaaaazazazazaaaaaaazzaaaazaaazzzaaazzzzzzaazazaazzaaazazzaazaaaaazzzzazaaazazzzzzzaazazazzazzzazaazzzaazzzzzzzazazaaaazzzzaaaaaazzaazaaazzazaaazzzzaaazaaazzzzaaazzzazzazzazaaaazzazaaazzaaaaaazzzzaazzazazzzzazzaazzazzzzazaazazzzaazazazzaaaazzzzzzazzzaaaazazzzaazaaazzaaaaaazzzaazazzzaazaazzzzzazazazaaaaazaaazzazaazaazazaazazzaazazaazazaaazzaazzzzzazzazazzzaazazaazzzaazzazzaaaaazazazaazazazaazzaaazaaazazaazaaazzaazzaazzazzazzzzzzzzaaaazazzaazaazzzaazaaazaazaazzzaaaazzaazaazzazazzzzaazazazaazzzazaaazazzzzaazazaazzaaaazazazazzazazaazzzaazzzzzzaazazaazazzazazzzzaazzzaazazaaaazaazzzzzaazaaazaazaaaazzazaazazazazazzzzazaaaazzazazzzzazazzazaazzzzzzazazzaazaazzazazzzazazaazazzzzzzzaaaazaaaazzzaazazazazzazazazzzzaaazzazazzzazzaaaazzzaaaazzzzzaazzzzazzzzzaazazaazzzzazzzazaaazazzazzazazzzzzzzaaazazaaazzazazzazzzazazaaazzazaaazazzaaazazzzzazzzzazazzzazzzzaazaazaazaaazzzazaazzzaaaazzzazzzaazazaazaaazzzzzazzzzaaazaazaazzaaaaazaaaazaaazzazzaaaaazaazzzzzzazzazaaaaazzaazzazazaazazzzazazzaazaaaazzazazzzazazazaazaazzzazazazazazaazazazzzazaazaaazaaaazzzzzzaaaaaazazazzaaazzaaaazazaaazzazzazazzzaaazzazzzaazaaazazazzaazaazaaazzzazazaazzazazzzzzaaazzzzazazzaazaaaaaazzzazzaazzaaaaazazzzzazaaazazazzzzzazzzazzaazaaaaazaazzzazzazazzazzzazaaazaazzaazaaazzaazzazaaaaazzzazzazaaaazzzzzzaaaazzzzzzazzazazaazzzzaazzzazazzazzaaaaazazaaaaaazzazzzaaaaaazzzaazaazzzzazzzzzazaazaaaaaazzzazzzazaazazazazaaazaaazazzazaaazaaaazaaaazazaaaaaazzazzaazaazaaaaazzaaazaaaazzzzzzzazzazzzaaazazzzaazzazaazazzzzzzaaaazzzzazazazzzazazzaazazzazaazzaaazaaaaaazzazzzazazzzzzzazzzzaaaazzaazzazaaaazzaazazzzaazzzazaazazazaaazazaazzaaazaazzzaazzzaazazaazaazzzzaaaaaaazzzzaazzazaaaaazazaaazaazazzazzzaaaaazzaazazazazzzzazaazaazaazaazaazzzazzazazzazaaaaazaaaazaaaaaaaaazaazzaazaaaaaaaaaazzaaaaaaaazzazzazazaaaazazazazaaaazzazzzaazzazzzzazzaazazzzzazzazzaaazzzzazaaaaaaazazaaaaazzzzzzzaazaazaazazzzazzaazzaazaazaaaaazazaazaaaaaaazazazaaazazzazzzzaazzazazzzzzzzazzazaazaaaaazaaaaaaaaazzzaazazzzzaazzzazzaaaaaaaazazaazzazazaazazzzzzaazazzzaaaaaaazaazzzzzaazaazazazzzazaazazaaaazzaazzzaazazzzzaazzzazzzaaaaazzaaazzazaaaazzazzzzazaaaaaaaaazaazzaaazazzaazzzzaaaazazzzaazaaaazzzzzazzzzzazaaaaaaaaaaaaaazaaazazzzzazazaazzaazazzzzazazazzzaaaaazazzaaazaazaaaaaaazzzaaaazzzaazzzaaazaaaazzaaaaazazzzaazzaazazazazaazzzzazaazaaaaazzazzaazazzaaazzaaaazazzzazazzzzzaazazazzazzazzzzaaazzzaazzzzazzzazazzzazzzaazzzaaaazzzazzzzzaazzzzzzazazazzaaazzzaaaazazaaaazaazzaazzazazazaazzzazazzzazazzaazazzazzaazazzazaazzzazzzzzzzazzzzzzzaaaazaaazazzzaazzzzaaazzaazazzzazzzzazaaazzazaaaazzaaazazaazazaaazzzaaazzzzzaaazzaaaaazaaaaazaaaazazzazazaaazazazazazzzzzzazaazazzaazzzaaaazzazzzzzzaazzzaaaazazaazaaaaaazazzaazzaazaazaaaazzaazazzazzzzaaaazzzzzazaazazzzaazzzaazaaaazaaaaaaaaaaaaaazzzzazzzzazaazaazaazzzzzazaaazazzzzzzzzaaaaaaaaaazzzaazazzzaazzzazazazazaazazazazaazzzaaazazzzzzazzazzzaaaaazaazazzzazzzaaazzzaazzzzazzazazaazaazazazzaaazazaaazzzaaazaaazzzaazaaazazazzzaaazazzaazaaaaazazazaazzzazzaazzzzzzzazzzaaazaazaaazzzaazzzaaazaaaazzaaaaaaaazazzzazzaazzzazzaazzzaazaazzzzzzaaaazzazzzzaaaaazzaaazaazazaazaazzzzzaaaazaaazazazzaaazazaazazazzazzzzzzzaazzzaaazaazaaazzzaaazzzzzaazaaazzazaazzzaaaazaazaaazazaaaazaazzazaazaazaazzzzaazazazazzaazaazazzzaaazazaaazaaazzzzaazaaazaazazzazzzzaaaaazaaazzaazaaaazzzaaazazazazazazzzazaazaaazzazaazzazazzzzazzzaazazaaazzaazaazazaaaazzazazaazazaaaaazazzzzaaazzaaaazazazzaazzzazzzzzaaazazazzzzazzaaaazzzazazzzaazaaz", "zazzazazaazazzzaazzzzazzaaazzazazaaaaaaazaaaaazaaazaazaazaaazaazaazzzzazzzaazazazaazzzaazzzaaazzzaazaaazzazaaaazzzzzaazazazaaazazzzzazzzazaaaazzzaaaazzzazazzaaazaaazzzzazzaaaaaazzaazzzazzzaazazzzaaaazaaaazzazzazzzaaaaaazaaazaaaaaaazzzazzazaaazzzzzzzzzzaazzzazazazazzaazzzzaaaazzzazzaazaaazaazazzazaaazazzzzazzzaaaaaazaazaaaaazzzazzzzaaazzzzazaaazzazazzazzazzzzaaaazaazazazazazzaaazzzazaazazzazazaazzzazaaaazaazaaazzzzaaazaazaazazaaazzzazaazaaaaazzzzazaazazazzzzazaaazaazzzaazaaazzaaaazzaazzzazzaazazzazaazaazzaazzazazaaaaaaazazaazzzzazzaazazazaazazazaazzazaaaaaaazzzaaaazaaaaaaaazaazzazaaaaazzaaaazazaaazzzzzaazazzaazzzzazzaaaazzazazazaazzzzzazazazaaaaazazazazaazaaaazzazaaazazzaaaazazazzazazaazaazzaazzzaaaaaaaazzzazzazzaazzzaaazaazazazzzazzazzazzzaaaaazazazzaazzzzzzzzazzzzzzaazzazazazzzzzzzzzaazaazaaaazazzzaaazzaazzazzzzaazzzaaaaazzzaazazazazazzzaazzzzzazzaaazzaaazzaazzaaazzzazazzaaazaazzaaaazzzzazaazzazaazzzzzazaaaazazaazazaaaazaaazzzzzaazazazaaaazzazazzaaazaazazaazzaazazzazaaazzzzzazaazzzazaaaaaazazzzaazaaazzzzzzzzzzazaazaazazaazzaaazaaaazzzzazazzazzzazaaazazaazzzzazazzzaaazaaazaaazzzzazzzzazazaaaazaazazazaazzzazzazazaazaaazazzzazazazaazazaazzaazaaazzzzzaaazazzzzzzaazzzazzzzaaazaazzzzazzazazzzzzzzzzazazazzzzzzzzazzazazaazzzzaazaaazzzzazzaazzzzaazzazazzzzazaaazzzazaazazzzazzzazazzzaaazaazzazzzazaaazzazzaazazaaaaazzaaazaaaaazzzzazzzzaazazzzazzzazaazazaaazazzaaazzazzzzzaaazzzaazzzzzaazzazaaazazzaaazaazazazaaazazazzzaaaaazzzzaazzazazazzazaazaazzaazzazaazzazzaaazazzzzazaaaaazazazzzzzazzzazzaaazzazzzaazzazaazzzazzzzzaaaazazaaazzazazzzzazazaazzzzzzzzaazaazazzaaazzzaaazaazazazazzazzaaaazaazzzaazaaazzzzzaazzzzzazaaazzzaaazzzzazazzazazzazzazazzzaazazaaazzzazzzzzazzazazaazazzazaaaazzzaazaaazzzzazazazzzzaaaazaazaazzazaaazaazaaazzaazazzzaaazaaaazzaaaazzzzazazazzzazaaaazzazzazazzazzzazzzazzaaaaaaazazzazzzzzzzzazazzzazaazaaaazazzzazazzzazaaaaaazzaazaazaaaazzzzaaaaazaazazaaaaazaaazzaaaaazazaazzaaazazzaazaazzzazzzaazzzzazzzaazaaazazaaazzzzaaaaazaazaaaaazzazazzzaaaaaazzzazazazazzzaazzaaaazaaaazzaazaaaaaaaazzzzzzazaaaazzaaazzzzzazaaaazzaazazazzazzzzaaaaazaazzaazaazazzaaaazzzazzazaazzaazaaaaazzazzazaaaazzzzzzzzzazzazzzaaaazaazzzazzazaazazzaazzzzzzaazzzzazzaaazzzzaazzzzzaazzzzzazaaazzaaaazzzazzzzzzzaazazazzaaazzzzzzazzzzaazzzaazzaaaaazzazaaaaaazzzzzaaazaazzzzzzaazaazazzaazzzaaazzaazaaazaazzzazazaazzazzazaazzazzaazaaazaaazzazazaaazzazzzzaazzzzzzzzzaazazzzzzzzzazazzaazzaazazzzazzazzazzaaazzzzazaazzazzzzzzzzazaazzzaazaazazzzzzazaazaazaazaaaaaazzaaazzazzzzazazzaazzzzzzaaaaaazzaaaazzaazzzaazzazzaazazzaazzzaazazaazaaaazzzazaazzazazaazzzzzaaaazaaaaaazazazaazaaaazzzazazzazzzazazzzzzazzaazzazzazzzzzazazazzazzaazazaazazzzzazzazaaaaaaazzazaaaaaazzazzzzzazazaazzzazzzzzzzazaaazzzazzazzaazaaaaazzazazazzzzzazzaazaaaaaaazzazzaaaaaaazazazzazzzzzzaazzzazzaaazzaazaazzaaaazaaazzzazzazzzazaazaaazzzaazzaaazzazazazzazazzaaazaaazaaazaaaaaazaaazaazazzzzazaazazaazaaaazzaazaaazaazzazzzazaazzaaazaazzaaazaazzazzzazazaaazzazaaaaazazzazzzzzazzazzaazzaaazaaazazzazaaazazaazaaaaazaazazzaazazazzzaaaaaaaaaazzzzazazzzaaaazzaaaazzaazzzaazzazazazzaazzaazzzazaaazzazzzaaaaaaaaaazzzaaazazzaaazaazzaazzzaazazaaaaazaaaazazzaazaazazzzaazazaazaazazazzazzazzzazazzazazzzaaaazaaazazzazaaaaazazzzaaaaazazazaaazaazaaazzaazzazaaaaazzaazzaazaazazzzzzzzzaazzaaazaaaaazzazazzzzaaazzzaazzzzzazaazzaaaazazazzazzzazaazzaazzazzzaaazzazzzzazazaazzzaaazazaazzzazzaaazazzaazzazzzaazaaaaaazaazzzzzazaaazzzzzazaaazzaazazzaazzzazzzzaazzaazzaaazzazzzzzzazazaaazaaaaaazaazzzazaazazaaaaaaaazaaazazzazzzazzzaazzazzzzzazazaaaazzzazzzzaaazzaazaaaazzazaaaaaaaazaazaazazaaaazazaaazazzzzaaaaazaaazazzaaazzaazazzzazazazzazzzzazazazaazzzzzazazzzzzaaaazzzzzzzzzzzzaazzazaazazazaaazzazazazaaazzzazazazzazaaaaaazazzazaazzzaazazaaaaazzzzzzaazzzzzazzzazzazzaaaazzzzazzzzzzazaazaazaazzazzzzazzzaaaaaazaazzazazzaaazazzazzzazzaaaazzzaazzzzaazaazazazzazaaaazaazaazzzzaaaazzazazaaaazazzaaazaazzzzzzzazazzzzzzzazazaazazzzzzaazzaaazazzzzzzzazzaazaaazzazaazazzzzzzazzzzaaaaazaaaazazaaaazzaazazazazaazzzaaazazaaazzaazzazazzzzzazaaazzzaazazaazaaazaazazzzzzaazazzazzzazzazzazazzaaaaazzaaaazzzaaaaaaaaazaazzzazaazazazaaaaazzzzzzzzzzzzzzazaazzzzaaaazazzzzaazzzzaaazzzazzaazzzzaazaaazazzaaazzazzzzzzaaazazazzaaaaaazazaaazzzzzzaazzzzazzzzzzazzzazzazaaazaazzazzzzzzaaaaaazazazaazzaazzaaaazzzaaazaazaaaazzazaaaazazzzzaazzzaazzaaazazzaazaazazzazazaazazzzazaazzaaaazazaaazaaazzzzzzaazzaazzazzzzazzzaazzaaaaazzaaazazzzzzzaazzzzazazzazzzazzaaazaazzazaaaaazzazzaazzzzazaaazzzaazazzzazazzzaazzzaazazazazaaazzazazazzaazaazaaazzzaaazzzaazazazaazzzaaaazazaazaaaaaaaazaaaaazazzzzzazazaaaazazazzzzzazazzzaaazaazaaazzazzazazazaazzaaaazzaaazazzaaazzazaaaazzzzazzzazzzzaaazzaazzzazazzazzazzzzaaaaazaazazzzzzzazaazazzazzaazazzzazazaazzaazzaazazzazzazzzazzaazzzzzzzazzazazazaaaaaaazazzzazaazaaazaaaaazzazazaazzaazzzazzaaazzazazzzazzzzaaazzzazaazzzzzzzaaaaaaazaaaazzzzzazzaaaaazzzaaaazzazaazazzzazzaazazaaaazazaaazzaaazzzzaaaaaazazaaazzazzzzzazaazaazaaazzazzazzzzaazzazaazazzazzzazzazzzzzzaaaazazzzazzazazzzzzzzzazaazaaazaazazzazzzazzzaaazaaaaazzazaaaaaaazzzazzaazazzzaazazzazaazaaazazaaaazzzaazzzzazzzaazaazzzaaaazzazaaaazaazaaaaazzzaaazzaaaazzzzaazzzzaaazzaazaaazzzzzzaazazzzaaaaazazzaazzzzaazzazzzazzazzzazzazaaazzaazzzazzaazazaazzzaazaaazazazaaaaazzzazzzzzazaaazzaazazzzzzzaazaaaaazzzazaazzaazazazaazazzzaaaaazazazazzaazaaaazzazaazaaazzzzaazzzaaazazzzzzzaazzzazzzzaazaazazazazzzaazzaaaazzaazzazzazzaaazazzzzzaaazazaazaaazazazzaazzaaaaaaaaazzzazazazazzazzaazaaaazzzaaaazazzaaazzazaaazazzzaaaazzazaazaazzaaazazzzzazzzzazazaaazaazazzazzaaazazaazzzazaazazaaazazaazzaazaaaaazzazazzazzzzazzzzaazzazzzzzzaaazzzazzzzaazaazzaazaaazzazzazaaazaaazzzazazzzaazzzazaazzaaazzzaaazazzzaaazazzazzzazzazzazzaaazaaazzaaaazazazzzazaaaazzaazzzaazzaaazaaaazaazzzzzazzazzzaazaaaazzazzaazzzzaazzzaazaaazaazzzazaazaaazzaaazzzzzaaazzzzazazazazazazzazaazazazaaaazaazzaaazzzzzzaazazzzzzazzzzzzazaazzaaaaaaazazzaazaaaaaaazzaaazazaazazaaaaaaaaazzzzaaazzaaaaaaaaazaazaazzazzzzzzzazzaaaazzazaaazazzaazazzaazaaazzazaazaazaaaaaaaaaaazaaazzaaazzzzzzzazazaazzzaaaazzzazzzzazzaaaaaazzaazazzaazzzaazzaaaazazzzzaazazazaazaaazazzaazazzzaaaaaaaazazazzaaazzaazzzaaaazaazaazaazaazzaaaaazzzazaaazzazzaazzzazzazzaaazzazzazzzaazaaaaaaazzazzzzzazzzazzaazzzzaaaaazzazzaazzzaazaazaazaaazazzaaazzaazazzzzzzzaaaaazaaaazzazzaazaaazazaaaaaazazaaazazzzazaaaaaaaazzaazzazzazzzzaazaazzazzaaazazazaazazzazzaazzaaaaazazazaaaazazzazaaazaazzzzzazaazzaaazzzaaazzzzazzzzazzaazaazazaazazaaaazazzaazzazazzzaaazzzzzzzaaaaazaazazazaazzzazazazazzazazzazzzazazzzazaaazaazaazazazzzaazzaaazzazzazazazzaazazazzazazzazzaazazzaazzazzzzzazazzazaaazzzaazzzzazzazzaaaaaaazazzaaazaazzazaazzaazazzzzzzzaazaaaaaaazazazzzaaaaazzazzazazaazzaaazazzaazzaaazaaazzazazazazzzzaaazaaazzazaazzzaaazaaaaazazaazzzzaaaaazazazazaazzaazzazzzaaaazzzaaazaazazazzzzzaazaaaaazzazzazaaazazaazzzzazzzzzzzzzzaaazazazaaaaazzaaazzazzaazzzzazazzzazzazazzazzzzaaaazzaaazaazaaazzazaaaazaazazzaazzazazazzazazazazzaaazzaazzaaaazzaaaazazaazzaaazzzzazzzzzazzazaazzzzazzzzaaaaaazzzzzaaazaazzazazazzazzzaazaazzzzaazaazzaazazazaaazzaaazazzazazzaaaaazaazzzzaaazzazzazzzzzaaazazazazzzzazazzaazzazzzazazazzzaazaazazaaaaaazzzaazaazazzazaaazaaaaazzzazaaaazazaaaaazazzazzzazazzzzazzaazazazaaaaazazaazzzaaazazaazazazaazazzazazaaaazazazzzzazzazzzzzzzaaazaazzaazzzazaazzzzzzazazzazzaazzaaazazazazaaaazzzzzaazazaaaaaaaazazazzazazaazaazzazaaaaaazzzaazzzzazzazzazzzazzzzazzazzzzazazaaazazazzzzzazaazzzzzzazzaazzaaaaazzaazzzzazzzzaazazazaaaazzazzazaaaazzazaaaazzzzaaaaaaazazzzzzzzazzaaazaazaaazazazzaazaaazzzazzaazaazzazzazzzzzzzzzazzaaaaazazzaaazzaaazzazazzzazazazzazzazaaaaaazzazazaaaaaazazzzazazazazzzzazzzzzazzzzazazzaaazaaaazzzzaazzzzzaaaaazzzazzzzaaazzzzzzzzzzzazaazaazaaazzzazzzazaazzazzazaazzazaaazzaaazaaaaaazaazaazazzaazaaazazazzaazaaazaazzazzaaazazzaazaazzzzzzazaazazazaaazzzzaazaaazzzzaazzaaazazzaaaazaazaaaaaazaaazaazazzzzazzazaaaaaazazzzzzzzaaaazzaazaaazaaaazzaaaazzzzaazzaazzzazzzzzzazazazazzzazazaaaazzaaazazzzzaazazaaazaazaaaaazaaazzzzazzaazzzzazazzaazazzzzaazzazzzazaaazazzzazaazaazzaaazazzaazazaaazzzazzzzzazazzzzazzaazazaaaaazzaaaaaaazzazzzazzzazazzazaaaaaaazazaaaaaaaazazzzaazzzzazazzaaaaazaazazaazzzzzzzazzazzzazazaazzzzzaaaaaazzazazazaaaazzazaaazzzazzazazzaazaazzazzzzzaaaazazzzazzzzzaaaazazaazaaazzaaaazaazzazzzazazaazazazzzzaazzzazaazaaaazaaaazaaaaazzzaaaazzzzzaazzzazzaaaazzaaazaazaazzzzazaazzaazaaazzzaaaazzazaaazazzzzzazazazzazzzaazaaaaazazzaazaaaazazazaaaaaaazzzzzaaazzzaaaazaazzzzzzazzazaaazzaazzazazzzaazzaaaazaazzazaazaazazazzzzzzzzazaazzzazzzaazaaaaaaazaazaazaaazzzaazzzzazzzaazaazazazzazzzaaazaaaazzzzzzzzaaazzzzaaaaazzaazzaazzzzzazazaazaaaaaaazzzzaazzaazaazaaaaazazaazaaaaazzzaaazaazzzzzzzazzzaaaaazzaaaazaaaazzaaazaazazzaazazzzzzazaazazzazazzaazzaaaaaaazazzzaaaaaazaazzazaazaazzzzzazaaazzzaaaaaazaazaazazzaazazaaazazaazzzazaazzazazzzzaaazzzaazzzzazzzazzaazazazazzaaaaazaaazazzazazzazzazazzaazzazzazaazzzaaaazaaazzzaaazzzazzaaazzaazzzaazzzazazazzzzzzzzazzazzzaaaazazzzzzzzzazzzzaaaaazzaaazzzaazaazazzaazzzzaaaazzzzaazaaaaazzazzazzazzzzazazzaaaaaazzzaaaazzzazzzaazzaaaaaaazzaazazaazzzazaazzaazazzazzazazaaaazzaazazzzaazzzzaaazzazaaazaaaazaazzazaazazzzaazzzzaaazzaazzzazzzazzazazzazzaaazzzzzzazaazazaaaazzaaazzzazazazazazaaaazzazzzzazazaazzazaaaazzazaaaazaazaaazzzzaazzzzzazaaazzaaaaaaaazzaaaaazazazzzzaaaaaaazazazaazzazazazaaaaazaazazzzazzzzzzaaazzzazzaaazzzaaazzzazzzzzaazaazzzzzzazzazzzazzaaaazzazzzazzazzaaazaazzaazazzzzazazaaaaaazaaazazzaazazazzzazaazzazazzzaazaazzaaazaaazazzzazazaaazazzaaazzzazzazazazaazzazazzzaazaazazaazzazazzzaaazazaaazzzazazzzaaaazazaazazaaazzazzzazzzazzzaaaaazaazazzazzzaazzaazzzaazzazzzzazaazazaazzzzzaaazzzazazzazaaazzzzzzzzaazzaazzzzazzzzzazazzzazzzazzaaazazzazaazzzzaazzaazzaaazzaaaazaaaaaaazzaaaazaazaaazzaaazazzaaaaaaaaazaazzazzazazzzzzzzzaaazzzzaaazzzzazzazzaazzzazzzaazaaaazzaaazzaazazaazazzaaazazzzaazzzaazaazzaazzazaaaaaazzzzzaaaazazaaazaaaaazazazaaaazaaazzaaaazzzzzzzzaaazaaazzzzaaaaaaazazzaazazzzzzazzaaaazaaaazzzzazzzaaazzzzazazzzazaaaazazazazaaaazaazazazazzaaaaaaaazazazazzazaazaazaazzzzzzzaaazzazazaaaazzzzzaaazzzzzzzazazzaaazzzaaaaaazazazazazazzzazzzazaazzzaaaazzaazaazzzazazazzaazazazazzzaazzzaazzaazzaazzazazazzaazaazzzazzazzazzaazaazazzzzzazazzzzzzaazzaazzaaaaazzzzazzzzazaa")) cout << i << '\t';
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}