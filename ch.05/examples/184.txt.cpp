template<class T, size_t N>
class Stack {
  T data[N];  // ������������� ������� N
  size_t count;
public:
  void push(const T& t);
  // Ƞ�.��.
};