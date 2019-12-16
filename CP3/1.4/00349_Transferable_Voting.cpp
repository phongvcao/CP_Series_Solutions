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

class Candidate {
public:

    int index = -1;
    unordered_set< int > votersSet;

    Candidate() {
        // not implemented
    }

    Candidate( const Candidate& other )
        : index( other.index ),
          votersSet( other.votersSet )
    {
        // not implemented
    }

    virtual ~Candidate() {
        // not implemented
    }

    friend bool operator ==( const Candidate& c1, const Candidate& c2 ) {
        return c1.votersSet.size() == c2.votersSet.size();
    }

    friend bool operator !=( const Candidate& c1, const Candidate& c2 ) {
        return ! ( c1 == c2 );
    }

    friend bool operator <( const Candidate& c1, const Candidate& c2 ) {
        if ( c1.votersSet.size() < c2.votersSet.size() ) {
            return true;
        } else if ( c1.votersSet.size() > c2.votersSet.size() ) {
            return false;
        } else {
            if ( c1.index < c2.index ) {
                return true;
            } else if ( c1.index > c2.index ) {
                return false;
            } else {
                return false;
            }
        }
    }

    friend ostream& operator <<( ostream& out, const Candidate& candidate ) {
        out << " | " << candidate.index << " : ";
        for ( int voterIdx : candidate.votersSet ) {
            out << voterIdx << ", ";
        }
        out << " | ";
        return out;
    }
};

int main( int argc, char ** argv ) {

    //
    // We will have votersVec and candidatesVec
    //
    // vector< deque< int > > votersVec contains first, second, third, etc. choice of voters
    //
    // vector< deque< int > > candidatesVec contains the candidates and id of their voters
    // candidatesVec should be sorted by size() of deque< int >()
    //

    int electionCount = 0;
    while ( true ) {
        int C = 0;
        int N = 0;

        cin >> C >> N;

        if ( C == 0 && N == 0 ) break;

        vector< deque< int > > votersVec( N, deque< int >() );

        // candidatesVec should be sorted by size of deque< int >
        //
        // If the size is updated, we can remove the candidate, and re-insert again
        // with the new size.
        //
        // We will also have to adjust the pointer in candidatesVec
        vector< Candidate > candidatesVec( C );

        for ( int c = 0; c < C; c++ ) {
            candidatesVec[ c ].index = c;
        }

        int badBallotsCount = 0;
        for ( int n = 0; n < N; n++ ) {
            unordered_set< int > votedSet;
            bool skipBallot = false;

            for ( int c = 0; c < C; c++ ) {
                int candidateId = 0;
                cin >> candidateId;

                if ( ! skipBallot && ( candidateId > C || votedSet.find( candidateId - 1 ) != votedSet.end() ) ) {
                    // This candidate is either out of range or already voted.
                    // This is a bad ballot
                    skipBallot = true;

                    // Remove this voter from all candidates in votedSet and
                    // also from candidateId - 1
                    if ( candidateId <= C ) {
                        candidatesVec[ candidateId - 1 ].votersSet.erase( n );
                    }
                    for ( int canId : votedSet ) {
                        candidatesVec[ canId ].votersSet.erase( n );
                    }

                    // Clear out this voter's deque
                    votersVec[ n ].clear();

                    // Clear out votedSet
                    votedSet.clear();
                }

                if ( ! skipBallot ) {
                    if ( c == 0 ) {
                        candidatesVec[ candidateId - 1 ].votersSet.insert( n );
                    }
                    votersVec[ n ].push_back( candidateId - 1 );
                    votedSet.insert( candidateId - 1 );
                }

            }

            if ( skipBallot ) {
                // Add bad ballots
                ++badBallotsCount;
            }
        }

        // Here we should have all correct data. Start calculating now
        //
        // First loop through candidatesVec
        //
        // Check amount of voters each candidate has, and see if they occupied
        // majority. Save the max & min.
        //
        // If the max is majority, print out winner
        //
        // If the max == the min, print out all candidates as tied
        //
        // If max is not majority
        //   - Get the candidates with min votes ( candidatesVec[ min ] )
        //   - Get the list of all voters that voted this candidates ( candidatesVec[ min ].votersDeque )
        //   - For the first voter of votersDeque, 
        //   - Remove the first voter of votersDeque ( votersDeque.pop_front() )
        //
        cout << "Election #" << electionCount + 1 << endl;
        if ( badBallotsCount > 0 ) {
            cout << "   " << badBallotsCount << " bad ballot(s)" << endl;
        }

        while ( true ) {
            int minCandidateIdx = -1;
            int maxCandidateIdx = -1;

            for ( int i = 0; i < candidatesVec.size(); i++ ) {
                if ( ! candidatesVec[ i ].votersSet.empty() ) {
                    if ( minCandidateIdx == -1 || candidatesVec[ i ] < candidatesVec[ minCandidateIdx ] ) {
                        minCandidateIdx = i;
                    }

                    if ( maxCandidateIdx == -1 || candidatesVec[ maxCandidateIdx ] < candidatesVec[ i ] ) {
                        maxCandidateIdx = i;
                    }
                }
            }

            if ( ( double )candidatesVec[ maxCandidateIdx ].votersSet.size() / ( double )( N - badBallotsCount ) > 0.5 ) {
                cout << "   Candidate " << maxCandidateIdx + 1 << " is elected." << endl;
                break;
            } else if ( candidatesVec[ maxCandidateIdx ] == candidatesVec[ minCandidateIdx ] ) {
                cout << "   The following candidates are tied: ";
                int writtenCount = 0;
                for ( int i = 0; i < candidatesVec.size(); i++ ) {
                    if ( ! candidatesVec[ i ].votersSet.empty() ) {
                        if ( writtenCount > 0 ) {
                            cout << " ";
                        }
                        cout << i + 1;
                        ++writtenCount;
                    }
                }
                cout << endl;
                break;
            } else {
                // If max is not majority
                //   - Get the candidates with min votes ( candidatesVec[ min ] )
                //   - Get the votersSet of this minCandidate
                //   - Go through votersSet, remove the first candidate in the deque< int > of each votersSet if the deque< int > is not empty()
                //   - minCandidate.votersSet.clear();
                unordered_set< int > tmpVotersSet = candidatesVec[ minCandidateIdx ].votersSet;
                for ( int voterIdx : tmpVotersSet ) {
                    candidatesVec[ votersVec[ voterIdx ].front() ].votersSet.erase( voterIdx );
                    votersVec[ voterIdx ].pop_front();
                    candidatesVec[ votersVec[ voterIdx ].front() ].votersSet.insert( voterIdx );
                }
            }
        }
        ++electionCount;
    }

    return 0;
}
