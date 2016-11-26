#pragma once

#define SafeDeleteSetNull(x) { delete x; x = nullptr; }
#define SizeofArray(a) (sizeof(a)/sizeof(a[0]))

