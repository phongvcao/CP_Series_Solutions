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

class Account {
public:

    int num = 0;
    string name = "";

    Account() {
        // not implemented
    }

    Account( const Account& other )
        : num( other.num ),
          name( other.name )
    {
        // not implemented
    }

    virtual ~Account() {
        // not implemented
    }

    friend bool operator <( const Account& a1, const Account& a2 ) {
        return a1.num < a2.num;
    }
};

class Transaction {
public:

    int num = 0;

    vector< pair< Account *, double > > amountVec;
    double balance = 0;

    Transaction() {
        // not implemented
    }

    Transaction( const Transaction& other )
        : num( other.num ),
          amountVec( other.amountVec ),
          balance( other.balance )
    {
        // not implemented
    }

    virtual ~Transaction() {
        // not implemented
    }

    bool isOutOfBalance() const {
        return balance != 0;
    }

    friend bool operator <( const Transaction& t1, const Transaction& t2 ) {
        return t1.num < t2.num;
    }

};

int main( int argc, char ** argv ) {

    string line = "";
    int tripleZeroCount = 0;
    map< int, Account > accountMap;
    map< int, Transaction > transactionMap;
    vector< int > transactionIdxVec;

    while ( getline( cin, line ) ) {
        string initialStr = line.substr( 0, 3 );
        if ( initialStr == "000" ) {
            ++tripleZeroCount;
            continue;
        }

        if ( tripleZeroCount == 0 ) {
            // We're reading account info
            int accountNum = atoi( initialStr.c_str() );
            if ( accountMap.find( accountNum ) != accountMap.end() ) {
                accountMap[ accountNum ].name = line.substr( 3 );
            } else {
                Account acc;
                acc.num = accountNum;
                acc.name = line.substr( 3 );
                accountMap.insert( { accountNum, acc } );
            }
        } else if ( tripleZeroCount == 1 ) {
            // We're reading transaction info
            stringstream ss( line );
            string infoPart = "";
            double amountPart = 0;
            ss >> infoPart >> amountPart;

            // Convert amountPart to double
            double amount = amountPart / ( double )100;
            int transactionNum = atoi( line.substr( 0, 3 ).c_str() );
            int accountNum = atoi( line.substr( 3, 6 ).c_str() );

            if ( transactionMap.find( transactionNum ) == transactionMap.end() ) {
                transactionIdxVec.push_back( transactionNum );
                Transaction transaction;
                transaction.num = transactionNum;
                transactionMap.insert( { transactionNum, transaction } );
            }

            Transaction * transactionPtr = &transactionMap[ transactionNum ];
            transactionPtr->amountVec.push_back( { &accountMap[ accountNum ], amount } );
            transactionPtr->balance += amount;
        } else {
            break;
        }
    }

    for ( int i = 0; i < transactionIdxVec.size(); i++ ) {
        Transaction * transPtr = &transactionMap[ transactionIdxVec[ i ] ];
        if ( transPtr->isOutOfBalance() ) {
            printf( "*** Transaction %03d is out of balance ***\n", transPtr->num );
            for ( int j = 0; j < transPtr->amountVec.size() ; j++ ) {
                printf( "%03d %-30s %10.2f\n", transPtr->amountVec[ j ].first->num,
                        transPtr->amountVec[ j ].first->name.c_str(),
                        transPtr->amountVec[ j ].second );
            }
            printf( "%03d %-30s %10.2f\n\n", 999, "Out of Balance", -1 * transPtr->balance );
        }
    }

    return 0;
}
