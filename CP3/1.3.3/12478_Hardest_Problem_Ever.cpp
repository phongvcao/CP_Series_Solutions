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
#include <iterator>
#include <utility>
#include <algorithm>
#include <memory>
#include <cctype>
#include <stdexcept>
#include <limits>
#include <numeric>

//----< iostream >----------//
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

//----< cstdio >------------//
using std::printf;
using std::fprintf;
using std::sprintf;
using std::snprintf;

//----< iomanip >-----------//
using std::setprecision;
using std::setw;

//----< ios >---------------//
using std::hex;
using std::dec;
using std::oct;
using std::fixed;

//----< sstream >-----------//
using std::stringstream;
using std::ostringstream;
using std::istringstream;

//----< fstream >-----------//
using std::ofstream;
using std::ifstream;

//----< string >------------//
using std::getline;
using std::string;
using std::to_string;
using std::stoi;
using std::stol;

//----< cmath >-------------//
using std::sqrt;
using std::pow;
using std::log;             // log( <arg> )
using std::exp;             // e ^ <arg>
using std::abs;
using std::floor;           // Round down to nearest integer double
using std::ceil;            // Round up to nearest integer double
using std::trunc;           // Truncate the fractional part to get the integer part
using std::round;           // Round to nearest integer double

//----< cstdlib >-----------//
using std::rand;
using std::srand;

//----< ctime >-------------//
using std::time;

//----< functional >--------//
using std::hash;
using std::greater;         // lhs > rhs. Used for MinPQ
using std::less;            // lhs < rhs. Used for MaxPQ. Default for priority_queue<>
using std::less_equal;
using std::greater_equal;

//----< array >-------------//
using std::array;           // Fixed & Unordered Array

//----< vector >------------//
using std::vector;          // Resizable & Unordered Array

//----< map >---------------//
using std::map;             // Ordered Map (Red-Black Tree)

//----< unordered_map >-----//
using std::unordered_map;   // HashMap (SeparateChainingHashST)

//----< set >---------------//
using std::set;             // Ordered Set (Red-Black Tree)

//----< unordered_set >-----//
using std::unordered_set;   // HashSet (SeparateChainingHashST)

//----< list >--------------//
using std::list;            // Doubly-Linked List with size() ( O( 1 ) )

//----< forward_list >------//
using std::forward_list;    // Singly-Linked List without size() function ( so O( N ) if we need to get size() )

//----< deque >-------------//
using std::deque;           // Vector of fixed-size Vectors: 1 fixed-size vector for each end of the deque

//----< queue >-------------//
using std::queue;           // Non-Iterable & Use std::deque as underlying data structure
using std::priority_queue;  // MaxPQ (MaxHeap) & Non-Iterable.
//                          // => Pass std::greater<> as template params to create MinPQ (MinHeap)

//----< stack >-------------//
using std::stack;           // Non-Iterable & Use std::deque as underlying data structure

//----< iterator >----------//
using std::next;            // Return an advanced iter without changing original iter
using std::prev;            // Return an decremented iter without changing original iter
using std::distance;        // Calculate distance between 2 iterators

//----< utility >-----------//
using std::pair;
using std::make_pair;
using std::move;            // Move resources between objects - typically used with std::unique_ptr<T>

//----< algorithm >---------//
using std::fill;
using std::max;
using std::min;
using std::find;
using std::reverse;
using std::sort;
using std::remove;
using std::swap;

//----< memory >------------//
// using std::make_unique;
using std::unique_ptr;
using std::make_shared;
using std::shared_ptr;
using std::weak_ptr;

//----< cctype >------------//
using std::isalnum;
using std::isalpha;
using std::islower;
using std::isupper;
using std::isdigit;
using std::isspace;         // Check whether char is whitespace character (space, newline, tab, etc. )
using std::isblank;         // Check whether char is blank character ( space or tab )
using std::tolower;
using std::toupper;

//----< stdexcept >---------//
using std::runtime_error;
using std::invalid_argument;
using std::out_of_range;

//----< limits >------------//
using std::numeric_limits;

//----< numeric >-----------//
using std::iota;
// using std::gcd;
// using std::lcm;

//--------------------------//

class Name {
private:

    bool matching = false;
    int matchCount = 0;
    string name = "";
    vector< int > charCount;
    vector< int > orgCharCount;
    int occurences = 0;

public:

    Name( const Name& other )
        : matching( other.matching ),
          name( other.name ),
          occurences( other.occurences ),
          matchCount( other.name.size() )
    {
        charCount = other.charCount;
        orgCharCount = other.orgCharCount;
    }

