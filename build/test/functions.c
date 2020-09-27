#include "ctest.h"
#include "functions.h"

CTEST(logic_suite, convert_number) {
    int number = 1234;
    int convNum[4] = {};
    convertNumber(number, convNum);
    int expNum[4] = {1, 2, 3, 4};
    ASSERT_DATA((unsigned char*)expNum, 4,
                (unsigned char*)guess, 4);

    number = 1122;
    ASSERT_FALSE(convertNumber(num, guess));
    number = 123;
    ASSERT_FALSE(convertNumber(num, guess));
    number = 12345;
    ASSERT_FALSE(convertNumber(num, guess));
    number = 0123;
    ASSERT_FALSE(convertNumber(num, guess));
}
CTEST(logic_suite, bulls_count) {
    int numk[4]   = {1, 2, 3, 4};
    int guess[4] = {1, 2, 4, 3};
    ASSERT_EQUAL(2, bulls_cows(numk, guess));

    guess[0] = 5;
    guess[1] = 6;
    guess[2] = 7;
    guess[3] = 8;
    ASSERT_EQUAL(0, bulls_cows(numk, guess));

    guess[0] = numk[0];
    guess[1] = numk[1];
    guess[2] = numk[2];
    guess[3] = numk[3];
    ASSERT_EQUAL(4, bulls_cows(numk, guess));
}
CTEST(logic_suite, cows_count) {
    int numk[4]   = {1, 2, 3, 4};
    int guess[4] = {3, 0, 1, 5};
    int bulls;
    ASSERT_EQUAL(2, cows(numk, guess, bulls));

    guess[0] = 5;
    guess[1] = 6;
    guess[2] = 7;
    guess[3] = 8;
    ASSERT_EQUAL(0, cows(numk, guess, bulls));

    numk[0] = guess[3];
    numk[1] = guess[2];
    numk[2] = guess[1];
    numk[3] = guess[0];
    ASSERT_EQUAL(4, cows(numk, guess, bulls));
}