#include "arb_int.h"

int main(int argc, char **argv)
{
    arb_int_t a, b;
    arb_from_string(&a, "12345");
    arb_from_string(&b, "12345");

    arb_add(a, b);

    arb_int_t c = arb_duplicate (a);

    arb_free (a);
    arb_free (b);
    arb_free (c);

    return 0;
}
