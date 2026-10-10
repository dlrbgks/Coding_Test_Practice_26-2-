
#include <stdio.h>

int paper[128][128];
int white = 0;
int blue = 0;

// 검사용 함수 만들기
void divide(int x, int y, int size) {
    int i, j;
    int color = paper[x][y];
    int same = 1;
    int half;

    // 영역 안에 다른 색이 있는지 확인
    for (i = x; i < x + size; i++) {
        for (j = y; j < y + size; j++) {
            if (paper[i][j] != color) {
                same = 0;
                break;
            }
        }

        if (same == 0) {
            break;
        }
    }

    // 모든 칸의 색이 같으면 개수 증가
    if (same == 1) {
        if (color == 0) {
            white++;
        }
        else {
            blue++;
        }
        return;
    }

    // 색이 다르면 4등분
    // 홀수용 매커니즘 없어도 됨
    half = size / 2;

    divide(x, y, half);               // 좌상
    divide(x, y + half, half);        // 우상
    divide(x + half, y, half);        // 좌하
    divide(x + half, y + half, half); // 우하
}

int main(void) {
    int N;
    int i, j;

    scanf("%d", &N);

    // 색종이 정보 입력
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &paper[i][j]);
        }
    }

    // 0,0 부터 검사 스타트
    divide(0, 0, N);

    printf("%d\n", white);
    printf("%d\n", blue);

    return 0;
}
