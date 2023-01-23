{                                                    \
   class Error_NarrowingConversion{};                \
   sizeof(StaticCheck<sizeof(void*) <= sizeof(char)> \
           (Error_NarrowingConversion()));           \
}