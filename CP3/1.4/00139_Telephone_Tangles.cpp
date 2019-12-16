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

class Code {
public:

    static const int CODE_LOCAL = 0;
    static const int CODE_NATIONAL = 1;
    static const int CODE_INTERNATIONAL = 2;
    static const int CODE_UNKNOWN = 3;

    int codeType = CODE_UNKNOWN;
    string areaCode = "";
    string name = "";
    int priceInCents = 0;
    double priceInDollars = 0;

    static int getCodeType( const string& numStr ) {
        if ( numStr[ 0 ] == '0' && numStr[ 1 ] == '0' ) {
            if ( numStr[ 2 ] != ' ' ) {
                return CODE_INTERNATIONAL;
            } else {
                return CODE_NATIONAL;
            }
        } else if ( numStr[ 0 ] == '0' ) {
            return CODE_NATIONAL;
        } else {
            return CODE_LOCAL;
        }
    }

    static int getCodeTypeWithSize( const string& numStr ) {
        if ( numStr[ 0 ] == '0' && numStr[ 1 ] == '0' ) {
            if ( numStr[ 2 ] != ' ' ) {
                return CODE_INTERNATIONAL;
            } else {
                return CODE_NATIONAL;
            }
        } else if ( numStr[ 0 ] == '0' ) {
            return CODE_NATIONAL;
        } else {
            return CODE_LOCAL;
        }
    }

    static int getMaxAreaCodeSize( int codeType ) {
        switch ( codeType ) {
            case CODE_NATIONAL:
            {
                return 5;
            }

            case CODE_INTERNATIONAL:
            {
                return 3;
            }

            case CODE_LOCAL:
            case CODE_UNKNOWN:
            {
                return 0;
            }

            default:
            {
                return 0;
            }
        }

        return 0;
    }

    Code() {
        // not implemented
    }

    Code( const string& codeStr )
        : codeType( getCodeType( codeStr ) )
    {
        stringstream ss( codeStr );

        ss >> this->areaCode;
        string nameNPrice = codeStr.substr( this->areaCode.size() );
        this->areaCode = this->areaCode.substr( codeType );
        
        size_t dollarSignIdx = nameNPrice.find( "$" );
        if ( dollarSignIdx != string::npos ) {
            this->priceInCents = atoi( nameNPrice.substr( dollarSignIdx + 1 ).c_str() );
            this->priceInDollars = ( double )this->priceInCents / 100.0;
        }

        this->name = nameNPrice.substr( 0, dollarSignIdx );
        int firstSpaceIdx = this->name.find_first_not_of( " " );
        int lastSpaceIdx = this->name.find_last_not_of( " " );

        if ( firstSpaceIdx != -1 && lastSpaceIdx != -1 ) {
            this->name = name.substr( firstSpaceIdx, lastSpaceIdx + 1 - firstSpaceIdx );
        }

    }

    Code( int codeType, const string& areaCode, const string& name,
          int priceInCents, double priceInDollars )
        : codeType( codeType ),
          areaCode( areaCode ),
          name( name ),
          priceInCents( priceInCents ),
          priceInDollars( priceInDollars )
    {
        // not implemented
    }

    Code( const Code& other )
        : codeType( other.codeType ),
          areaCode( other.areaCode ),
          name( other.name ),
          priceInCents( other.priceInCents ),
          priceInDollars( other.priceInDollars )
    {
        // not implemented
    }

    virtual ~Code() {
        // not implemented
    }

    friend bool operator <( const Code& c1, const Code& c2 ) {
        return c1.areaCode < c2.areaCode;
    }

    friend bool operator >( const Code& c1, const Code& c2 ) {
        return c1.areaCode > c2.areaCode;
    }

    friend bool operator ==( const Code& c1, const Code& c2 ) {
        return c1.areaCode == c2.areaCode;
    }

    friend bool operator !=( const Code& c1, const Code& c2 ) {
        return ! ( c1 == c2 );
    }

    friend ostream& operator <<( ostream& out, const Code& code ) {
        out << " | codeType : " << code.codeType
            << " ; areaCode : " << code.areaCode
            << " ; name : " << code.name
            << " ; priceInCents : " << code.priceInCents
            << " ; priceInDollars : " << code.priceInDollars << " | ";
        return out;
    }

};

class Number {
public:

