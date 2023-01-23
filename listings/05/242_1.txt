{                                                   \
   class Error_NarrowingConversion{};               \
   sizeof(StaticCheck<sizeof(void*) <= sizeof(int)> \
           (Error_NarrowingConversion()));          \
}