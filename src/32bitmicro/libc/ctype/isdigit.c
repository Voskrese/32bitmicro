/*
FUNCTION
<<isdigit>>---decimal digit predicate

INDEX
isdigit

ANSI_SYNOPSIS
#include <ctype.h>
int isdigit(int <[c]>);

TRAD_SYNOPSIS
#include <ctype.h>
int isdigit(<[c]>);

DESCRIPTION
<<isdigit>> is a macro which classifies ASCII integer values by table
lookup.  It is a predicate returning non-zero for decimal digits, and 0 for
other characters.  It is defined only when <<isascii>>(<[c]>) is true
or <[c]> is EOF.

You can use a compiled subroutine instead of the macro definition by
undefining the macro using `<<#undef isdigit>>'.

RETURNS
<<isdigit>> returns non-zero if <[c]> is an decimal digit (<<0>>--<<9>>).

PORTABILITY
<<isdigit>> is ANSI C.

No supporting OS subroutines are required.
*/

#include <ctype.h>

#if defined(PREFER_SIZE_OVER_SPEED)

#undef isdigit
int isdigit (int c)
{
	return((c>='0') && (c<='9'));
}

#endif
