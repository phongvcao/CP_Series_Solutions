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

namespace Blood {
    //
    // We will have an unordered_map< string, vector< string > > of BLOOD_TYPES_TO_COMBINATIONS
    // We will have an unordered_map< string, string > of COMBINATIONS_TO_BLOOD_TYPES
    // We will have an unordered_map< char, vector< string > > of ALLELES_TO_COMBINATIONS
    //
    //
    //
    // I. First we determine the BloodType
    //
    // We will have 2 cases:
    // 1. Child missing : if child is missing, we generate permutation of 2 parents
    // COMBINATIONS and push that onto a set< string >
    //
    // 2. Parent missing : first we find COMBINATIONS of the child, and for each
    // char in the child COMBINATION that is found in the parent, we get the list
    // of possible other parent's COMBINATION that contains the other char from the
    // ALLELES_TO_COMBINATIONS map. We then pushes this value to an unordered_set< string >
    // which contains all COMBINATIONS possible for the question-marked entity.
    //
    //
    //
    // II. Now we determine the Rh factor ( + or - )
    //
    // We will have 2 cases:
    // 1. Child missing: We can just if-else the combination of Rh factor
    //
    // 2. Parent missing: We can just if-else the combination of Rh factor
    //

    unordered_map< string, vector< string > > ABO_TYPES_TO_COMBINATIONS = {
        {  "A", { "AA", "AO" } },
        { "AB", { "AB" } },
        {  "B", { "BB", "BO" } },
        {  "O", { "OO" } },
    };

    unordered_map< string, string > COMBINATIONS_TO_ABO_TYPES = {
        { "AA",  "A" },
        { "AB", "AB" },
        { "AO",  "A" },
        { "BB",  "B" },
        { "BO",  "B" },
        { "OO",  "O" },
    };

    unordered_map< char, vector< string > > ALLELES_TO_COMBINATIONS = {
        { 'A', { "AA", "AB", "AO" } },
        { 'B', { "AB", "BB", "BO" } },
        { 'O', { "AO", "BO", "OO" } },
    };

    static const string BLOOD_TYPE_UNKNOWN = "?";

    static const char RH_POSITIVE = '+';
    static const char RH_NEGATIVE = '-';

    unordered_map< char, vector< string > > ABO_RH_TO_COMBINATIONS = {
        { '+', { "++", "+-" } },
        { '-', { "--" } },
    };
    
    unordered_map< char, vector< string > > ABO_RH_TO_POSSIBLE_COMBINATIONS = {
        { '+', { "++", "+-" } },
        { '-', { "--", "+-" } },
    };

    unordered_map< string, string > COMBINATIONS_TO_ABO_RH = {
        { "++", "+" },
        { "+-", "+" },
        { "-+", "+" },
        { "--", "-" },
    };

