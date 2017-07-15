//This calculates factorials of non-negative integers[*] up to ULONG_MAX, which will have so many digits that it's unlikely your machine can store a whole lot more, even if it has time to calculate them. Uses the GNU multiple precision library, which you need to link against.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

void factorial(mpz_t result, unsigned long input) {
    mpz_set_ui(result, 1);
    while (input > 1) {
        mpz_mul_ui(result, result, input--);
    }
}

int main() {
    mpz_t fact;
    unsigned long input = 0;
    char *buf;

    mpz_init(fact);
    scanf("%lu", &input);
    factorial(fact, input);

    buf = malloc(mpz_sizeinbase(fact, 10) + 1);
    assert(buf);
    mpz_get_str(buf, 10, fact);
    printf("%s\n", buf);

    free(buf);
    mpz_clear(fact);
}
