#include <stdio.h>
int main() {
        int data[] = {3,2,1,45,6,7, 25, 16, 0};
        int lh[9];
        int len = sizeof(data)/sizeof(data[0]);

        int lhcnt = 1;
        lh[0] = data[0];

        for(int i = 0; i< len; i++) {
                int j;
                for(j = 0; j< lhcnt; j++) {
                        if(lh[j] > data[i]) {
                                printf("%d > %d\n", lh[j], data[i]);

                                for(int k = lhcnt; k> j; k--) {
                                        lh[k] = lh[k-1];

                                }
                                lh[j] = data[i];
                                lhcnt++;
                                break;
                        }
                }

                if(j == lhcnt) {
                        lh[lhcnt - 1] = data[i];
                        printf("%d\n", j);
                        lhcnt++;
                }

        }


        for(int i=0; i< len; i++) {
                printf("%d,", lh[i]);
        }


        // your code goes here
        return 0;
}
