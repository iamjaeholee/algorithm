#include <iostream>
#include <queue>

int main(){
	int T;
	std::cin >> T;

	for (int i = 1; i<=T; i++){
		int R, K, N, sum=0;
		std::cin >> R >> K >> N;
		std::deque<int> dq(N), rc;

		for(int i=0; i<N; i++) std::cin >> dq[i];

		while(R--){
			int passengers = 0, ride=0;
			while(!dq.empty() && !ride){
				int front = dq.front();
				if(passengers + front <= K){
					passengers += front;
					rc.push_back(front);
					dq.pop_front();
				} else ride = 1;
			}

			// ride
			sum += passengers;
			while(!rc.empty()) {
				dq.push_back(rc.front());
				rc.pop_front();
			}
		}

		std::cout << "Case #" << i << ": " << sum << std::endl;
	}
}
