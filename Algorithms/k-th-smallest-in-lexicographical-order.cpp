// 440. K-th Smallest in Lexicographical Order
// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/64624/concise-easy-to-understand-java-5ms-solution-with-explaination
// class Solution {
// public:
// 	int findKthNumber(int n, int k) {

// 	}
// };
// END: https://discuss.leetcode.com/topic/64624/concise-easy-to-understand-java-5ms-solution-with-explaination

// BEGIN: Time Limit Exceeded
class Solution {
public:
	int findKthNumber(int n, int k) {
		int result = 0;
		for (int i = 0; i < k; i++) {
			result = next(result, n);
		}
		return result;
	}
private:
	int next(int val, const int n) {
		if (!val) return 1;
		if (size_t(10 * val) <= size_t(n)) return 10 * val;
		int valp1 = val + 1;
		if (valp1 <= n && valp1 % 10 != 0) return valp1;
		if (valp1 % 10 == 0) {
			while (valp1 % 10 == 0) valp1 /= 10;
			return valp1;
		}
		val = val / 10 + 1;
		while (val % 10 == 0) val /= 10;
		return val;
	}
};

// class Solution {
// public:
// 	int findKthNumber(int n, int k) {
// 		int result = 0;
// 		for (int i = 0; i < k; i++) {
// 			result = next(result, n);
// 		}
// 		return result;
// 	}
// private:
// 	int next(int val, const int n) {
// 		if (!val) return 1;
// 		if (size_t(10 * val) <= size_t(n)) return 10 * val;
// 		string val_str = to_string(val);
// 		string valp1_str = to_string(val + 1);
// 		if (val + 1 <= n && valp1_str.back() != '0') return val + 1;
// 		if (valp1_str.back() == '0') {
// 			while (valp1_str.back() == '0') valp1_str.pop_back();
// 			return stoi(valp1_str);			
// 		}
// 		int new_val = val / 10 + 1;
// 		string new_val_str = to_string(new_val);
// 		if (new_val_str.back() != '0') return new_val;
// 		while (new_val_str.back() == '0') new_val_str.pop_back();
// 		return stoi(new_val_str);
// 	}
// };

// class Solution {
// public:
// 	int findKthNumber(int n, int k) {
// 		vector<string> OPT;
// 		for (int i = 1; i <= n; i++) {
// 			const string str = to_string(i);
// 			OPT.push_back(str);
// 		}
// 		sort(begin(OPT), end(OPT));
// 		return stoi(OPT[k - 1]);
// 	}
// };
// END: Time Limit Exceeded
int main(void) {
	Solution solution;
	int result = 0;
	result = solution.findKthNumber(100, 10);
	assert(17 == result);
	result = solution.findKthNumber(10, 3);
	assert(2 == result);
	result = solution.findKthNumber(13, 2);
	assert(10 == result);
	result = solution.findKthNumber(4289384, 1922239);
	assert(2730010 == result);
	result = solution.findKthNumber(7747794, 5857460);
	assert(6271710 == result);
	result = solution.findKthNumber(681692778, 351251360);
	assert(416126219 == result);
	cout << "\nPassed All\n";
	return 0;
}