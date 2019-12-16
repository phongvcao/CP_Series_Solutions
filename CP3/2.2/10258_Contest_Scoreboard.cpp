//
// Created by Phong Cao.
//

// uncomment to disable assert()
// #define NDEBUG
#include <cassert>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <ios>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <list>
#include <forward_list>
#include <deque>
#include <queue>
#include <stack>
#include <tuple>
#include <iterator>
#include <utility>
#include <algorithm>
#include <memory>
#include <cctype>
#include <stdexcept>
#include <limits>
#include <numeric>

//----< iostream >--------------//
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

//----< cstdio >----------------//
using std::printf;
using std::fprintf;
using std::sprintf;
using std::snprintf;

//----< iomanip >---------------//
using std::setprecision;
using std::setw;

//----< ios >-------------------//
using std::hex;
using std::dec;
using std::oct;
using std::fixed;

//----< sstream >---------------//
using std::stringstream;
using std::ostringstream;
using std::istringstream;

//----< fstream >---------------//
using std::ofstream;
using std::ifstream;

//----< string >----------------//
using std::getline;
using std::string;
using std::to_string;
using std::stoi;
using std::stol;

//----< cmath >-----------------//
using std::sqrt;
using std::pow;
using std::log;                 // log( <arg> )
using std::exp;                 // e ^ <arg>
using std::abs;
using std::fabs;
using std::floor;               // Round down to nearest integer double
using std::ceil;                // Round up to nearest integer double
using std::trunc;               // Truncate the fractional part to get the integer part
using std::round;               // Round to nearest integer double

//----< cstdlib >---------------//
using std::rand;
using std::srand;

//----< ctime >-----------------//
using std::time;

//----< functional >------------//
using std::hash;
using std::greater;             // lhs > rhs. Used for MinPQ
using std::less;                // lhs < rhs. Used for MaxPQ. Default for priority_queue<>
using std::less_equal;
using std::greater_equal;

//----< array >-----------------//
using std::array;               // Fixed & Unordered Array

//----< vector >----------------//
using std::vector;              // Resizable & Unordered Array

//----< map >-------------------//
using std::map;                 // Ordered Map (Red-Black Tree)
using std::multimap;            // Ordered Map (Red-Black Tree) & Allow duplicated keys

//----< unordered_map >---------//
using std::unordered_map;       // HashMap (SeparateChainingHashST)
using std::unordered_multimap;  // Ordered Map (Red-Black Tree) & Allow duplicated keys

//----< set >-------------------//
using std::set;                 // Ordered Set (Red-Black Tree)
using std::multiset;            // Ordered Set (Red-Black Tree) & Allow duplicated keys

//----< unordered_set >---------//
using std::unordered_set;       // HashSet (SeparateChainingHashST)
using std::unordered_multiset;  // HashSet (SeparateChainingHashST) & Allow duplicated keys

//----< list >------------------//
using std::list;                // Doubly-Linked List with size() ( O( 1 ) )

//----< forward_list >----------//
using std::forward_list;        // Singly-Linked List without size() function ( so O( N ) if we need to get size() )

//----< deque >-----------------//
using std::deque;               // Vector of fixed-size Vectors: 1 fixed-size vector for each end of the deque

//----< queue >-----------------//
using std::queue;               // Non-Iterable & Use std::deque as underlying data structure
using std::priority_queue;      // MaxPQ (MaxHeap) & Non-Iterable.
//                              // => Pass std::greater<> as template params to create MinPQ (MinHeap)

//----< stack >-----------------//
using std::stack;               // Non-Iterable & Use std::deque as underlying data structure

//----< tuple >-----------------//
using std::tuple;               // Non-Iterable & Use std::pair as underlying data structure
using std::get;                 // Access & Set element in tuple using get< index >( tuple_var )

//----< iterator >--------------//
using std::next;                // Return an advanced iter without changing original iter
using std::prev;                // Return an decremented iter without changing original iter
using std::distance;            // Calculate distance between 2 iterators
using std::inserter;            // Insert element into first arg starting from position in second arg

