
# dt.h

## Description:

DEFER/TRY/END Statement.

C++ header only library.

```cpp
#include <dt.h>
```

Author: Elijah Shadbolt

Date: 29 March 2020

Licence: Public Domain (CC0)

Country: New Zealand

## Usage:

```cpp
	DT_DEFER;
	{
		// This block always executes regardless of an exception thrown from the TRY block.
		// If this block throws an exception, this block's exception is propagated.
		// This block's exception takes precedence over the TRY block's exception.
	}
	DT_TRY;
	{
		// Even if this block throws an exception, the DEFER block is executed.
	}
	DT_END;
```

Note: The DEFER/TRY/END statement forms its own scope, so they can be nested.

```cpp
	DT_DEFER
		DT_DEFER
			// this executes third
		DT_TRY
			// this executes second
		DT_END;
	DT_TRY
		// this executes first
	DT_END;
```

Note: DT_END must be followed by a semicolon.
