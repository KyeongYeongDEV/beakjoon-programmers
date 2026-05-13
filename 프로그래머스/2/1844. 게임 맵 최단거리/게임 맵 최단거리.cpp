#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> maps) {
    int N = maps.size();
    int M = maps[0].size();

    // 델타 배열 (상하좌우)
    int dy[] = {1, -1, 0, 0};
    int dx[] = {0, 0, 1, -1};

    // 1차원 압축된 좌표를 담는 큐
    queue<int> q;
    q.push(0); // (0,0) -> 0 * M + 0 = 0

    // 시작 지점의 거리를 1로 설정 (원본 1과 구분하기 위해 실제 거리 + 1로 저장)
    // 혹은 원본을 2로 바꾸고 나중에 1을 빼주는 방식
    maps[0][0] = 2;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        // 1차원 인덱스에서 2차원 좌표 복원
        int y = cur / M;
        int x = cur % M;

        // 목적지 도달 시 (현재 적힌 값 - 1) 반환
        if(y == N - 1 && x == M - 1)
            return maps[y][x] - 1;

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 경계 검사 및 길(1)인지 확인
            if(ny >= 0 && ny < N && nx >= 0 && nx < M && maps[ny][nx] == 1) {
                // 현재 칸의 거리 + 1을 다음 칸에 저장 (방문 체크 겸용)
                maps[ny][nx] = maps[y][x] + 1;
                q.push(ny * M + nx);
            }
        }
    }

    return -1;
}