    Name( string name )
        : name( name ),
          charCount( 26, 0 ),
          orgCharCount( 26, 0 ),
          matchCount( name.size() )
    {
        // Preprocess the name
        for ( int i = 0; i < name.size(); i++ ) {
            ++charCount[ name[ i ] - 'A' ];
            ++orgCharCount[ name[ i ] - 'A' ];
        }
    }

    virtual ~Name() {
        // not implemented
    }

    bool matchChar( char c ) {
        int idx = c - 'A';
        if ( matching ) {
            if ( charCount[ idx ] > 0 ) {
                --charCount[ idx ];
                --matchCount;
            } else {
                matching = false;
                matchCount = name.size();

                for ( int i = 0; i < orgCharCount.size(); i++ ) {
                    charCount[ i ] = orgCharCount[ i ];
                }
                return false;
            }
        } else {
            if ( charCount[ idx ] > 0 ) {
                matching = true;
                --charCount[ idx ];
                --matchCount;
            } else {
                matching = false;
                matchCount = name.size();
                for ( int i = 0; i < orgCharCount.size(); i++ ) {
                    charCount[ i ] = orgCharCount[ i ];
                }
                return false;
            }
        }

        if ( matchCount == 0 ) {
            ++occurences;
            return true;
        }
        return true;
    }

    vector< int > getCharCount() const {
        return charCount;
    }

    vector< int > getOrgCharCount() const {
        return orgCharCount;
    }

    int getOccurences() const {
        return occurences;
    }

    int getMatchCount() const {
        return matchCount;
    }

    string getName() const {
        return name;
    }

    int size() const {
        return name.size();
    }

};

int main( int argc, char ** argv ) {

    vector< vector< char > > gridVec = {
        { 'O', 'B', 'I', 'D', 'A', 'I', 'B', 'K', 'R' },
        { 'R', 'K', 'A', 'U', 'L', 'H', 'I', 'S', 'P' },
        { 'S', 'A', 'D', 'I', 'Y', 'A', 'N', 'N', 'O' },
        { 'H', 'E', 'I', 'S', 'A', 'W', 'H', 'I', 'A' },
        { 'I', 'R', 'A', 'K', 'I', 'B', 'U', 'L', 'S' },
        { 'M', 'F', 'B', 'I', 'N', 'T', 'R', 'N', 'O' },
        { 'U', 'T', 'O', 'Y', 'Z', 'I', 'F', 'A', 'H' },
        { 'L', 'E', 'B', 'S', 'Y', 'N', 'U', 'N', 'E' },
        { 'E', 'M', 'O', 'T', 'I', 'O', 'N', 'A', 'L' },
    };

    vector< string > names = {
        "RAKIBUL",
        "ANINDYA",
        "MOSHIUR",
        "SHIPLU",
        "KABIR",
        "SUNNY",
        "OBAIDA",
        "WASI",
    };

    vector< Name > namesVec;
    for ( int i = 0; i < names.size(); i++ ) {
        Name name( names[ i ] );
        namesVec.push_back( name );
    }

    string finalName = "";
    bool finalNameFound = false;

    for ( int i = 0; i < namesVec.size(); i++ ) {
        if ( finalNameFound ) break;
        // For each rows
        for ( int j = 0; j < gridVec.size(); j++ ) {
            if ( finalNameFound ) break;

            // Match horizontally
            for ( int k = 0; k < gridVec[ j ].size() - namesVec[ i ].size() + 1; k++ ) {
                if ( finalNameFound ) break;
                for ( int l = k; l < k + namesVec[ i ].size(); l++ ) {
                    if ( finalNameFound ) break;
                    if ( namesVec[ i ].matchChar( gridVec[ j ][ l ] ) ) {
                        if ( namesVec[ i ].getOccurences() == 2 ) {
                            finalName = namesVec[ i ].getName();
                            finalNameFound = true;
                        }
                    } else {
                        break;
                    }
                    
                }
            }
        }
        
        // For each cols
        for ( int j = 0; j < gridVec[ 0 ].size(); j++ ) {
            if ( finalNameFound ) break;

            // Match vertically
            for ( int k = 0; k < gridVec.size() - namesVec[ i ].size() + 1; k++ ) {
                if ( finalNameFound ) break;
                for ( int l = k; l < k + namesVec[ i ].size(); l++ ) {
                    if ( finalNameFound ) break;
                    if ( namesVec[ i ].matchChar( gridVec[ l ][ j ] ) ) {
                        if ( namesVec[ i ].getOccurences() == 2 ) {
                            finalName = namesVec[ i ].getName();
                            finalNameFound = true;
                        }
                    } else {
                        break;
                    }
                    
                }
            }
        }
    }

    cout << finalName << endl;

    return 0;
}
