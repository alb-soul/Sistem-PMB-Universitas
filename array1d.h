#include "xcept.h"
using namespace std;

template < class T >
class Array1D {

template < class U >
friend ostream & operator << (ostream & ,const Array1D < U > & x);

public:
	Array1D(int size = 0, int MaxStackSize = 10);
	Array1D(const Array1D < T > & v);
	~Array1D() {
		delete[] dataKTP;
	}
	T & operator[](int i) const;
	int Size() {
		return size;
	}
	Array1D < T > & operator = (const Array1D < T > & v);
	Array1D < T > operator + () const;
	Array1D < T > operator + (const Array1D < T > & v) const;
	Array1D < T > operator - () const;
	Array1D < T > operator - (const Array1D < T > & v) const;
	Array1D < T > operator * (const Array1D < T > & v) const;
	Array1D < T > & operator += (const T & x);
	Array1D < T > & ReSize(int sz);
  Array1D <T>& pop(T x);
  Array1D <T>& push(T x);
  Array1D <T>& enqueue(T x);
  T dequeue(T& x);
  bool IsFull() const {return top == MaxTop;}
  bool IsEmpty() const {return top == -1;}
  bool isFullQueue() {
    if (front == 0 && end == size-1) {
      return true;
    }
    if (front == end + 1) {
      return true;
    }
    return false;
  }
  bool isEmptyQueue() {
    return front==-1;  
  }
  void geserKiri();
  void cetakAntrian();
  T Top() const;

private:
	int size;
  int top;
  int MaxTop;
  int front;
  int end;
	T * dataKTP;
  T * element;
};

template < class T >
  Array1D < T > ::Array1D(int sz, int szst){
	if (sz < 0) throw BadInitializers();
	size = sz;
	dataKTP = new T[sz];
  element = new T[szst];
  MaxTop = szst - 1;
  top = -1;
  front = -1;
  end = -1;
}

template <class T>
Array1D<T> &Array1D<T>::enqueue(T x) {
  cout << "\n" << x << " masuk antrian\n";
  if (isFullQueue()) throw NoMem();
  else {
      if (end==-1) {
        front++;
        element[front] = x;
        top++;
        end++;
      }
      else {
        end = (end+1) % MaxTop;
        element[end] = x;
    }
  }
  return *this;
}

template <class T>
T Array1D<T>::dequeue(T& x) {
  if (isEmptyQueue()) throw OutOfBounds();
  x = element[front];
  if (front==end) {
    front = -1;
    end  = -1;
  }
  else {
    front = (front+1) % MaxTop;
  }
  return x;
}

template <class T>
void Array1D<T>::geserKiri() {
  for (int i=0;i<end+1;i++) {
    element[i] = element[i+1];
  }
}

template <class T>
void Array1D<T>::cetakAntrian() {
  cout << "Isi antrian : ";
  for (int i=front;i<=end;i++) {
    cout << element[i] << " - ";
  }
  cout << endl;
}

template <class T>
T Array1D<T>::Top() const {
	// Return top element.
   if (IsEmpty()) throw OutOfBounds(); // Top fails
   else return element[top];
}

template <class T>
Array1D<T> &Array1D<T>::push(T x)
{
	// Add x to stack.
   if (IsFull()) throw NoMem(); // add fails
   element[++top] = x;
    end++;
   return *this;
}


template <class T>
Array1D<T> &Array1D<T>::pop(T x){
	// Delete top element and put in x.
   if (IsEmpty()) throw OutOfBounds(); // delete fails
   x = element[top--];
   return *this;
}


template < class T >
  Array1D < T > ::Array1D(const Array1D < T > & v){
size = v.size;
dataKTP = new T[size]; // get space
for (int i = 0; i < size; i++) // copy dataKTPs
  dataKTP[i] = v.dataKTP[i];
}
template < class T >
  T & Array1D < T > ::operator[](int i) const {
    if (i < 0 || i >= size) 
      throw OutOfBounds();
    return dataKTP[i];
  }
template < class T >
  Array1D < T > & Array1D < T > ::operator = (const Array1D < T > & v) {
    if (this != & v) {
      size = v.size;
      delete[] dataKTP;
      dataKTP = new T[size];
      for (int i = 0; i < size; i++)
        dataKTP[i] = v.dataKTP[i];
    }
    return *this;
  }
template < class T >
  Array1D < T > Array1D < T > ::operator + (const Array1D < T > & v) const {
    if (size != v.size) 
    	throw SizeMismatch();
    Array1D < T > w(size);
    for (int i = 0; i < size; i++)
      w.dataKTP[i] = dataKTP[i] + v.dataKTP[i];
    return w;
  }
template < class T >
  Array1D < T > Array1D < T > ::operator - (const Array1D < T > & v) const {
    if (size != v.size) throw SizeMismatch();
    Array1D < T > w(size);
    for (int i = 0; i < size; i++)
      w.dataKTP[i] = dataKTP[i] - v.dataKTP[i];
    return w;
  }
template < class T >
  Array1D < T > Array1D < T > ::operator - () const {
    Array1D < T > w(size);
    for (int i = 0; i < size; i++)
      w.dataKTP[i] = -dataKTP[i];
    return w;
  }
template < class T >
  Array1D < T > Array1D < T > ::operator * (const Array1D < T > & v) const {
    if (size != v.size) throw SizeMismatch();
    Array1D < T > w(size);
    for (int i = 0; i < size; i++)
      w.dataKTP[i] = dataKTP[i] * v.dataKTP[i];
    return w;
  }
template < class T >
  Array1D < T > & Array1D < T > ::operator += (const T & x) {
    for (int i = 0; i < size; i++)
      dataKTP[i] += x;
    return *this;
  }
template < class T >
  ostream & operator << (ostream & out, const Array1D < T > & x) {
    for (int i = 0; i < x.size; i++)
      out << x.dataKTP[i] << " ";
    return out;
  }
template < class T >
  Array1D < T > & Array1D < T > ::ReSize(int sz) {
    if (sz < 0) throw BadInitializers();
    delete[] dataKTP;
    size = sz;
    dataKTP = new T[size];
    return *this;
  }