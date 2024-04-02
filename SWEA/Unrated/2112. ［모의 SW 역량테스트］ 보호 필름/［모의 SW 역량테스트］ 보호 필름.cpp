#include<iostream>
#include<cstring>
using namespace std;
int D; // 두께
int W; // 가로 크기
int K; // 합격 기준
int film[20][20]; // 보호 필름
int COPY[20][20]; // 복사본 // 라인별로 비교 // DFS 돌렸을 때, 복구 하기 위해서
int injectioncnt;
int ans = 21e8;
bool test() {
	//1. 세로 방향으로 K개 이상 연결된 A또는 B가 모든 열에 있는가?
	// 지금 선택한 라인 기준으로 세로방향(D) 만큼 확인
	// 합격기준 K 이상이면 다음열 체크 오른쪽으로 W 만큼 진행.
	for (int i = 0; i < W; i++) {
		// 기준점 잡기
		int base = COPY[0][i];//무조건 맨위에 있는 거부터 시작~!!!
		int cnt = 0;
		int flag = 0; //0 유효하지 않다. 1 유효하다.
		for (int j = 0; j < D; j++) {
			//지금 내가 보고 있는 열의 칸이 base와 동일하다면
			//연속된 동일한 약품을 하나 더 찾았다~!!
			if (base == COPY[j][i]) {
				cnt++;
				// cnt를 늘리는 순간 이게 합격 기준 K개 이상이다 flag = 1 유효하다라고 체크하고 break
				if (cnt >= K) {
					flag = 1;
					break;
				}
			}
			else {
				//2. 세로 방향으로 확인을 했는데
				// 다른 약품이다~!!
				// 다음 행으로 아래로 이동
				// base
				base = COPY[j][i];
				//base가 바뀌었으니 -> 새롭게 연속되는 약품을 한개는 찾았다~!!
				cnt = 1;
			}
		}
		// 지금 보는 이 열을 다 체크 했는데 유효하지 않은 경우 불량~!!
		if (flag == 0)
			return false;
	}
	return true;// 통과~!!
}
void func(int level) {
	//기저 조건 -> D 번 행에 도달하면
	if (level == D) {
		//성능 테스트
		if (test() == true) {
			//최소 약품 횟수
			if (injectioncnt < ans) {
				ans = injectioncnt;
			}
		}
		return;
	}
	//백트래킹
	if (injectioncnt >= ans)
		return;
	// <
	//가라
	// 1. 아무것도 안하는 경우
	func(level + 1);
	// 2. 약품을 A로 바꾸는 경우
	for (int i = 0; i < W; i++) {
		COPY[level][i] = 0; // 0 > A약품   1 > B약품
	}
	injectioncnt++;
	func(level + 1);
	//복구
	for (int i = 0; i < W; i++) {
		COPY[level][i] = film[level][i];
	}
	injectioncnt--;

	// 3. 약품을 B로 바꾸는 경우
	for (int i = 0; i < W; i++) {
		COPY[level][i] = 1; // 0 > A약품   1 > B약품
	}
	injectioncnt++;
	func(level + 1);
	//복구
	for (int i = 0; i < W; i++) {
		COPY[level][i] = film[level][i];
	}
	injectioncnt--;
}
void input() {
	//input
	cin >> D >> W >> K;
	//필름 정보
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < W; j++) {
			cin >> film[i][j];
			COPY[i][j] = film[i][j];
		}
	}
}
void init() {
	injectioncnt = 0;
	ans = 21e8;
	memset(film, 0, sizeof(film));
	memset(COPY, 0, sizeof(COPY));
}
void solve() {
	if (test()) {
		ans = 0; // 애초에 약품투입을 하지 않아도 되는 경우
		return;
	}
	else {
		func(0); // 약품을 투입해야 하는 경우, 0 (baseLine)번 라인부터 시작하는 DFS
	}
}
int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solve();
		cout << "#" << tc << " " << ans << "\n";
	}
}
