#include <bits/stdc++.h>
#include <limits>
int N, M;
int min_s = std::numeric_limits<int>::max();
int min_v(int m) {
	int v = 0;
	for (int R = M - m; R >=1; R--) {
		int H = R;
		v += R * R * H;
	}
	return v;
}
int max_v(int r, int h, int m) {
	int v = 0;
	for (int R = r, H =h; m <= M; R--, H--, m++) {
		v += R * R *H;
	}
	return v;
}

void dfs(int r, int h, int m, int s, int v) {
	if (m == M && N == v && s < min_s) {
		min_s = s;
		return;
	}
	if (r == 0 || s + 2 * (N -v) / r > min_s) {
		return;
	}
	if (min_v(m) > N-v) {
		return;
	}
	if (max_v(r, h, m) < N -v) {
		return;
	}
	for (int R = r - 1; R >= M - m; --R) {
		for (int H = h -1; H >= M -m; H--) {
			dfs(R, H, m + 1, s + 2 * R * H, v + R * R * H);
		}
	}

}

int main() {
	std::cin >> N >> M;
	for (int r1 = M; r1 * r1 <= N; ++r1) {
		for (int h1 = N / (r1 * r1); h1 >= M; --h1) {
			int s = r1 * r1 + 2 * r1 * h1;
			int v = r1 * r1 * h1;
			dfs(r1, h1, 1, s, v);
		}
	}
	if (min_s == std::numeric_limits<int>::max()) {
		std::cout << 0 << std::endl;
	} else {
		std::cout << min_s << std::endl;
	}
}