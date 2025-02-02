template<>
  struct char_traits<wchar_t> {
  typedef wchar_t char_type;
  typedef wint_t int_type;
  typedef streamoff off_type;
  typedef wstreampos pos_type;
  typedef mbstate_t state_type;
  static void assign(char_type& c1, const char_type& c2);
  static bool eq(const char_type& c1, const char_type& c2);
  static bool lt(const char_type& c1, const char_type& c2);
  static int compare(const char_type* s1,
                     const char_type*  s2, size_t n);
  static size_t length(const char_type* s);
  static const char_type* find(const char_type* s, size_t n,
                               const char_type& a);
  static char_type* move(char_type* s1,
                         const char_type* s2, size_t n);
  static char_type* copy(char_type* s1,
                         const char_type* s2, size_t n);
  static char_type* assign(char_type* s, size_t n,
                           char_type a);
  static int_type not_eof(const int_type& c);
  static char_type to_char_type(const int_type& c);
  static int_type to_int_type(const char_type& c);
  static bool eq_int_type(const int_type& c1,
                          const int_type& c2);
  static int_type eof();
};