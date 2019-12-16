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

class Title {
public:

    string readValue = "";
    int readIndex = -1;
    
    string keyword = "";
    int keywordIndex = -1;

    Title() {
        // not implemented
    }

    Title( const Title& other )
        : readValue( other.readValue ),
          readIndex( other.readIndex ),
          keyword( other.keyword ),
          keywordIndex( other.keywordIndex )
    {
        // not implemented
    }

    virtual ~Title() {
        // not implemented
    }

    static vector< pair< string, int > >
        getKeywordsWithIndexes( string readValue,
                                const unordered_set< string >& wordsToIgnoreSet ) {
        int readValueIndex = 0;
        vector< pair< string, int > > rvVec;
        unordered_set< string > foundWordsSet;
        stringstream ss( readValue );
        string word = "";
        while ( ss >> word ) {
            if ( wordsToIgnoreSet.find( word ) == wordsToIgnoreSet.end()
                    && foundWordsSet.find( word ) == foundWordsSet.end() ) {
                foundWordsSet.insert( word );

                size_t foundIndex = readValue.find( word );
                while ( foundIndex != string::npos ) {
                    if ( ( foundIndex > 0 && ! isspace( readValue[ foundIndex - 1 ] ) ) || ( foundIndex + word.size() < readValue.size() && ! isspace( readValue[ foundIndex + word.size() ] ) ) ) {
                        foundIndex = readValue.find( word, foundIndex + word.size() );
                        continue;
                    }
                    rvVec.push_back( make_pair( word, foundIndex ) );
                    foundIndex = readValue.find( word, foundIndex + word.size() );
                }
            }
        }
        return rvVec;
    }

    friend bool operator <( const Title& t1, const Title& t2 ) {
        // Titles are compared by:
        //   - The keyword
        //   - The read index of the title
        //   - The index of the keyword ( if the readIndex of the title is the same ),
        //     which means in the same title, the index of the keyword is compared.
        if ( t1.keyword < t2.keyword ) {
            return true;
        } else if ( t1.keyword > t2.keyword ) {
            return false;
        } else {
            if ( t1.readIndex < t2.readIndex ) {
                return true;
            } else if ( t1.readIndex > t2.readIndex ) {
                return false;
            } else {
                return t1.keywordIndex < t2.keywordIndex;
            }
        }
    }

    friend ostream& operator <<( ostream& out, const Title& title ) {
        for ( int i = 0; i < title.readValue.size(); i++ ) {
            if ( i >= title.keywordIndex && i < title.keywordIndex + title.keyword.size() ) {
                out << ( char )toupper( title.readValue[ i ] );
            } else {
                out << title.readValue[ i ];
            }
        }

        return out;
    }
};

int main( int argc, char ** argv ) {

    string line = "";

    // Read words to ignore
    unordered_set< string > wordsToIgnoreSet;
    while ( getline( cin, line ) ) {
        if ( line == "::" ) break;

        string word = "";
        stringstream ss( line );
        ss >> word;

        wordsToIgnoreSet.insert( word );
    }

    // Read titles
    vector< Title > titlesSet;
    int readIndex = 0;
    while ( getline( cin, line ) ) {
        for ( int i = 0; i < line.size(); i++ ) {
            if ( isupper( line[ i ] ) ) {
                line[ i ] = tolower( line[ i ] );
            }
        }

        vector< pair< string, int > > keywordsWithIndexesVec = Title::getKeywordsWithIndexes( line, wordsToIgnoreSet );

        for ( int i = 0; i < keywordsWithIndexesVec.size(); i++ ) {
            Title title;
            title.readValue = line;
            title.readIndex = readIndex;
            title.keyword = keywordsWithIndexesVec[ i ].first;
            title.keywordIndex = keywordsWithIndexesVec[ i ].second;
            titlesSet.push_back( title );
        }

        ++readIndex;
    }

    sort( titlesSet.begin(), titlesSet.end() );

    for ( const Title& title : titlesSet ) {
        cout << title << endl;
    }

    return 0;
}
