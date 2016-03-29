//
//  problem_1654.c
//  
//
//  Created by 박거성 on 2016. 3. 24..
//
//

#include <stdio.h>

int K, N, i, lines[10000], count, answer;
long long maxLength, l, r, mid;

int main(){
    scanf("%d %d", &K, &N);
    for (i = 0; i < K; i++) {
        scanf("%d", &lines[i]);
        maxLength += lines[i];
    }
    l = 1;
    r = maxLength / N;
    while (l <= r) {
        mid = (l + r) / 2;
        count = 0;
        for (i = 0; i < K; i++) count += (lines[i] / mid);
        if (count < N) r = mid - 1;
        else {
            if (answer < mid) answer = mid;
            l = mid + 1;
        }
    }
    printf("%d\n", answer);
    return 0;
}