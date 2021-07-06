#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int calcValue(std::vector<int> input){
	int lastIndex = input.size() - 1;
	sort(input.begin(), input.end());

	return input[lastIndex] - input[0];
}

int find(std::vector<int> input, const int m){
	int minAnswer = INT_MAX;
	int inputSize = input.size();
	std::vector<int> answer; // holding selected answers

	if(m == 1) return calcValue(input); // return last division

	else for(int i=1; i<=inputSize-m+1; i++) {
		answer = std::vector<int>(input.begin(), input.begin()+i);
		std::vector<int> nextVector = std::vector<int>(input.begin()+i, input.end());
		minAnswer = std::min(minAnswer, std::max(find(nextVector, m-1), calcValue(answer)));
	}

	return minAnswer;
}

int main(){
	// input
	int N, M; std::cin >> N >> M;
	std::vector<int> inputNumbers(N);
	for(int i=0; i<N; i++) std::cin >> inputNumbers[i];

	// manipulate
	std::cout << find(inputNumbers, M);

	return 0;
}