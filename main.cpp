#include <iostream>
#include <vector>
#include <string>

using namespace std;

// functions
int patternN(double, string);
double whichOperator(char, vector<double>&);

int main() {
  
	// N & Pattern
  cout << "Pattern Problem: \n";

  // Test Statements
	patternN(1232, "ab+cd");
	patternN(3413289830, "a-bcdefghij");
  patternN(69074, "abc/de");
  patternN(164, "ab*c");
	patternN(2490, "abcd");


  return 0;
}

int patternN(double N, string p) {
	string temp = to_string(N); // convert N to string
	int i = 0, j = 0; // counters
	char op;
	vector<double> nums;
	string t = "";

	// get operator and length of both sides (ab+cd) => (2, 2, +)
	while (i < p.size()) {
		if (!isalpha(p[i])) {
			op = p[i];
			nums.push_back(stod(t));
			t = "";
		}
		else
			t += temp[j++];

		i++;
	}
	nums.push_back(stod(t));

  // make ouput look nicer
  cout << "[N: " << N << ", pattern: " << p << "] ";
	for (auto& i : nums) {
		cout << i << " ";
		if (i == nums[0])
			cout << op << " ";
	}

  if (op == '\0') {
    cout << "Error: operator is missing\n";
    return 0;
  }
	
  // switch for operator and calculates answer
  double ans = whichOperator(op, nums);

  // make ouput look nicer
	cout << "= " <<  ans << "\n";

	return ans;
}

// switch for operator and calculates answer
double whichOperator(char op, vector<double>& nums) {
  double ans = nums[0];
  switch (op) {
	case '+':
		for (auto& i : nums) {
			if (i != nums[0])
        ans += i;
    }
		break;
	case '-':
		for (auto& i : nums) {
			if (i != nums[0])			
        ans -= i;
    }
		break;
	case '/':
		for (auto& i : nums) {
			if (i != nums[0])
        ans /= (double) i;
    }
		break;
	case '*':
		for (auto& i : nums) {
			if (i != nums[0])
        ans *= i;
    }
		break;
	default:
		cout << "something\'s wrong" << endl;
	}

  return ans;
}