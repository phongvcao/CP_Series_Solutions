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

class Candidate;

class Voter {
public:

    int index = -1;
    deque< int > candidatesIdDeque;

    Voter() {
        // not implemented
    }

    Voter( const Voter& other )
        : index( other.index ),
          candidatesIdDeque( other.candidatesIdDeque )
    {
        // not implemented
    }

    virtual ~Voter() {
        // not implemented
    }

};

class Candidate {
public:

    int index = -1;
    string name = "";
    unordered_set< int > votersIdSet;

    Candidate() {
        // not implemented
    }

    Candidate( const Candidate& other )
        : index( other.index ),
          votersIdSet( other.votersIdSet ),
          name( other.name )
    {
        // not implemented
    }

    virtual ~Candidate() {
        // not implemented
    }

};

struct cmpCandidatesByNumVotes {
    bool operator ()( const Candidate* c1, const Candidate* c2 ) const {
        if ( c1->votersIdSet.size() < c2->votersIdSet.size() ) {
            return true;
        } else if ( c1->votersIdSet.size() > c2->votersIdSet.size() ) {
            return false;
        } else {
            return c1->index < c2->index;
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
        int candidatesCount = 0;
        if ( getline( cin, line ) ) {
            stringstream ss( line );
            ss >> candidatesCount;
        }

        vector< Candidate > candidatesVec( candidatesCount );
        set< Candidate *, cmpCandidatesByNumVotes > candidatesSet;
        for ( int i = 0; i < candidatesCount; i++ ) {
            if ( getline( cin, line ) ) {
                candidatesVec[ i ].index = i;
                candidatesVec[ i ].name = line;
                candidatesSet.insert( &candidatesVec[ i ] );
            }
        }

        vector< Voter > votersVec;
        while ( getline( cin, line ) ) {
            if ( line.empty() ) break;

            stringstream ss( line );
            Voter voter;
            voter.index = votersVec.size();
            votersVec.push_back( voter );

            int candidateId;
            while ( ss >> candidateId ) {
                --candidateId;
                votersVec.back().candidatesIdDeque.push_back( candidateId );

                if ( votersVec.back().candidatesIdDeque.size() == 1 ) {
                    candidatesSet.erase( &candidatesVec[ candidateId ] );
                    candidatesVec[ candidateId ].votersIdSet.insert( voter.index );
                    candidatesSet.insert( &candidatesVec[ candidateId ] );
                }
            }
        }

        int emptyVotersCount = 0;
        unordered_set< int > removedCandidatesIdSet;
        unordered_set< int > toBeRemovedCandidatesIdSet;
        // Evaluate the information to get result
        while ( true ) {
            int maxVotersCount = ( * candidatesSet.rbegin() )->votersIdSet.size();
            int minVotersCount = ( * candidatesSet.begin() )->votersIdSet.size();
            
            if ( maxVotersCount * 2 > votersVec.size() - emptyVotersCount ) {
                // There is a candidate with majority
                cout << ( * candidatesSet.rbegin() )->name << endl;
                break;
            } else if ( maxVotersCount == minVotersCount ) {
                // All candidates are tied
                for ( const Candidate * canPtr : candidatesSet ) {
                    if ( canPtr->votersIdSet.size() == minVotersCount ) {
                        cout << canPtr->name << endl;
                    }
                }
                break;
            } else {
                // There is no candidate with majority
                // For all candidates with minVotersCount
                //   - We loop though all of their voters
                //     - We then pop_front() these voters' candidatesIdDeque
                //     - We get the new front() of candidatesIdDeque of these voters
                //       which is newCandidateId
                //     - We insert these voters's indexes into candidatesVec[ newCandidateId ]
                //       by first removing candidatesVec[ newCandidateId ] from
                //       candidatesSet, add voters' indexes, then re-insert
                //       candidatesVec[ candidateId ] into candidatesSet
                // Now we remove this candidate out of candidatesSet
                //
                set< Candidate *, cmpCandidatesByNumVotes > tmpCandidatesSet = candidatesSet;
                for ( set< Candidate *, cmpCandidatesByNumVotes >::iterator iter = tmpCandidatesSet.begin();
                        iter != tmpCandidatesSet.end(); ++iter ) {
                    if ( ( * iter )->votersIdSet.size() > minVotersCount ) break;

                    toBeRemovedCandidatesIdSet.insert( ( *iter )->index );
                }

                for ( int candidateIdx : toBeRemovedCandidatesIdSet ) {
                    for ( int voterIdx : candidatesVec[ candidateIdx ].votersIdSet ) {
                        // First we begin by popping the first candidate if 
                        // candidatesIdDeque is NOT empty().
                        //
                        // After that, we have a while ( true ) loop checking
                        // whether the current top-level candidate is already
                        // eliminated before.
                        // - If the candidatesIdDeque is empty(), break out of 
                        // the while ( true ) loop.
                        // - If it has already been eliminated, pop it out and
                        // continue the while ( true ) loop.
                        // - ElseIf it has not been eliminated, break out of 
                        // the while ( true ) loop
                        //

                        if ( ! votersVec[ voterIdx ].candidatesIdDeque.empty() ) {
                            votersVec[ voterIdx ].candidatesIdDeque.pop_front();
                        }

                        while ( true ) {
                            if ( votersVec[ voterIdx ].candidatesIdDeque.empty() ) {
                                ++emptyVotersCount;
                                break;
                            }

                            if ( removedCandidatesIdSet.find( votersVec[ voterIdx ].candidatesIdDeque.front() ) != removedCandidatesIdSet.end() ) {
                                votersVec[ voterIdx ].candidatesIdDeque.pop_front();
                                continue;
                            }

                            int newCandidateId = votersVec[ voterIdx ].candidatesIdDeque.front();
                            candidatesSet.erase( &candidatesVec[ newCandidateId ] );
                            candidatesVec[ newCandidateId ].votersIdSet.insert( voterIdx );
                            candidatesSet.insert( &candidatesVec[ newCandidateId ] );

                            if ( votersVec[ voterIdx ].candidatesIdDeque.empty() ) {
                                ++emptyVotersCount;
                            }

                            break;
                        }
                    }
                    candidatesSet.erase( &candidatesVec[ candidateIdx ] );
                    removedCandidatesIdSet.insert( candidateIdx );
                }
                toBeRemovedCandidatesIdSet.clear();
            }
        }

        if ( n < N - 1 ) {
            cout << endl;
        }

    }

    return 0;
}
