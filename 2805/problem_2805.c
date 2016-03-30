//
//  problem_2805.c
//  
//
//  Created by 박거성 on 2016. 3. 30..
//
//

#include <stdio.h>

int N, M, i, r, l;
long long max, mid, answer, temp;

int main(){
    scanf("%d %d", &N, &M);
    int trees[N];
    for (i = 0; i < N; i++) {
        scanf("%d", &trees[i]);
        if (max <= trees[i]) max = trees[i];
    }
    r = max;
    l = 1;
    while (l <= r) {
        mid = (r + l) / 2;
        temp = 0;
        for (i = 0; i < N; i++){
            if (trees[i] / mid != 0) temp += (trees[i] - mid);
        }
        if (temp >= M) {
            if (answer <= mid) answer = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    printf("%lld\n", answer);
    return 0;
}