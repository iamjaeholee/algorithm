#include <iostream>
#include <vector>
#include <map>

int main() {
	int r, c, k; std::cin >> r >> c >> k;
	std::vector<std::vector<int>> map(4, std::vector<int> (4));
	for(int i=1; i<=3; i++){
		for(int j=1; j<=3; j++){
			std::cin >> map[i][j];
		}
	}

	int r=3, c=3;

	for(int i=0; i<100; i++){
		if(r >= c) { // R
			for(int j=1; j<=r; j++){
				int greatest=0;

				// iterating r
				std::map<int, int> m;
				for(int k=1; k<=c; k++){
					int cur = map[j][k];

					if(cur == 0) continue;

					std::map<int, int>::iterator it = m.find(cur);
					if(it != m.end()) m[cur] = m[cur] + 1;
					else m[cur] = 1;
				}

				// sort

				// make new vector
				std::map<int, int>::iterator it = m.begin();
				std::vector<int> temp(1);

				while(it != m.end()){
					temp.push_back(it->first);
					temp.push_back(it->second);
				}

				// check value
				greatest = std::max(greatest, temp.size());

				// change vector


			}
		}
	}

	return 0;
}