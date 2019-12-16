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
using std::transform;           // Apply the given function to a range and store result in another range
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
// using std::tolower;
// using std::toupper;

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

class Team {
public:

    static const int POINTS_PER_WIN;
    static const int POINTS_PER_TIE;
    static const int POINTS_PER_LOSS;

    int readIndex = -1;
    string name = "";
    int pointsScored = 0;
    int gamesPlayed = 0;
    int goalsScored = 0;
    int goalsSuffered = 0;

    Team() {
        // not implemented
    }

    Team( const Team& other )
        : readIndex( other.readIndex ),
          name( other.name ),
          pointsScored( other.pointsScored ),
          gamesPlayed( other.gamesPlayed ),
          goalsScored( other.goalsScored ),
          goalsSuffered( other.goalsSuffered )
    {
        // not implemented
    }

    int getGoalsDifference() const {
        return goalsScored - goalsSuffered;
    }

    double getPointsEarnedPercentage() const {
        return ( double )pointsScored * 100.0 / ( double )( 3 * gamesPlayed );
    }

    virtual ~Team() {
        // not implemented
    }

    friend bool operator ==( const Team& t1, const Team& t2 ) {
        return ( t1.pointsScored == t2.pointsScored )
                && ( t1.getGoalsDifference() == t2.getGoalsDifference() )
                && ( t1.goalsScored == t2.goalsScored );
    }

    friend bool operator !=( const Team& t1, const Team& t2 ) {
        return ! ( t1 == t2 );
    }

};

struct cmpTeamPtrs {
    bool operator ()( const Team* t1, const Team* t2 ) const {
        if ( t1->pointsScored > t2->pointsScored ) {
            return true;
        } else if ( t1->pointsScored < t2->pointsScored ) {
            return false;
        } else {
            if ( t1->getGoalsDifference() > t2->getGoalsDifference() ) {
                return true;
            } else if ( t1->getGoalsDifference() < t2->getGoalsDifference() ) {
                return false;
            } else {
                if ( t1->goalsScored > t2->goalsScored ) {
                    return true;
                } else if ( t1->goalsScored < t2->goalsScored ) {
                    return false;
                } else {
                    string t1TeamName = t1->name;
                    string t2TeamName = t2->name;
                    transform( t1TeamName.begin(), t1TeamName.end(), t1TeamName.begin(), ::tolower );
                    transform( t2TeamName.begin(), t2TeamName.end(), t2TeamName.begin(), ::tolower );
                    if ( t1TeamName == t2TeamName ) {
                        return t1->readIndex < t2->readIndex;
                    } else {
                        return t1TeamName < t2TeamName;
                    }
                }
            }
        }
    }
};

const int Team::POINTS_PER_WIN = 3;
const int Team::POINTS_PER_TIE = 1;
const int Team::POINTS_PER_LOSS = 0;

int main( int argc, char ** argv ) {

    int caseCount = 0;
    while ( true ) {
        int numTeams = 0;
        int numGames = 0;
        cin >> numTeams >> numGames;

        if ( numTeams == 0 && numGames == 0 ) break;

        unordered_map< string, Team > teamsMap;
        for ( int i = 0; i < numTeams; i++ ) {
            string teamName = "";
            cin >> teamName;

            if ( teamsMap.find( teamName ) == teamsMap.end() ) {
                Team team;
                team.readIndex = i;
                team.name = teamName;
                teamsMap.insert( { teamName, team } );
            }
        }

        for ( int i = 0; i < numGames; i++ ) {
            string team1Name = "";
            int team1GoalsScored = 0;
            string dashStr = "";
            int team2GoalsScored = 0;
            string team2Name = "";
            cin >> team1Name >> team1GoalsScored >> dashStr >> team2GoalsScored >> team2Name;

            ++teamsMap[ team1Name ].gamesPlayed;
            ++teamsMap[ team2Name ].gamesPlayed;
            teamsMap[ team1Name ].goalsScored += team1GoalsScored;
            teamsMap[ team1Name ].goalsSuffered += team2GoalsScored;
            teamsMap[ team2Name ].goalsScored += team2GoalsScored;
            teamsMap[ team2Name ].goalsSuffered += team1GoalsScored;

            if ( team1GoalsScored > team2GoalsScored ) {
                // Team 1 won
                // Update team1 info
                teamsMap[ team1Name ].pointsScored += Team::POINTS_PER_WIN;
                // Update team2 info
                teamsMap[ team2Name ].pointsScored += Team::POINTS_PER_LOSS;

            } else if ( team1GoalsScored < team2GoalsScored ) {
                // Team 2 won
                // Update team2 info
                teamsMap[ team2Name ].pointsScored += Team::POINTS_PER_WIN;
                // Update team1 info
                teamsMap[ team1Name ].pointsScored += Team::POINTS_PER_LOSS;
            } else {
                // This is a tie
                // Update team1 info
                teamsMap[ team1Name ].pointsScored += Team::POINTS_PER_TIE;
                // Update team2 info
                teamsMap[ team2Name ].pointsScored += Team::POINTS_PER_TIE;
            }
        }

        set< Team *, cmpTeamPtrs > teamsSet;
        for ( unordered_map< string, Team >::iterator iter = teamsMap.begin(); iter != teamsMap.end(); iter++ ) {
            teamsSet.insert( &( iter->second ) );
        }

        if ( caseCount > 0 ) {
            cout << endl;
        }

        int rankCount = 0;
        int trueRankCount = 0;
        const Team * prevTeamPtr = NULL;
        for ( const Team * teamPtr : teamsSet ) {
            bool sameRank = false;
            ++trueRankCount;
            if ( ! prevTeamPtr ) {
                prevTeamPtr = teamPtr;
            } else {
                if ( *teamPtr != *prevTeamPtr ) {
                } else {
                    sameRank = true;
                }
                prevTeamPtr = teamPtr;
            }

            if ( ! sameRank ) {
                rankCount = trueRankCount;
                printf( "%2d.", rankCount );
            } else {
                printf( "   " );
            }

            printf( "%16s%4d%4d%4d%4d%4d", teamPtr->name.c_str(), teamPtr->pointsScored, teamPtr->gamesPlayed, teamPtr->goalsScored, teamPtr->goalsSuffered, teamPtr->getGoalsDifference() );

            if ( teamPtr->gamesPlayed != 0 ) {
                printf( "%7.2f\n", teamPtr->getPointsEarnedPercentage() );
            } else {
                printf( "%7s\n", "N/A" );
            }
        }
        ++caseCount;
    }

    return 0;
}