    set< string, greater< string > > combineParentChild( const string& p1BloodType, const string& c1BloodType ) {
        string p1Abo = p1BloodType.substr( 0, p1BloodType.size() - 1 );
        string c1Abo = c1BloodType.substr( 0, c1BloodType.size() - 1 );
        char p1Rh = p1BloodType.back();
        char c1Rh = c1BloodType.back();

        vector< string > p1Combinations = Blood::ABO_TYPES_TO_COMBINATIONS[ p1Abo ];
        vector< string > c1Combinations = Blood::ABO_TYPES_TO_COMBINATIONS[ c1Abo ];

        vector< string > p1RhCombinations = Blood::ABO_RH_TO_COMBINATIONS[ p1Rh ];
        vector< string > c1RhCombinations = Blood::ABO_RH_TO_COMBINATIONS[ c1Rh ];

        // 2. Parent missing : first we find COMBINATIONS of the child, and for each
        // char in the child COMBINATION that is found in the parent, we get the list
        // of possible other parent's COMBINATION that contains the other char from the
        // ALLELES_TO_COMBINATIONS map. We then pushes this value to an unordered_set< string >
        // which contains all COMBINATIONS possible for the question-marked entity.
        set< string, greater< string > > aboCombSet;
        for ( int i = 0; i < c1Combinations.size(); i++ ) {
            string c1Comb = c1Combinations[ i ];
            for ( int j = 0; j < p1Combinations.size(); j++ ) {
                string p1Comb = p1Combinations[ j ];

                if ( c1Comb[ 0 ] == p1Comb[ 0 ] || c1Comb[ 0 ] == p1Comb[ 1 ] ) {
                    vector< string > allelesVec = ALLELES_TO_COMBINATIONS[ c1Comb[ 1 ] ];
                    for ( int k = 0; k < allelesVec.size(); k++ ) {
                        aboCombSet.insert( COMBINATIONS_TO_ABO_TYPES[ allelesVec[ k ] ] );
                    }
                }

                if ( c1Comb[ 1 ] == p1Comb[ 1 ] || c1Comb[ 1 ] == p1Comb[ 0 ] ) {
                    vector< string > allelesVec = ALLELES_TO_COMBINATIONS[ c1Comb[ 0 ] ];
                    for ( int k = 0; k < allelesVec.size(); k++ ) {
                        aboCombSet.insert( COMBINATIONS_TO_ABO_TYPES[ allelesVec[ k ] ] );
                    }
                }
            }
        }

        set< string, greater< string > > rhCombSet;
        for ( int i = 0; i < c1RhCombinations.size() ; i++ ) {
            string c1RhComb = c1RhCombinations[ i ];
            for ( int j = 0; j < p1RhCombinations.size(); j++ ) {
                string p1RhComb = p1RhCombinations[ j ];

                if ( c1RhComb[ 0 ] == p1RhComb[ 0 ] || c1RhComb[ 0 ] == p1RhComb[ 1 ] ) {
                    vector< string > rhsVec = ABO_RH_TO_POSSIBLE_COMBINATIONS[ c1RhComb[ 1 ] ];
                    for ( int k = 0; k < rhsVec.size(); k++ ) {
                        rhCombSet.insert( Blood::COMBINATIONS_TO_ABO_RH[ rhsVec[ k ] ] ); 
                    }
                }

                if ( c1RhComb[ 1 ] == p1RhComb[ 1 ] || c1RhComb[ 1 ] == p1RhComb[ 0 ] ) {
                    vector< string > rhsVec = ABO_RH_TO_POSSIBLE_COMBINATIONS[ c1RhComb[ 0 ] ];
                    for ( int k = 0; k < rhsVec.size(); k++ ) {
                        rhCombSet.insert( Blood::COMBINATIONS_TO_ABO_RH[ rhsVec[ k ] ] );
                    }
                }
            }
        }

        // Combine ABO & Rh combinations
        set< string, greater< string > > rvSet;
        for ( const string& aboStr : aboCombSet ) {
            for ( const string& rhStr : rhCombSet ) {
                rvSet.insert( aboStr + rhStr );
            }
        }

        return rvSet;
    }

    set< string, greater< string > > combineParents( const string& p1BloodType, const string& p2BloodType ) {
        string p1Abo = p1BloodType.substr( 0, p1BloodType.size() - 1 );
        string p2Abo = p2BloodType.substr( 0, p2BloodType.size() - 1 );
        char p1Rh = p1BloodType.back();
        char p2Rh = p2BloodType.back();

        vector< string > p1Combinations = Blood::ABO_TYPES_TO_COMBINATIONS[ p1Abo ];
        vector< string > p2Combinations = Blood::ABO_TYPES_TO_COMBINATIONS[ p2Abo ];

        vector< string > p1RhCombinations = Blood::ABO_RH_TO_COMBINATIONS[ p1Rh ];
        vector< string > p2RhCombinations = Blood::ABO_RH_TO_COMBINATIONS[ p2Rh ];


        // First figure out ABO combinations
        set< string, greater< string > > aboCombSet;
        for ( int i = 0; i < p1Combinations.size(); i++ ) {
            string p1Comb = p1Combinations[ i ];
            for ( int j = 0; j < p2Combinations.size(); j++ ) {
                string p2Comb = p2Combinations[ j ];
                
                for ( int k = 0; k < p1Comb.size(); k++ ) {
                    for ( int l = 0; l < p2Comb.size(); l++ ) {
                        string finalComb = "";
                        if ( p1Comb[ k ] < p2Comb[ l ] ) {
                            finalComb += p1Comb[ k ];
                            finalComb += p2Comb[ l ];
                        } else {
                            finalComb += p2Comb[ l ];
                            finalComb += p1Comb[ k ];
                        }
                        aboCombSet.insert( COMBINATIONS_TO_ABO_TYPES[ finalComb ] );
                    }
                }
            }
        }

        // Then figure out Rh combinations
        set< string, greater< string > > rhCombSet;
        for ( int i = 0; i < p1RhCombinations.size(); i++ ) {
            string p1RhComb = p1RhCombinations[ i ];
            for ( int j = 0; j < p2RhCombinations.size(); j++ ) {
                string p2RhComb = p2RhCombinations[ j ];
                
                for ( int k = 0; k < p1RhComb.size(); k++ ) {
                    for ( int l = 0; l < p2RhComb.size(); l++ ) {
                        string finalRhComb = "";
                        if ( p1RhComb[ k ] != p2RhComb[ l ] ) {
                            finalRhComb = "+";
                        } else {
                            finalRhComb += p1RhComb[ k ];
                        }
                        rhCombSet.insert( finalRhComb );
                    }
                }
            }
        }

        // Combine ABO & Rh combinations
        set< string, greater< string > > rvSet;
        for ( const string& aboStr : aboCombSet ) {
            for ( const string& rhStr : rhCombSet ) {
                rvSet.insert( aboStr + rhStr );
            }
        }

        return rvSet;
    }
}

