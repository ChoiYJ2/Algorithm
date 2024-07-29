#include <iostream>

int A[500][500];
int N;
int r, c; // 현재 위치 행, 열
int d = 0, cnt = 1; // 현재 방향, 간 횟수

int ans = 0; // 토네이도가 소멸되었을 때, 격자의 밖으로 나간 모래의 양

// 서, 남, 동, 북
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

double sandP[9] = {0.01, 0.01, 0.07, 0.07, 0.02, 0.02, 0.1, 0.1, 0.05};
// 서, 남, 동, 북 같은 d방향으로 모래 흩날림
// a방향까지 해서 10이여야함
int sandX[4][10] = {{0, 0, -1, -1, -1, -1, -2, -2, -3, -2},
                    {-1, 1, -1, 1, -2, 2, -1, 1, 0, 0},
                    {0, 0, 1, 1, 1, 1, 2, 2, 3, 2},
                    {-1, 1, -1, 1, -2, 2, -1, 1, 0, 0}};
int sandY[4][10] = {{-1, 1, -1, 1, -2, 2, -1, 1, 0, 0},
                    {0, 0, 1, 1, 1, 1, 2, 2, 3, 2},
                    {-1, 1, -1, 1, -2, 2, -1, 1, 0, 0},
                    {0, 0, -1, -1, -1, -1, -2, -2, -3, -2}};

// 모래는 다음과 같이 일정한 비율로 흩날리게 된다
void sand(int x, int y, int dir){
  // y 위치
  int yx = x + dx[dir];
  int yy = y + dy[dir];

  // yAmount 계속 변하기 때문에 처음값 따로 변수로 저장해줘야함
  int yAmount = A[yy][yx];

  // y 모래 날릴 거 없으면 패스
  if(A[yy][yx] == 0){
    return;
  }

  for(int i = 0; i < 9; i++){
    int nx = x + sandX[dir][i];
    int ny = y + sandY[dir][i];
    double percent = sandP[i];

    // y의 모든 모래 해당 비율만큼 소수점 아래는 버린다
    int amount = yAmount * percent;

    // 모래가 격자의 밖으로 이동할 수도 있다. 격자의 밖으로 나간 모래의 양 구하기
    if(nx < 1 || ny < 1 || nx > N || ny > N){
      ans += amount;
    } else {
      // 모래 이동
      A[ny][nx] += amount;
    }
    // 모래 이동했으므로 모래 양 그만큼 뺴주기
    A[yy][yx] -= amount;
  }

  // α로 이동하는 모래의 양은 비율이 적혀있는 칸으로 이동하지 않은 남은 모래의 양과 같다.
  int nx = x + sandX[dir][9];
  int ny = y + sandY[dir][9];

  // 모래가 격자의 밖으로 이동할 수도 있다. 격자의 밖으로 나간 모래의 양 구하기
  if(nx < 1 || ny < 1 || nx > N || ny > N){
    ans += A[yy][yx];
  } else {
    // 모래 이동
    A[ny][nx] += A[yy][yx];
  }
  // y의 모든 모래가 비율과 α가 적혀있는 칸으로 이동 완료되어 모래양 0
  A[yy][yx] = 0;
}

int main(){
  scanf("%d", &N);

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      scanf("%d", &A[i][j]);
    }
  }

  // 중간 시작 좌표 설정
  r = (N+1)/2; // N은 항상 홀수
  c = (N+1)/2;

  // 토네이도는 (1, 1)까지 이동한 뒤 소멸
  //r != 1 && c != 1 이거 하면 안됨 (1,1) -> (0, 0) : 항상 서쪽으로 이동해서 종료됨
  while(r != 0 && c != 0){
    // cnt번만큼 2번씩 이동하는 토네이도
    for(int i = 0; i < 2; i++){
      for(int j = 0; j < cnt; j++){
        // 토네이도가 한 칸 이동할 때마다 모래는 다음과 같이 일정한 비율로 흩날리게 된다
        sand(r, c, d);
        // 토네이도 이동
        r += dx[d];
        c += dy[d];
      }

      // 방향 이동
      d = (d+1) % 4; // 0 ~ 4 반복
    }
    cnt++; // cnt 증가
  }

  printf("%d", ans);

  return 0;
}