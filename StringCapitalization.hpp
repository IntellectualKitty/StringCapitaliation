//===============================================================================
// MIT License
//
// Copyright (c) 2020 IntellectualKitty
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//===============================================================================

// Pragma guard.
#pragma once

// Include standard C/C++ header(s).
#include <cctype>
#include <cstring>
#include <string>

// Namespace.
namespace std
{

// Capitalize the first word: "hit the sack" -> "Hit the sack".
string cap_first_string( const char* s )
{
    string result;
    if ( s )
    {
        size_t len = strlen( s );
        result.reserve( (string::size_type)len );

        bool capitalize = true;
        for ( size_t i = 0; i < len; i++ )
        {
            if ( capitalize && !isspace( s[i] ) )
            {
                if ( isalpha() )
                    result.push_back( (char)toupper( s[i] ) );
                else
                    result.push_back( s[i] );
                capitalize = false;
            }
            else
                result.push_back( s[i] );
        }
    }
    return result;
}

// Capitalize each word: "hit the sack" -> "Hit The Sack".
string cap_each_string( const char* s )
{
    string result;
    if ( s )
    {
        size_t len = strlen( s );
        result.reserve( (string::size_type)len );

        bool capitalize = true;
        for ( size_t i = 0; i < len; i++ )
        {
            if ( capitalize && !isspace( s[i] ) )
            {
                if ( isalpha( s[i] ) )
                    result.push_back( (char)toupper( s[i] ) );
                else
                    result.push_back( s[i] );
                capitalize = false;
            }
            else
            {
                result.push_back( s[i] );
                if ( isspace( s[i] ) )
                    capitalize = true;
            }
        }
    }
    return result;
}

// Capitalize each letter: "hit the sack" -> "HIT THE SACK".
string all_caps_string( const char* s )
{
    string result;
    if ( s )
    {
        size_t len = strlen( s );
        result.reserve( (string::size_type)len );

        for ( size_t i = 0; i < len; i++ )
        {
            if ( isalpha( s[i] ) )
                result.push_back( (char)toupper( s[i] ) );
            else
                result.push_back( s[i] );
        }
    }
    return result;
}

}
