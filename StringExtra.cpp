#include "StringExtra.h"
#include <string>
#include <vector>

using namespace std;

string std::toLowercase( string input )
    {
    for ( int i = 0; i < input.length( ); i++ )
        {
        input [ i ] = tolower( input [ i ] );
        }
    return input;
    }


