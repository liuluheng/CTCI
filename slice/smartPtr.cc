#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class SmartPtr {
 public:
  explicit SmartPtr(T *p = nullptr) 
      : count_(new size_t(1)), obj_ptr_(p) { }

  ~SmartPtr() {
    dispose();
  }

  SmartPtr(const SmartPtr<T> &other) 
    :count_(other.count_),
    obj_ptr_(other.obj_ptr_)
    { ++*count_; }

  SmartPtr<T>& operator=(const SmartPtr<T> &rhs) {
    ++(*rhs.count_); // in case self copy
    dispose();
    count_ = rhs.count_;
    obj_ptr_ = rhs.obj_ptr_;

    return *this;
  }

  T& operator*() const { return *obj_ptr_; }
  T* operator->() const { return obj_ptr_; }
  size_t count() const { return *count_; }
  T* get() const { return obj_ptr_; }
  explicit operator bool() { return obj_ptr_ != nullptr; }

  void swap(SmartPtr<T> &other) {
    std::swap(obj_ptr_, other.obj_ptr_);
    // TRUTH is other.get() return an rvalue, rvalue cannot be bind
    // to non-const reference
    // if you write :
    //    T *tmp = other.get();
    //    std::swap(obj_ptr_, tmp);
    // this get passed
    //
    // std::swap(obj_ptr_, other.get()); // no matching swap!!! 
    std::swap(count_, other.count_);
  }

  void reset(T *ptr = nullptr) {
    dispose();
    obj_ptr_ = ptr;
    count_ = new size_t(1);
  }

  bool unique() { return *count_ == 1; }

 private:
  void dispose() {
    if (--*count_ == 0) {
      delete count_;
      delete obj_ptr_;
    }
  }

  size_t *count_;
  T *obj_ptr_;
};

int main()
{
  cout << "TEST SMARTPTR" << endl;

  SmartPtr<int> sptr, sptr2;
  assert(sptr.unique());
  
  sptr.swap(sptr2);
  assert(!sptr);

  SmartPtr<int> sptr3(new int(2));
  cout << "TEST SMARTPTR operator=()" << endl;
  sptr = sptr3;
  assert(sptr);
  assert(!sptr.unique());
  assert(sptr3);

  cout << "TEST SMARTPTR reset" << endl;
  sptr3.reset();
  assert(sptr);
  assert(sptr.unique());

  cout << "TEST SMARTPTR copy constructor" << endl;
  SmartPtr<int> sptr4(sptr3);
  assert(!sptr4);
  assert(!sptr4.unique());
  assert(sptr4.count() == 2);

  return 0;
}
