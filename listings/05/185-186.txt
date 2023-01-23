template<class T, size_t N = 100> class Stack {
  T data[N];  // Фиксированная емкость N
  size_t count;
public:
  void push(const T& t);
  // И т. д.
};