//----< utility >---------------//
using std::pair;
using std::make_pair;
using std::move;                // Move resources between objects - typically used with std::unique_ptr<T>

//----< algorithm >-------------//
using std::fill;
using std::max;
using std::min;
using std::find;
using std::reverse;
using std::sort;                // Intro-Sort elements, but NOT preserve original order of equal elements
using std::partial_sort;        // Sort elements in range ( iterFirst, iterLast ) ( exclusively )
using std::stable_sort;         // Merge-Sort elements & preserve original order of equal elements
using std::remove;
using std::swap;
using std::binary_search;
using std::next_permutation;
using std::prev_permutation;
using std::set_intersection;    // Only works on std::set and not std::unordered_set
using std::set_difference;      // Only works on std::set and not std::unordered_set
using std::set_union;
using std::lower_bound;         // Returns iter pointing to first element >= value
using std::upper_bound;         // Returns iter pointing to first element > value
// using std::nth_element;

//----< memory >----------------//
// using std::make_unique;
using std::unique_ptr;
using std::make_shared;
using std::shared_ptr;
using std::weak_ptr;

//----< cctype >----------------//
using std::isalnum;
using std::isalpha;
using std::islower;
using std::isupper;
using std::isdigit;
using std::isspace;             // Check whether char is whitespace character (space, newline, tab, etc. )
using std::isblank;             // Check whether char is blank character ( space or tab )
using std::tolower;
using std::toupper;

//----< stdexcept >-------------//
using std::runtime_error;
using std::invalid_argument;
using std::out_of_range;

//----< limits >----------------//
using std::numeric_limits;

//----< numeric >---------------//
using std::iota;
// using std::gcd;
// using std::lcm;

//------------------------------//

class Problem {
public:

    static const char SUBMISSION_CORRECT;
    static const char SUBMISSION_INCORRECT;
    static const char SUBMISSION_UNKNOWN;

    int readIndex = -1;
    int problemNum = 0;
    bool isSolved = false;
    int solveTime = 0;
    set< int > incorrectSet;

    Problem() {
        // not implemented
    }

    Problem( const Problem& other )
        : readIndex( other.readIndex ),
          problemNum( other.problemNum ),
          isSolved( other.isSolved ),
          solveTime( other.solveTime ),
          incorrectSet( other.incorrectSet )
    {
        // not implemented
    }

    int getIncorrectCount() const {
        return incorrectSet.size();
    }

    virtual ~Problem() {
        // not implemented
    }

};

const char Problem::SUBMISSION_CORRECT = 'C';
const char Problem::SUBMISSION_INCORRECT = 'I';
const char Problem::SUBMISSION_UNKNOWN = ' ';

class Contestant {
public:

    int readIndex = -1;
    int contestantNum = 0;
    unordered_map< int, Problem > problemsMap;
    int problemsSolvedCount = 0;

    Contestant() {
        // not implemented
    }

    Contestant( const Contestant& other )
        : readIndex( other.readIndex ),
          contestantNum( other.contestantNum ),
          problemsMap( other.problemsMap ),
          problemsSolvedCount( other.problemsSolvedCount )
    {
        // not implemented
    }

    virtual ~Contestant() {
        // not implemented
    }

    int getTotalTime() const {
        int rv = 0;
        for ( unordered_map< int, Problem >::const_iterator iter = problemsMap.begin(); iter != problemsMap.end(); iter++ ) {
            if ( iter->second.isSolved ) {
                rv += iter->second.solveTime;
                rv += iter->second.getIncorrectCount() * 20;
            }
        }
        return rv;
    }

    friend ostream& operator <<( ostream& out, const Contestant& contestant ) {
        out << contestant.contestantNum << " " << contestant.problemsSolvedCount << " " << contestant.getTotalTime();
        return out;
    }
};

