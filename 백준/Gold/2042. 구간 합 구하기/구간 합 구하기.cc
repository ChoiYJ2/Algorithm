#include <iostream>

using namespace std;

int n, m, k;
long long int num[1000001];
long long int tree[4000001]; // 구간 합 트리. 2의 제곱 형태의 길이를 가지기 때문에 4를 곱하면 모든 범위 커버 가능.

// 구간 합 트리를 생성한다.
long long int init(int start, int end, int node) {
	if (start == end) return tree[node] = num[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

// 구간 합을 구한다.
long long int sum(int start, int end, int node, int left, int right) {
	// 범위 밖
	if (left > end || right < start) return 0;
	// 범위 안
	if (left <= start && end <= right) return tree[node];
	// 합 구하기
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, long long int dif) {
	// 범위 밖
	if (index < start || index > end) return;
	// 범위 안
	tree[node] += dif;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	init(0, n - 1, 1);
	for (int i = 0; i < m + k; i++)
	{
		long long int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			update(0, n - 1, 1, b - 1, c - num[b - 1]);
			num[b - 1] = c;
		}
		else if (a == 2)
			cout << sum(0, n - 1, 1, b - 1, c - 1) << "\n";
	}

	return 0;
}