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

class Team {
public:

    static const int POINTS_PER_WIN;
    static const int POINTS_PER_TIE;
    static const int POINTS_PER_LOSS;

    int readIndex = -1;
    string name = "";
    int pointsEarned = 0;
    int gamesPlayed = 0;
    int winsCount = 0;
    int tiesCount = 0;
    int lossesCount = 0;
    int goalsScored = 0;
    int goalsAgainst = 0;

    Team() {
        // not implemented
    }

    Team( const Team& other )
        : readIndex( other.readIndex ),
          name( other.name ),
          pointsEarned( other.pointsEarned ),
          gamesPlayed( other.gamesPlayed ),
          winsCount( other.winsCount ),
          tiesCount( other.tiesCount ),
          lossesCount( other.lossesCount ),
          goalsScored( other.goalsScored ),
          goalsAgainst( other.goalsAgainst )
    {
        // not implemented
    }

    virtual ~Team() {
        // not implemented
    }

    static pair< pair< string, int >, pair< string, int > > parseGameString( const string& gameStr ) {
        int firstHashIndex = gameStr.find_first_of( '#' );
        int firstAtIndex = gameStr.find_first_of( '@' );
        int lastHashIndex = gameStr.find_last_of( '#' );

        return { { gameStr.substr( 0, firstHashIndex ),
                   atoi( gameStr.substr( firstHashIndex + 1, firstAtIndex - firstHashIndex - 1 ).c_str() ) },
                 { gameStr.substr( lastHashIndex + 1 ),
                   atoi( gameStr.substr( firstAtIndex + 1, lastHashIndex - firstAtIndex - 1 ).c_str() ) }, };
    }

    friend ostream& operator <<( ostream& out, const Team& team ) {
        out << team.name << " "
            << team.pointsEarned << "p, "
            << team.gamesPlayed << "g ("
            << team.winsCount << "-" << team.tiesCount << "-"
            << team.lossesCount << "), "
            << team.goalsScored - team.goalsAgainst << "gd ("
            << team.goalsScored << "-" << team.goalsAgainst << ")";
        return out;
    }
};

const int Team::POINTS_PER_WIN = 3;
const int Team::POINTS_PER_TIE = 1;
const int Team::POINTS_PER_LOSS = 0;

