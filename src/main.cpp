#include <iostream>
#include <vector>
#include <string>

using namespace std;

using vi = vector<int>;
using vc = vector<char>;
using vvc = vector<vc>;

vvc maze(102, vc(102, '#'));

vi dx{ 0, -1, 0, 1 };
vi dy{ 1, 0, -1, 0 };

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	auto sx = int{ 50 };
	auto sy = int{ 50 };
	maze[sy][sx] = '.';

	auto l = sx;
	auto r = sx;
	auto t = sy;
	auto b = sy;

	auto d = int{ 0 };

	int n;
	cin >> n;

	string moves;
	cin >> moves;

	for (int i = 0; i < n; ++i) {
		const auto& m = moves[i];
		if ('F' == m) {
			sx += dx[d];
			sy += dy[d];
			maze[sy][sx] = '.';

			if (sx < l) {
				l = sx;
			}

			if (r < sx) {
				r = sx;
			}

			if (sy < t) {
				t = sy;
			}

			if (b < sy) {
				b = sy;
			}
		}
		else if ('R' == m) {
			d += 1;
			d %= 4;
		}
		else if ('L' == m) {
			d -= 1;
			d = (d + 4) % 4;
		}
	}

	for (int y = t; y <= b; ++y) {
		for (int x = l; x <= r; ++x) {
			cout << maze[y][x];
		}
		cout << '\n';
	}

	return 0;
}