int main( int argc, char ** argv ) {

    string line = "";
    int caseCount = 0;
    while ( getline( cin, line ) ) {
        if ( line == "E N D" ) break;
        if ( line.empty() ) continue;

        stringstream ss( line );
        vector< string > parentsVec( 2, "" );
        string child = "";

        ss >> parentsVec[ 0 ] >> parentsVec[ 1 ] >> child;

        cout << "Case " << caseCount + 1 << ": ";
        if ( child == Blood::BLOOD_TYPE_UNKNOWN ) {
            // 1. Child missing : if child is missing, we generate permutation of 2 parents
            // COMBINATIONS and push that onto a set< string >
            set< string, greater< string > > childBloodTypesSet = Blood::combineParents( parentsVec[ 0 ], parentsVec[ 1 ] );
            cout << parentsVec[ 0 ] << " " << parentsVec[ 1 ];

            if ( childBloodTypesSet.empty() ) {
                cout << " IMPOSSIBLE" << endl;
            } else {
                if ( childBloodTypesSet.size() > 1 ) {
                    cout << " {";
                } else {
                    cout << " ";
                }

                int childBloodIdx = 0;
                for ( const string& childBloodType : childBloodTypesSet ) {
                    if ( childBloodIdx > 0 ) {
                        cout << ", ";
                    }
                    cout << childBloodType;
                    ++childBloodIdx;
                }
                if ( childBloodTypesSet.size() > 1 ) {
                    cout << "}" << endl;
                } else {
                    cout << endl;
                }
            }
        } else {
            // 2. Parent missing
            if ( parentsVec[ 0 ] == Blood::BLOOD_TYPE_UNKNOWN ) {
                set< string, greater< string > > parentBloodTypesSet = Blood::combineParentChild( parentsVec[ 1 ], child );
                if ( parentBloodTypesSet.empty() ) {
                    cout << "IMPOSSIBLE " << parentsVec[ 1 ] << " " << child << endl;
                } else {
                    if ( parentBloodTypesSet.size() > 1 ) {
                        cout << "{";
                    }
                    int parentBloodIdx = 0;
                    for ( const string& parentBloodType : parentBloodTypesSet ) {
                        if ( parentBloodIdx > 0 ) {
                            cout << ", ";
                        }
                        cout << parentBloodType;
                        ++parentBloodIdx;
                    }
                    if ( parentBloodTypesSet.size() > 1 ) {
                        cout << "} ";
                    } else {
                        cout << " ";
                    }
                    cout << parentsVec[ 1 ] << " " << child << endl;
                }
            } else {
                set< string, greater< string > > parentBloodTypesSet = Blood::combineParentChild( parentsVec[ 0 ], child );
                if ( parentBloodTypesSet.empty() ) {
                    cout << parentsVec[ 0 ] << " IMPOSSIBLE " << child << endl;
                } else {
                    cout << parentsVec[ 0 ];
                    if ( parentBloodTypesSet.size() > 1 ) {
                        cout << " {";
                    } else {
                        cout << " ";
                    }
                    int parentBloodIdx = 0;
                    for ( const string& parentBloodType : parentBloodTypesSet ) {
                        if ( parentBloodIdx > 0 ) {
                            cout << ", ";
                        }
                        cout << parentBloodType;
                        ++parentBloodIdx;
                    }
                    if ( parentBloodTypesSet.size() > 1 ) {
                        cout << "} ";
                    } else {
                        cout << " ";
                    }
                    cout << child << endl;
                }
            }
        }
        ++caseCount;
    }

    return 0;
}