struct cmpTeamPtrs {
    bool operator ()( const Team* t1, const Team* t2 ) const {
        if ( t1->pointsEarned > t2->pointsEarned ) {
            return true;
        } else if ( t1->pointsEarned < t2->pointsEarned ) {
            return false;
        } else {
            if ( t1->winsCount > t2->winsCount ) {
                return true;
            } else if ( t1->winsCount < t2->winsCount ) {
                return false;
            } else {
                if ( t1->goalsScored - t1->goalsAgainst > t2->goalsScored - t2->goalsAgainst ) {
                    return true;
                } else if ( t1->goalsScored - t1->goalsAgainst < t2->goalsScored - t2->goalsAgainst ) {
                    return false;
                } else {
                    if ( t1->goalsScored > t2->goalsScored ) {
                        return true;
                    } else if ( t1->goalsScored < t2->goalsScored ) {
                        return false;
                    } else {
                        if ( t1->gamesPlayed < t2->gamesPlayed ) {
                            return true;
                        } else if ( t1->gamesPlayed > t2->gamesPlayed ) {
                            return false;
                        } else {
                            string t1Name = t1->name;
                            string t2Name = t2->name;
                            for ( int i = 0; i < t1Name.size(); i++ ) {
                                t1Name[ i ] = tolower( t1Name[ i ] );
                            }
                            
                            for ( int i = 0; i < t2Name.size(); i++ ) {
                                t2Name[ i ] = tolower( t2Name[ i ] );
                            }
                            return t1Name < t2Name;
                        }
                    }
                }
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

    for ( int n = 0; n < N; n++ ) {
        string tourName = "";
        if ( getline( cin, line ) ) {
            tourName = line;
        }

        int numTeams = 0;
        if ( getline( cin, line ) ) {
            stringstream ss( line );
            ss >> numTeams;
        }

        unordered_map< string, Team > teamsMap;
        for ( int i = 0; i < numTeams; i++ ) {
            if ( getline( cin, line ) ) {
                if ( teamsMap.find( line ) == teamsMap.end() ) {
                    Team team;
                    team.name = line;
                    team.readIndex = i;
                    teamsMap.insert( { line, team } );
                }
            }
        }

        int numGames = 0;
        if ( getline( cin, line ) ) {
            stringstream ss( line );
            ss >> numGames;
        }

        for ( int i = 0; i < numGames; i++ ) {
            if ( getline( cin, line ) ) {
                pair< pair< string, int >, pair< string, int > > gameInfo = Team::parseGameString( line );

                ++teamsMap[ gameInfo.first.first ].gamesPlayed;
                ++teamsMap[ gameInfo.second.first ].gamesPlayed;

                if ( gameInfo.first.second > gameInfo.second.second ) {
                    // If first team wins
                    // Update first team info
                    teamsMap[ gameInfo.first.first ].pointsEarned += Team::POINTS_PER_WIN;
                    ++teamsMap[ gameInfo.first.first ].winsCount;
                    teamsMap[ gameInfo.first.first ].goalsScored += gameInfo.first.second;
                    teamsMap[ gameInfo.first.first ].goalsAgainst += gameInfo.second.second;

                    // Update second team info
                    teamsMap[ gameInfo.second.first ].pointsEarned += Team::POINTS_PER_LOSS;
                    ++teamsMap[ gameInfo.second.first ].lossesCount;
                    teamsMap[ gameInfo.second.first ].goalsScored += gameInfo.second.second;
                    teamsMap[ gameInfo.second.first ].goalsAgainst += gameInfo.first.second;

                } else if ( gameInfo.first.second < gameInfo.second.second ) {
                    // If second team win
                    // Update second team info
                    teamsMap[ gameInfo.second.first ].pointsEarned += Team::POINTS_PER_WIN;
                    ++teamsMap[ gameInfo.second.first ].winsCount;
                    teamsMap[ gameInfo.second.first ].goalsScored += gameInfo.second.second;
                    teamsMap[ gameInfo.second.first ].goalsAgainst += gameInfo.first.second;

                    // Update first team info
                    teamsMap[ gameInfo.first.first ].pointsEarned += Team::POINTS_PER_LOSS;
                    ++teamsMap[ gameInfo.first.first ].lossesCount;
                    teamsMap[ gameInfo.first.first ].goalsScored += gameInfo.first.second;
                    teamsMap[ gameInfo.first.first ].goalsAgainst += gameInfo.second.second;
                } else {
                    // If both team tie
                    // Update first team info
                    teamsMap[ gameInfo.first.first ].pointsEarned += Team::POINTS_PER_TIE;
                    ++teamsMap[ gameInfo.first.first ].tiesCount;
                    teamsMap[ gameInfo.first.first ].goalsScored += gameInfo.first.second;
                    teamsMap[ gameInfo.first.first ].goalsAgainst += gameInfo.second.second;

                    // Update second team info
                    teamsMap[ gameInfo.second.first ].pointsEarned += Team::POINTS_PER_TIE;
                    ++teamsMap[ gameInfo.second.first ].tiesCount;
                    teamsMap[ gameInfo.second.first ].goalsScored += gameInfo.second.second;
                    teamsMap[ gameInfo.second.first ].goalsAgainst += gameInfo.first.second;
                }
            }
        }
        
        set< Team *, cmpTeamPtrs > teamsSet;
        for ( unordered_map< string, Team >::iterator iter = teamsMap.begin(); iter != teamsMap.end(); iter++ ) {
            teamsSet.insert( &( iter->second ) );
        }

        cout << tourName << endl;
        int rankCount = 1;
        for ( const Team * teamPtr : teamsSet ) {
            cout << rankCount << ") " << *teamPtr << endl;
            ++rankCount;
        }

        if ( n < N - 1 ) {
            cout << endl;
        }
    }

    return 0;
}
