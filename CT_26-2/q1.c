// sort 안쓰고 해보기

#include <stdio.h>

typedef struct {
    int num;
    int start;
    int end;
} Meeting;

int main(void) {
    Meeting m[500], temp;
    int result[500];
    int N, i, j, min;
    int count = 0;
    int lastEnd = 0;

    scanf("%d", &N);

    // 회의 정보 입력
    for (i = 0; i < N; i++) {
        scanf("%d %d %d",
            &m[i].num, &m[i].start, &m[i].end);
    }

    // 종료시간을 기준으로 오름차순 정렬
    for (i = 0; i < N - 1; i++) {
        min = i;

        for (j = i + 1; j < N; j++) {
            if (m[j].end < m[min].end) {
                min = j;
            }
        }

        temp = m[i];
        m[i] = m[min];
        m[min] = temp;
    }

    // 종료시간이 빠른 회의부터 선택
    for (i = 0; i < N; i++) {
        if (m[i].start >= lastEnd) {
            result[count] = m[i].num;
            count++;
            lastEnd = m[i].end;
        }
    }

    // 결과 출력
    printf("%d\n", count);

    for (i = 0; i < count; i++) {
        printf("%d", result[i]);

        if (i < count - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
