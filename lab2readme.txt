	From lect04, Thu 2014-1-16, ense470
	Presented in class as an activity.

   I have in mind three numbers with the following characteristics.  

   Each is a multiple of 3 and consists of three different non-zero
   digits, just one of which is 3.

   Each of the three numbers individually satisfies three of the
   following conditions, and fails three.

   1. the number is the product of three distinct primes
   2. the number is triangular (is in the series 1,3,6,10,15,...)
   3. the number is a cube, or a cube + 3
   4. the number may be written as a single digit prime followed by a 2-digit prime
   5. the 3 is the first or last digit
   6. the number may be written as a two-digit prime, followed by a single digit 
      prime.

   What are my three numbers?

   ----------------------------------------------------------------

   Solution constraints: In your solution it's not enough to simply
   tell me the three numbers.  You have to write good quality c++ code
   which systematically works toward the solution by successively
   applying the constraints.  Each constraint should be applied by
   calling a function, and that function should have unit tests which
   show that it works.

   Divide up the work into parts and estimate the hours required for
   each part.  This estimate should include the time to design, code,
   and test the part.

   This is a group project.  Assign parts to each group member so that
   each member has a roughly equivalent amount of work.  As each group
   member works on their parts, they should track the actual amount of
   time taken.  At the end of the project, sum the estimated hours,
   and divide by the sum of the actual hours.  This should be a number
   less than 1 (unless you greatly overestimated the time it would
   take).  This number is your *velocity*: a measure of your actual
   rate of work relative to your estimated rate of work.

   For subsequent work, you make your best estimate, then divide by
   the velocity to get a more realistic time.  For example if you
   estimated 10h in the last project, or the last iteration of an
   ongoing project, and you actually spent 18h, your velocity is 10/18
   or 0.56.  If the next estimate you do is, say, 12h, you divide by
   this to get 21.4h.  

   At the risk of predisposing people towards a particular solution, I
   offer some snippets of code from my own solution.

////////////////////////////////////////////////////////////////
// file: puzzle.h
/**
   Interface for puzzle routines.
 */

#include <vector>
std::vector<unsigned> ensure_divisible_by_3(const std::vector<unsigned>& seq);
std::vector<unsigned> ensure_exactly_one_digit_3(const std::vector<unsigned>& seq);
std::vector<unsigned> ensure_no_duplicate_digits(const std::vector<unsigned>& seq);
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
// file: test_puzzle.h
#include <vector>
#include "puzzle.h"
using namespace std;

class Test_puzzle : public CxxTest::TestSuite {
public:
    void test_divisible_by_3() {
	TS_ASSERT_EQUALS(ensure_divisible_by_3(vector<unsigned>({3, 4,5,6})),
			 vector<unsigned>({3,6}));
    }
    void test_exactly_one_3() {
	TS_ASSERT_EQUALS(ensure_exactly_one_digit_3(vector<unsigned>({333, 433,356,206})),
			 vector<unsigned>({356}));
    }
    void test_no_duplicate_digits() {
	TS_ASSERT_EQUALS(ensure_no_duplicate_digits(vector<unsigned>({333, 433,356,206})),
			 vector<unsigned>({356, 206}));
    }
};
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
// file: puzzle.cpp
#include <numeric> 		// for iota
#include <iostream>		// for cout, etc.
#include <vector>
#include <string>
#include <algorithm>		// for count()
#include "puzzle.h"

using namespace std;

vector<unsigned> ensure_divisible_by_3(const vector<unsigned>& seq) {
    vector<unsigned> result;
    
    for (auto n : seq) {
	if (n % 3 == 0)
	    result.push_back(n);
    }
    return result;
}
// ... stuff snipped out...
////////////////////////////////////////////////////////////////
