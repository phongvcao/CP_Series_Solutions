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
using std::set_intersection;    // Only works on std::set and not std::unordered_set
using std::set_difference;      // Only works on std::set and not std::unordered_set
using std::set_union;
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

    char problemLetter = ' ';
    bool isSolved = false;
    int solveTime = 0;
    int rejectedCount = 0;

    set< int > rejectedTimeSet;

    Problem() {
        // not implemented
    }

    Problem( const Problem& other )
        : problemLetter( other.problemLetter ),
          isSolved( other.isSolved ),
          solveTime( other.solveTime ),
          rejectedCount( other.rejectedCount ),
          rejectedTimeSet( other.rejectedTimeSet )
    {
        // not implemented
    }

    virtual ~Problem() {
        // not implemented
    }

    int getRejectedCount() const {
        set< int >::iterator lowerBoundIter = rejectedTimeSet.upper_bound( solveTime );

        if ( lowerBoundIter == rejectedTimeSet.end() ) {
            return rejectedTimeSet.size();
        } else {
            return distance( rejectedTimeSet.begin(), lowerBoundIter );
        }
    }

    static int getTimeFromString( const string& timeStr ) {
        return ( timeStr[ 0 ] - '0' ) * 60 + atoi( timeStr.substr( 2 ).c_str() );
    }
};

class Team {
public:

    int teamNum = -1;
    unordered_map< char, Problem > problemsMap;
    int problemsSolvedCount = 0;

    Team() {
        // not implemented
    }

    Team( const Team& other )
        : teamNum( other.teamNum ),
          problemsMap( other.problemsMap ),
          problemsSolvedCount( other.problemsSolvedCount )
    {
        // not implemented
    }

    virtual ~Team() {
        // not implemented
    }

    int getTotalSolveTime() const {
        int rv = 0;
        for ( unordered_map< char, Problem >::const_iterator iter = problemsMap.begin(); iter != problemsMap.end(); iter++ ) {
            if ( iter->second.isSolved ) {
                rv += iter->second.solveTime + iter->second.getRejectedCount() * 20;
            }
        }
        return rv;
    }

    friend bool operator ==( const Team& t1, const Team& t2 ) {
        return ( t1.problemsSolvedCount == t2.problemsSolvedCount && t1.getTotalSolveTime() == t2.getTotalSolveTime() );
    }
    
    friend bool operator !=( const Team& t1, const Team& t2 ) {
        return ! ( t1 == t2 );
    }
};

struct cmpTeamByProblemsAndTime {
    bool operator ()( const Team* t1, const Team* t2 ) const {
        if ( t1->problemsSolvedCount > t2->problemsSolvedCount ) {
            return true;
        } else if ( t1->problemsSolvedCount < t2->problemsSolvedCount ) {
            return false;
        } else {
            if ( t1->getTotalSolveTime() < t2->getTotalSolveTime() ) {
                return true;
            } else if ( t1->getTotalSolveTime() > t2->getTotalSolveTime() ) {
                return false;
            } else {
                return t1->teamNum < t2->teamNum;
            }
        }
    }
};

int main( int argc, char ** argv ) {

    string line = "";
    int N = 0;

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> N;
    }

    getline( cin, line );

    for ( int n = 0; n < N; n++ ) {
        unordered_map< int, Team > teamsMap;
        int maxTeamNum = -1;
        while ( getline( cin, line ) ) {
            if ( line.empty() ) break;

            stringstream ss( line );

            int teamNum = -1;
            char problemLetter = ' ';
            string timeStr = "";
            char runStatus = ' ';
            ss >> teamNum >> problemLetter >> timeStr >> runStatus;

            if ( teamNum > maxTeamNum ) maxTeamNum = teamNum;

            if ( teamsMap.find( teamNum ) == teamsMap.end() ) {
                Team team;
                team.teamNum = teamNum;
                teamsMap.insert( { teamNum, team } );
            }

            Problem problem;
            problem.problemLetter = problemLetter;
            problem.solveTime = Problem::getTimeFromString( timeStr );
            if ( runStatus == 'Y' ) {
                problem.isSolved = true;
            } else {
                problem.rejectedTimeSet.insert( problem.solveTime );
                ++problem.rejectedCount;
            }

            if ( teamsMap[ teamNum ].problemsMap.find( problemLetter ) == teamsMap[ teamNum ].problemsMap.end() ) {
                teamsMap[ teamNum ].problemsMap.insert( { problemLetter, problem } );

                if ( runStatus == 'Y' ) {
                    ++teamsMap[ teamNum ].problemsSolvedCount;
                }
            } else {
                if ( ! teamsMap[ teamNum ].problemsMap[ problemLetter ].isSolved && runStatus == 'Y' ) {
                    ++teamsMap[ teamNum ].problemsSolvedCount;
                }
            }

            if ( ( ! teamsMap[ teamNum ].problemsMap[ problemLetter ].isSolved
                        || problem.solveTime < teamsMap[ teamNum ].problemsMap[ problemLetter ].solveTime )
                    && runStatus == 'Y' ) {
                teamsMap[ teamNum ].problemsMap[ problemLetter ].solveTime = problem.solveTime;
            }

            if ( runStatus == 'Y' ) {
                teamsMap[ teamNum ].problemsMap[ problemLetter ].isSolved = true;
            } else {
                teamsMap[ teamNum ].problemsMap[ problemLetter ].rejectedTimeSet.insert( problem.solveTime );
            }
        }

        for ( int i = 1; i < maxTeamNum + 1; i++ ) {
            if ( teamsMap.find( i ) == teamsMap.end() ) {
                Team team;
                team.teamNum = i;
                teamsMap.insert( { i, team } );
            }
        }

        // Logic starts here
        set< Team *, cmpTeamByProblemsAndTime > teamsSet;
        for ( unordered_map< int, Team >::iterator iter = teamsMap.begin(); iter != teamsMap.end(); iter++ ) {
            teamsSet.insert( &( iter->second ) );
        }

        cout << "RANK TEAM PRO/SOLVED TIME" << endl;
        int rankCount = 0;
        int trueRankCount = 1;
        const Team * prevTeamPtr = NULL;
        for ( const Team * teamPtr : teamsSet ) {
            if ( prevTeamPtr ) {
                if ( *teamPtr != *prevTeamPtr ) {
                    rankCount = trueRankCount;
                }
            } else {
                rankCount = trueRankCount;
            }
            
            printf( "%4d%5d", rankCount, teamPtr->teamNum );
            if ( teamPtr->problemsSolvedCount > 0 ) {
                printf( "%5d", teamPtr->problemsSolvedCount );
                printf( "%11d", teamPtr->getTotalSolveTime() );
            }
            printf( "\n" );
            prevTeamPtr = teamPtr;
            ++trueRankCount;
        }

        if ( n < N - 1 ) {
            cout << endl;
        }
    }

    return 0;
}
