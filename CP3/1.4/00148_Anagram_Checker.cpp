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

class DFS {
private:

    vector< bool > marked;

    // We'll have a vector< map< string, int > > that contains
    // the whole collection of words. Index of vector<> is the smallest
    // chars in word. First ele of map is the sorted word, second ele 
    // of map is index of wordsVeca.
    vector< multimap< string, int > > dictVec;

    // We'll have a vector< string > ( wordsVec ) that contains all
    // words read.
    vector< string > wordsVec;

    // Original phrase
    string orgPhrase = "";
    set< string > orgPhraseSet;

    // Final results of the current orgPhrase
    set< string > matchesSet;

    int binarySearch( const string& sortedStr, int low, int high, char c ) {
        if ( low > high ) return -1;

        int mid = low + ( high - low ) / 2;
        if ( c < sortedStr[ mid ] ) {
            return binarySearch( sortedStr, low, mid - 1, c );
        } else if ( c > sortedStr[ mid ] ) {
            return binarySearch( sortedStr, mid + 1, high, c );
        } else {
            return mid;
        }
        return -1;
    }

    void dfs( string phrase, int wordIndex, multiset< string > matchSet ) {
        // - Do a dfs of the dictVec ( vector< map< string, string > > )
        //
        // - As we traverse through the dictVec, we keep a vector<> of matches
        // and keep pushing into this vector<>
        //
        // - We also keep a bool marked[] vector that mapped to wordsVec above.
        // Whenever we visit a word in vector< map< string, int > >, we mark
        // marked.
        //
        // - Whenever a match is found, print it out. Then set marked[ v ] = false
        //
        // - As we backtrack each level of recursion that doesn't find any match,
        // we set marked[ w ] = false;
        //

        if ( orgPhraseSet.find( wordsVec[ wordIndex ] ) != orgPhraseSet.end() ) {
            return;
        }

        marked[ wordIndex ] = true;
        string newPhrase = phrase;
        
        for ( int i = 0; i < wordsVec[ wordIndex ].size(); i++ ) {
            int foundIndex = binarySearch( newPhrase, 0, newPhrase.size() - 1, wordsVec[ wordIndex ][ i ] );

            if ( foundIndex == -1 ) {
                // Mismatch chars
                marked[ wordIndex ] = false;
                return;
            } else {
                newPhrase.erase( foundIndex, 1 );
            }
        }

        // If we're here, wordsVec[ wordIndex ] must have matched against phrase
        matchSet.insert( wordsVec[ wordIndex ] );

        // We are here if all chars of wordsVec[ wordIndex ] matches phrase
        if ( newPhrase.empty() ) {
            // We found a perfect match
            // Let's print it out
            string output = "";
            int matchSetIdx = 0;
            for ( string matchedWord : matchSet ) {
                output += matchedWord;
                if ( matchSetIdx < matchSet.size() - 1 ) {
                    output += " ";
                }
                ++matchSetIdx;
            }
            output += "\n";
            matchesSet.insert( output );
        } else {
            // We need to keep looking
            char firstChar = newPhrase[ 0 ];
            for ( multimap< string, int >::const_iterator dictIter = dictVec[ firstChar - 'A' ].begin();
                    dictIter != dictVec[ firstChar - 'A' ].end(); ++dictIter ) {
                if ( ! marked[ dictIter->second ] ) {
                    dfs( newPhrase, dictIter->second, matchSet );
                }
            }
        }
        marked[ wordIndex ] = false;
    }

public:

    DFS()
        : dictVec( 26, multimap< string, int >() )
    {
        // not implemented
    }

    void addWord( string word ) {
        string orgWord = word;
        sort( word.begin(), word.end() );

        wordsVec.push_back( orgWord );
        dictVec[ word[ 0 ] - 'A' ].insert( { word, wordsVec.size() - 1 } );
        marked.push_back( false );
    }

    void searchPhrase( string phrase ) {
        orgPhrase = phrase;
        phrase = "";

        // Put orgPhrase into set
        stringstream ss( orgPhrase );
        string orgPhraseWord = "";
        orgPhraseSet.clear();
        while ( ss >> orgPhraseWord ) {
            orgPhraseSet.insert( orgPhraseWord );
        }

        // Remove all space from phrase
        for ( int i = 0; i < orgPhrase.size(); i++ ) {
            if ( ! isspace( orgPhrase[ i ] ) ) {
                phrase += orgPhrase[ i ];
            }
        }

        sort( phrase.begin(), phrase.end() );
        
        // Reset marked[] vector
        marked.resize( marked.size(), false );

        matchesSet.clear();

        // As we traverse through the dictVec, we keep a vector<> of matches
        // and keep pushing into this vector<>
        multiset< string > matchSet;
        char firstChar = phrase[ 0 ];
        for ( multimap< string, int >::const_iterator dictIter = dictVec[ firstChar - 'A' ].begin();
                dictIter != dictVec[ firstChar - 'A' ].end(); ++dictIter ) {
            dfs( phrase, dictIter->second, matchSet );
        }

        // int matchesSetIdx = 0;
        for ( const string& matchStr : matchesSet ) {
            cout << orgPhrase << " = " << matchStr;
        }
    }

    void reset() {
        wordsVec.clear();
        dictVec.resize( 26, multimap< string, int >() );
        marked.clear();
    }

    virtual ~DFS() {
        // not implemented
    }

};

int main( int argc, char ** argv ) {

    string line = "";
    int hashCount = 0;

    DFS dfs;

    while ( getline( cin, line ) ) {
        stringstream ss( line );

        if ( line.empty() ) continue;

        if ( line == "#" ) {
            ++hashCount;
            if ( hashCount == 2 ) {
                dfs.reset();
                hashCount = 0;
            }
            continue;
        }

        if ( hashCount == 0 ) {
            //
            // We're reading the words
            //
            // - Each word will be sorted
            //
            // - We'll have a vector< map< string, int > > that contains
            // the whole collection of words. Index of vector<> is the smallest
            // chars in word. First ele of map is the sorted word, second ele 
            // of map is index of wordsVeca.
            // - We'll have a vector< string > ( wordsVec ) that contains all
            // words read.
            //
            // - All lookups will be in the form of sorted words anyway
            //
            dfs.addWord( line );
        } else if ( hashCount == 1 ) {
            //
            // We're reading the phrases
            //
            // - Sort the phrase ???
            //
            // - Do a dfs of the dictVec ( vector< map< string, string > > )
            //
            // - As we traverse through the dictVec, we keep a vector<> of matches
            // and keep pushing into this vector<>
            //
            // - We also keep a bool marked[] vector that mapped to wordsVec above.
            // Whenever we visit a word in vector< map< string, int > >, we mark
            // marked.
            //
            // - Whenever a match is found, print it out. Then set marked[ v ] = false
            //
            // - As we backtrack each level of recursion that doesn't find any match,
            // we set marked[ w ] = false;
            //
            dfs.searchPhrase( line );
        } else {
            break;
        }
    }

    return 0;
}