struct cmpContestantPtrs {
    bool operator ()( const Contestant* c1, const Contestant* c2 ) const {
        if ( c1->problemsSolvedCount > c2->problemsSolvedCount ) {
            return true;
        } else if ( c1->problemsSolvedCount < c2->problemsSolvedCount ) {
            return false;
        } else {
            if ( c1->getTotalTime() < c2->getTotalTime() ) {
                return true;
            } else if ( c1->getTotalTime() > c2->getTotalTime() ) {
                return false;
            } else {
                return c1->contestantNum < c2->contestantNum;
            }
        }
    }
};

int main( int argc, char ** argv ) {

    int T = 0;
    string line = "";

    while ( getline( cin, line ) ) {
        if ( line.empty() ) continue;
        stringstream ss( line );
        ss >> T;
        break;
    }

    for ( int t = 0; t < T; t++ ) {
        unordered_map< int, Contestant > contestantsMap;

        while ( getline( cin, line ) ) {

            stringstream ss( line );
            int contestantNum = 0;
            int problemNum = 0;
            int timeStamp = 0;
            char verdict = Problem::SUBMISSION_UNKNOWN;
            ss >> contestantNum >> problemNum >> timeStamp >> verdict;
            
            if ( contestantNum == 0 ) {
                if ( contestantsMap.empty() ) {
                    continue;
                } else {
                    break;
                }
            }

            if ( contestantsMap.find( contestantNum ) == contestantsMap.end() ) {
                Contestant contestant;
                contestant.contestantNum = contestantNum;
                contestantsMap.insert( { contestantNum, contestant } );
            }
            
            Problem problem;
            problem.problemNum = problemNum;
            switch ( verdict ) {
                case Problem::SUBMISSION_CORRECT:
                {
                    problem.isSolved = true;
                    problem.solveTime = timeStamp;
                    break;
                }

                case Problem::SUBMISSION_INCORRECT:
                {
                    problem.incorrectSet.insert( timeStamp );
                    break;
                }

                default:
                {
                    break;
                }
            }

            if ( contestantsMap[ contestantNum ].problemsMap.find( problemNum ) == contestantsMap[ contestantNum ].problemsMap.end() ) {
                if ( verdict == Problem::SUBMISSION_CORRECT || verdict == Problem::SUBMISSION_INCORRECT ) {
                    contestantsMap[ contestantNum ].problemsMap.insert( { problemNum, problem } );
                }

                if ( verdict == Problem::SUBMISSION_CORRECT ) {
                    ++contestantsMap[ contestantNum ].problemsSolvedCount;
                }
            } else {
                if ( contestantsMap[ contestantNum ].problemsMap[ problemNum ].isSolved && problem.isSolved ) {
                    if ( contestantsMap[ contestantNum ].problemsMap[ problemNum ].solveTime > problem.solveTime ) {
                        contestantsMap[ contestantNum ].problemsMap[ problemNum ].solveTime = problem.solveTime;
                    }
                } else if ( ! contestantsMap[ contestantNum ].problemsMap[ problemNum ].isSolved && problem.isSolved ) {
                    contestantsMap[ contestantNum ].problemsMap[ problemNum ].isSolved = problem.isSolved;
                    contestantsMap[ contestantNum ].problemsMap[ problemNum ].solveTime = problem.solveTime;
                    ++contestantsMap[ contestantNum ].problemsSolvedCount;
                } else {
                    if ( verdict == Problem::SUBMISSION_INCORRECT && ! contestantsMap[ contestantNum ].problemsMap[ problemNum ].isSolved ) {
                        contestantsMap[ contestantNum ].problemsMap[ problemNum ].incorrectSet.insert( timeStamp );
                    }
                }
            }
        }

        set< Contestant *, cmpContestantPtrs > contestantsSet;
        for ( unordered_map< int, Contestant >::iterator iter = contestantsMap.begin(); iter != contestantsMap.end(); iter++ ) {
            contestantsSet.insert( &( iter->second ) );
        }

        for ( const Contestant * cPtr : contestantsSet ) {
            cout << *cPtr << endl;
        }

        if ( t < T - 1 ) {
            cout << endl;
        }
    }

    return 0;
}
