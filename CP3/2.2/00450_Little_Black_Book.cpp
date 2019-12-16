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

class Faculty {
public:

    string title = "";
    string firstName = "";
    string lastName = "";
    string address = "";
    string department = "";
    string homePhone = "";
    string workPhone = "";
    string campusBox = "";
    int readIndex = -1;

    Faculty() {
        // not implemented
    }

    Faculty( string facultyStr ) {
        // Parse facultyStr
        // Title,FirstName,LastName,HomeAddress,HomePhone,WorkPhone,CampusBox
        size_t commaPos = facultyStr.find_first_of( ',' );
        vector< string > infoVec( 7, "" );
        int infoVecIdx = 0;
        while ( commaPos != string::npos ) {
            infoVec[ infoVecIdx++ ] = facultyStr.substr( 0, commaPos );
            facultyStr = facultyStr.substr( commaPos + 1 );
            commaPos = facultyStr.find_first_of( ',' );
        }
        infoVec[ infoVecIdx++ ] = facultyStr;

        title = infoVec[ 0 ];
        firstName = infoVec[ 1 ];
        lastName = infoVec[ 2 ];
        address = infoVec[ 3 ];
        homePhone = infoVec[ 4 ];
        workPhone = infoVec[ 5 ];
        campusBox = infoVec[ 6 ];
    }

    Faculty( const Faculty& other )
        : title( other.title ),
          firstName( other.firstName ),
          lastName( other.lastName ),
          address( other.address ),
          department( other.department ),
          homePhone( other.homePhone ),
          workPhone( other.workPhone ),
          campusBox( other.campusBox ),
          readIndex( other.readIndex )
    {
        // not implemented
    }

    virtual ~Faculty() {
        // not implemented
    }

    friend bool operator <( const Faculty& f1, const Faculty& f2 ) {
        if ( f1.lastName < f2.lastName ) {
            return true;
        } else if ( f1.lastName > f2.lastName ) {
            return false;
        } else {
            return f1.readIndex < f2.readIndex;
        }
    }

    friend ostream& operator <<( ostream& out, const Faculty& faculty ) {
        out << faculty.title << " " << faculty.firstName << " " << faculty.lastName << endl;
        out << faculty.address << endl;
        out << "Department: " << faculty.department << endl;
        out << "Home Phone: " << faculty.homePhone << endl;
        out << "Work Phone: " << faculty.workPhone << endl;
        out << "Campus Box: " << faculty.campusBox << endl;
        return out;
    }

};

int main( int argc, char ** argv ) {

    // First sort by last name
    // Then sort by readIndex
    string line = "";
    int N = 0;
    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> N;
    }

    set< Faculty > facultySet;
    int readIndex = 0;
    for ( int i = 0; i < N; i++ ) {
        string department = "";
        if ( getline( cin, line ) ) {
            department = line;
        }

        while ( getline( cin, line ) ) {
            if ( line.empty() ) break;

            Faculty faculty( line );
            faculty.department = department;
            faculty.readIndex = readIndex++;
            facultySet.insert( faculty );
        }
    }

    for ( const Faculty& faculty : facultySet ) {
        for ( int i = 0; i < 40; i++ ) {
            cout << "-";
        }
        cout << endl;
        cout << faculty;
    }

    return 0;
}
