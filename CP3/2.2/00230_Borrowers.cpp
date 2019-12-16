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

class Book {
public:

    int index = -1;
    string title = "";
    string author = "";

    Book() {
        // not implemented
    }

    Book( const string& bookStr ) {
        pair< string, string > authorTitle = extractAuthorTitle( bookStr );
        author = authorTitle.first;
        title = authorTitle.second;
    }

    Book( const Book& other )
        : index( other.index ),
          title( other.title ),
          author( other.author )
    {
        // not implemented
    }

    virtual ~Book() {
        // not implemented
    }

    static pair< string, string > extractAuthorTitle( const string& bookStr ) {
        int secondDoubleQuoteIdx = 1;
        while ( bookStr[ secondDoubleQuoteIdx ] != '"' ) {
            ++secondDoubleQuoteIdx;
        }
        string titleStr = bookStr.substr( 0, secondDoubleQuoteIdx + 1 );
        string authorStr = bookStr.substr( secondDoubleQuoteIdx + 5 );
        return make_pair( authorStr, titleStr );
    }

    friend bool operator <( const Book& b1, const Book& b2 ) {
        if ( b1.author < b2.author ) {
            return true;
        } else if ( b1.author > b2.author ) {
            return false;
        } else {
            if ( b1.title < b2.title ) {
                return true;
            } else if ( b1.title > b2.title ) {
                return false;
            } else {
                return b1.index < b2.index;
            }
        }
    }

    static bool cmpByTitleAndAuthor( const Book& b1, const Book& b2 ) {
        if ( b1.title < b2.title ) {
            return true;
        } else if ( b1.title > b2.title ) {
            return false;
        } else {
            if ( b1.author < b2.author ) {
                return true;
            } else if ( b1.author > b2.author ) {
                return false;
            } else {
                return b1.index < b2.index;
            }
        }
    }
    
    static int binarySearch( const vector< Book >& valueVec, const Book& val ) {
        int low = 0;
        int high = valueVec.size() - 1;

        while ( low <= high ) {
            int mid = low + ( high - low ) / 2;
            if ( val < valueVec[ mid ] ) {
                high = mid - 1;
            } else if ( valueVec[ mid ] < val ) {
                low = mid + 1;
            } else {
                return mid;
            }
        }
        return low;
    }

    friend ostream& operator <<( ostream& out, const Book& book ) {
        out << " | " << book.title << " : " << book.author << " | ";
        return out;
    }

};

int main( int argc, char ** argv ) {

    string line = "";
    vector< Book > bookVec;
    unordered_map< string, string > titleToAuthorMap;
    int bookIndex = 0;
    while ( getline( cin, line ) ) {
        if ( line == "END" ) break;
        if ( line.empty() ) continue;
        Book book( line );
        book.index = bookIndex++;
        bookVec.push_back( book );
        if ( titleToAuthorMap.find( book.title ) == titleToAuthorMap.end() ) {
            titleToAuthorMap.insert( { book.title, book.author } );
        }
    }

    sort( bookVec.begin(), bookVec.end() );
    vector< bool > inStock( bookIndex, true );

    set< int > outputSet;
    while ( getline( cin, line ) ) {
        if ( line.empty() ) continue;
        if ( line == "END" ) break;

        if ( line == "SHELVE" ) {
            // Output the result
            for ( int index : outputSet ) {
                if ( index == 0 ) {
                    cout << "Put " << bookVec[ index ].title << " first" << endl;
                } else {
                    int bookBeforeIdx = index - 1;

                    while ( bookBeforeIdx >= 0 && ! inStock[ bookVec[ bookBeforeIdx ].index ] ) {
                        --bookBeforeIdx;
                    }

                    if ( bookBeforeIdx == -1 ) {
                        cout << "Put " << bookVec[ index ].title << " first" << endl;
                    } else {
                        cout << "Put " << bookVec[ index ].title << " after " << bookVec[ bookBeforeIdx ].title << endl;
                    }
                }
            }
            cout << "END" << endl;
            outputSet.clear();
        } else {
            int spaceIdx = line.find_first_of( ' ' );
            string cmd = "";
            string title = "";
            if ( spaceIdx != string::npos ) {
                cmd = line.substr( 0, spaceIdx );
                title = line.substr( spaceIdx + 1 );
            }
            string author = titleToAuthorMap[ title ];
            Book book;
            book.author = author;
            book.title = title;
            int foundIdx = Book::binarySearch( bookVec, book );

            if ( cmd == "RETURN" ) {
                inStock[ bookVec[ foundIdx ].index ] = true;
                outputSet.insert( foundIdx );
            } else if ( cmd == "BORROW" ) {
                inStock[ bookVec[ foundIdx ].index ] = false;
            }
        }
    }

    return 0;
}
