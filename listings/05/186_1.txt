template<class T = int, size_t N = 100>  // Значения по умолчанию
class Stack {                            // у обоих параметров
  T data[N];  // Фиксированная емкость N
  size_t count;
public:
  void push(const T& t);
  // И т. д.
};

Stack<> myStack;  // То же, что Stack<int,100>