    static int getNumberType( const string& numStr, bool ignoreIntl = false ) {
        int codeType = Code::getCodeType( numStr );

        if ( ignoreIntl && codeType == Code::CODE_INTERNATIONAL ) {
            codeType = Code::CODE_NATIONAL;
        }

        switch ( codeType ) {
            case Code::CODE_NATIONAL:
            {
                if ( numStr.size() < 6 || numStr.size() > 13 ) return Code::CODE_UNKNOWN;
                break;
            }

            case Code::CODE_INTERNATIONAL:
            {
                if ( numStr.size() < 7 || numStr.size() > 15 ) {
                    if ( numStr.size() >= 6 && numStr.size() <= 13 ) return Code::CODE_NATIONAL;
                    return Code::CODE_UNKNOWN;
                }
                break;
            }

            default:
            {
                return Code::CODE_LOCAL;
            }
        }

        return codeType;
    }

    Number() {
        // not implemented
    }

    Number( const Number& other ) {
        // not implemented
    }

    virtual ~Number() {
        // not implemented
    }

};

int main( int argc, char ** argv ) {

    // We will have a vector< set< Code > > of all codes
    //
    // For the numbers, we first identify the primitive numberType
    // Then we use this primitive type to extract:
    //   - areaCode
    // The areaCode will be extract as longest, and we'll pop_back() each char
    // & find the areaCode in the respective set< Code >. If none is found, 
    // then the area is unknown
    // If we can find the area code, we'll calculate & print out the result
    //

    string line = "";
    vector< set< Code > > codeSetVec( 4, set< Code >() );
    int stepCount = 0;

    while ( getline( cin, line ) ) {
        if ( line == "000000" ) {
            ++stepCount;
            continue;
        } else if ( line == "#" ) {
            break;
        }

        if ( stepCount == 0 ) {
            // We're reading in information for codeSetVec
            stringstream ss( line );
            string areaCode = "";
            ss >> areaCode;
            string nameNPrice = line.substr( areaCode.size() );
            
            size_t dollarSignIdx = nameNPrice.find( "$" );
            int priceInCents = 0;
            double priceInDollars = 0;

            if ( dollarSignIdx != string::npos ) {
                priceInCents = atoi( nameNPrice.substr( dollarSignIdx + 1 ).c_str() );
                priceInDollars = ( double )priceInCents / 100.0;
            }

            string name = nameNPrice.substr( 0, dollarSignIdx );
            int firstSpaceIdx = name.find_first_not_of( " " );
            int lastSpaceIdx = name.find_last_not_of( " " );

            if ( firstSpaceIdx != -1 && lastSpaceIdx != -1 ) {
                name = name.substr( firstSpaceIdx, lastSpaceIdx + 1 - firstSpaceIdx );
            }

            int codeType = Code::getCodeType( line );

            switch ( codeType ) {
                case Code::CODE_INTERNATIONAL:
                {
                    // This can be both INTERNATIONAL & NATIONAL
                    // CODE_INTERNATIONAL
                    if ( areaCode.size() >= 3 && areaCode.size() <= 5 ) {
                        codeType = Code::CODE_INTERNATIONAL;
                        string tempAreaCode = areaCode.substr( codeType );
                        Code code( codeType, tempAreaCode, name, priceInCents, priceInDollars );
                        codeSetVec[ code.codeType ].insert( code );
                    }

                    // CODE_NATIONAL
                    if ( areaCode.size() >= 2 && areaCode.size() <= 6 ) {
                        codeType = Code::CODE_NATIONAL;
                        string tempAreaCode = areaCode.substr( codeType );
                        Code code( codeType, tempAreaCode, name, priceInCents, priceInDollars );
                        codeSetVec[ code.codeType ].insert( code );
                    }
                    break;
                }

                case Code::CODE_NATIONAL:
                {
                    // This can only be NATIONAL
                    Code code( codeType, areaCode.substr( codeType ), name, priceInCents, priceInDollars );
                    codeSetVec[ code.codeType ].insert( code );
                    break;
                }

                default:
                {
                    // Local
                    break;
                }
            }

        } else if ( stepCount == 1 ) {
            // We're reading in numbers information
            stringstream ss( line );
            int dur = 0;
            string numStr = "";
            ss >> numStr;

            if ( line.size() == numStr.size() ) {
                getline( cin, line );
                ss.clear();
                ss.str( line );
                ss >> dur;
            } else {
                ss >> dur;
            }

            int numberType = Number::getNumberType( numStr );
            bool answerFound = false;

            switch ( numberType ) {
                case Code::CODE_LOCAL:
                {
                    printf( "%-16s%-20s%15s%5d%6.2f%7.2f\n",
                            numStr.c_str(),
                            "Local",
                            numStr.c_str(),
                            dur,
                            0.0,
                            0.0 );
                    answerFound = true;
                    break;
                }

                case Code::CODE_NATIONAL:
                case Code::CODE_INTERNATIONAL:
                {
                    // If we cannot find this national/international code,
                    // it's probably UNKNOWN
                    string areaCode = numStr.substr( numberType, Code::getMaxAreaCodeSize( numberType ) );
                    string trueNum = numStr.substr( numberType + Code::getMaxAreaCodeSize( numberType ) );

                    string tempAreaCode = "";
                    string tempTrueNum = areaCode + trueNum;
                    for ( int i = 0; i < areaCode.size(); i++ ) {
                        Code query;
                        tempAreaCode += areaCode[ i ];
                        tempTrueNum = tempTrueNum.substr( 1 );

                        query.areaCode = tempAreaCode;
                        set< Code >::iterator codeSetIter = codeSetVec[ numberType ].find( query );

                        if ( codeSetIter != codeSetVec[ numberType ].end() ) {
                            if ( ( tempTrueNum.size() < 4 || tempTrueNum.size() > 10 ) && ( numberType == Code::CODE_INTERNATIONAL ) ) {
                                continue;
                            }
                            if ( ( tempTrueNum.size() < 4 || tempTrueNum.size() > 7 ) && ( numberType == Code::CODE_NATIONAL ) ) {
                                continue;
                            }

                            printf( "%-16s%-20s%15s%5d%6.2f%7.2f\n",
                                    numStr.c_str(),
                                    codeSetIter->name.c_str(),
                                    tempTrueNum.c_str(),
                                    dur,
                                    ( double )codeSetIter->priceInCents / 100.0,
                                    ( double )dur * ( double )codeSetIter->priceInCents / 100.0 );
                            answerFound = true;
                            break;
                        }
                    }
                    break;
                }

                default:
                {
                    break;
                }
            }

            if ( ! answerFound ) {
                if ( numberType == Code::CODE_INTERNATIONAL ) {
                    numberType = Number::getNumberType( numStr, true );

                    if ( numberType == Code::CODE_NATIONAL ) {
                        // If we cannot find this international code,
                        // we should try national code
                        string areaCode = numStr.substr( numberType, Code::getMaxAreaCodeSize( numberType ) );
                        string trueNum = numStr.substr( numberType + Code::getMaxAreaCodeSize( numberType ) );

                        string tempAreaCode = "";
                        string tempTrueNum = areaCode + trueNum;
                        for ( int i = 0; i < areaCode.size(); i++ ) {
                            Code query;
                            tempAreaCode += areaCode[ i ];
                            tempTrueNum = tempTrueNum.substr( 1 );

                            query.areaCode = tempAreaCode;
                            set< Code >::iterator codeSetIter = codeSetVec[ numberType ].find( query );

                            if ( codeSetIter != codeSetVec[ numberType ].end() ) {
                                if ( ( tempTrueNum.size() < 4 || tempTrueNum.size() > 10 ) && ( numberType == Code::CODE_INTERNATIONAL ) ) {
                                    continue;
                                }
                                if ( ( tempTrueNum.size() < 4 || tempTrueNum.size() > 7 ) && ( numberType == Code::CODE_NATIONAL ) ) {
                                    continue;
                                }
                                printf( "%-16s%-20s%15s%5d%6.2f%7.2f\n",
                                        numStr.c_str(),
                                        codeSetIter->name.c_str(),
                                        tempTrueNum.c_str(),
                                        dur,
                                        ( double )codeSetIter->priceInCents / 100.0,
                                        ( double )dur * ( double )codeSetIter->priceInCents / 100.0 );
                                answerFound = true;
                                break;
                            }
                        }
                    }
                }
            }


            if ( ! answerFound ) {
                printf( "%-16s%-20s%15s%5d%6s%7.2f\n",
                        numStr.c_str(),
                        "Unknown",
                        "",
                        dur,
                        "",
                        -1.0 );
            }

        } else {
            break;
        }
    }

    return 0;
}
