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

namespace Mirror {

    static const int REFLECTED_ROTATED_UNKNOWN = -1;
    static const int REFLECTED_WITHOUT_ROTATED = 0;
    static const int REFLECTED_ROTATED_90_DEG = 90;
    static const int REFLECTED_ROTATED_180_DEG = 180;
    static const int REFLECTED_ROTATED_270_DEG = 270;

    static bool isEqual( const vector< vector< char > >& orgPatternVec, const vector< vector< char > >& newPatternVec ) {
        for ( int i = 0; i < orgPatternVec.size(); i++ ) {
            for ( int j = 0; j < orgPatternVec[ i ].size(); j++ ) {
                if ( orgPatternVec[ i ][ j ] != newPatternVec[ i ][ j ] ) {
                    return false;
                }
            }
        }
        return true;
    }

    static vector< vector< char > > get90DegRotation( const vector< vector< char > >& patternVec  ) {
        vector< vector< char > > rvVec( patternVec.size(), vector< char >( patternVec[ 0 ].size() ) );

        for ( int i = 0; i < patternVec.size(); i++ ) {
            for ( int j = 0; j < patternVec[ i ].size(); j++ ) {
                rvVec[ i ][ j ] = patternVec[ patternVec.size() - 1 - j ][ i ];
            }
        }

        return rvVec;
    }

    static vector< vector< char > > get180DegRotation( const vector< vector< char > >& patternVec ) {
        vector< vector< char > > rvVec( patternVec.size(), vector< char >( patternVec[ 0 ].size() ) );

        for ( int i = 0; i < patternVec.size(); i++ ) {
            for ( int j = 0; j < patternVec[ i ].size(); j++ ) {
                rvVec[ i ][ j ] = patternVec[ patternVec.size() - 1 - i ][ patternVec[ i ].size() - 1 - j ];
            }
        }

        return rvVec;
    }

    static vector< vector< char > > get270DegRotation( const vector< vector< char > >& patternVec ) {
        vector< vector< char > > rvVec( patternVec.size(), vector< char >( patternVec[ 0 ].size() ) );

        for ( int i = 0; i < patternVec.size(); i++ ) {
            for ( int j = 0; j < patternVec[ i ].size(); j++ ) {
                rvVec[ i ][ j ] = patternVec[ j ][ patternVec.size() - 1 - i ];
            }
        }

        return rvVec;
    }

    static vector< vector< char > > getVerticalReflection( const vector< vector< char > >& patternVec ) {
        vector< vector< char > > rvVec( patternVec.size(), vector< char >( patternVec[ 0 ].size() ) );

        for ( int i = 0; i < patternVec.size(); i++ ) {
            for ( int j = 0; j < patternVec[ i ].size(); j++ ) {
                rvVec[ i ][ j ] = patternVec[ patternVec.size() - 1 - i ][ j ];
            }
        }

        return rvVec;
    }

    static int getCombinationType( const vector< vector< char > >& patternVec, const vector< vector< char > >& newPatternVec ) {
        vector< vector< char > > reflectedVec = getVerticalReflection( patternVec );
        if ( isEqual( newPatternVec, reflectedVec ) ) {
            return REFLECTED_WITHOUT_ROTATED;
        }

        if ( isEqual( newPatternVec, get90DegRotation( reflectedVec ) ) ) {
            return REFLECTED_ROTATED_90_DEG;
        }

        if ( isEqual( newPatternVec, get180DegRotation( reflectedVec ) ) ) {
            return REFLECTED_ROTATED_180_DEG;
        }

        if ( isEqual( newPatternVec, get270DegRotation( reflectedVec ) ) ) {
            return REFLECTED_ROTATED_270_DEG;
        }

        return REFLECTED_ROTATED_UNKNOWN;
    }

}

int main( int argc, char ** argv ) {

    int patternCount = 0;
    while ( true ) {
        int N = 0;
        cin >> N;

        if ( N == 0 ) break;

        vector< vector< char > > orgPatternVec( N, vector< char >( N, '.' ) );
        vector< vector< char > > newPatternVec( N, vector< char >( N, '.' ) );

        for ( int n = 0; n < N; n++ ) {
            string orgStr = "";
            string newStr = "";

            cin >> orgStr >> newStr;

            for ( int i = 0; i < orgStr.size(); i++ ) {
                orgPatternVec[ n ][ i ] = orgStr[ i ];
            }

            for ( int i = 0; i < newStr.size(); i++ ) {
                newPatternVec[ n ][ i ] = newStr[ i ];
            }
        }

        cout << "Pattern " << patternCount + 1 << " was ";
        if ( Mirror::isEqual( orgPatternVec, newPatternVec ) ) {
            cout << "preserved." << endl;
        } else if ( Mirror::isEqual( Mirror::get90DegRotation( orgPatternVec ), newPatternVec ) ) {
            cout << "rotated 90 degrees." << endl;
        } else if ( Mirror::isEqual( Mirror::get180DegRotation( orgPatternVec ), newPatternVec ) ) {
            cout << "rotated 180 degrees." << endl;
        } else if ( Mirror::isEqual( Mirror::get270DegRotation( orgPatternVec ), newPatternVec ) ) {
            cout << "rotated 270 degrees." << endl;
        } else {
            int combinationType = Mirror::getCombinationType( orgPatternVec, newPatternVec );
            switch ( combinationType ) {
                case Mirror::REFLECTED_WITHOUT_ROTATED:
                {
                    cout << "reflected vertically." << endl;
                    break;
                }
                
                case Mirror::REFLECTED_ROTATED_90_DEG:
                {
                    cout << "reflected vertically and rotated 90 degrees." << endl;
                    break;
                }

                case Mirror::REFLECTED_ROTATED_180_DEG:
                {
                    cout << "reflected vertically and rotated 180 degrees." << endl;
                    break;
                }

                case Mirror::REFLECTED_ROTATED_270_DEG:
                {
                    cout << "reflected vertically and rotated 270 degrees." << endl;
                    break;
                }

                case Mirror::REFLECTED_ROTATED_UNKNOWN:
                {
                    cout << "improperly transformed." << endl;
                    break;
                }

                default:
                {
                    break;
                }
            }
        }
        ++patternCount;
    }

    return 0;
}
