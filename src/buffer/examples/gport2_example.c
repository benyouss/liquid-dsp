//
// gport2 (generic port) example
//

#include <stdio.h>
#include <stdlib.h>

#include "../src/buffer.h"

int main() {
    // options
    unsigned int n=16;
    int w[n], r[n];

    // create port
    gport2 p = gport2_create(n,sizeof(int));

    // initialize data
    unsigned int i;
    for (i=0; i<n; i++)
        w[i] = i;

    // producer
    printf("  producing 8 elements...\n");
    gport2_produce(p,(void*)w,8);
    printf("  producer finished\n");

    // consumer
    printf("  consuming 8 elements...\n");
    gport2_consume(p,(void*)r,8);
    printf("  consumer finished\n");

    for (i=0; i<8; i++)
        printf(" r(%2u) = %d\n",i,r[i]);
    
    // print status
    gport2_print(p);

    gport2_destroy(p);

    printf("done.\n");
    return 0;
}
