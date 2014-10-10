#include <iostream>
#include <queue>
using namespace std;

class Animal {
 public:
  virtual ~Animal() { }

  void setorder(int order) {
    order_ = order;
  }
  int getorder() {
    return order_;
  }
  bool isOlderThan(Animal &a) {
    return order_ < a.getorder();
  }

  string name_;
 private:
  int order_ = 0;
};

class Dog : public Animal {
  Dog() {
    name_ = "Dog";
  }
};

class Cat : public Animal {
  Cat() {
    name_ = "Cat";
  }
};

class AnimalQueue {
 public:
  void enqueue(Animal &a) {
    a.setorder(order_);
    order_++;

    if (a.name_ == "Dog")
      dogs_.push(dynamic_cast<Dog &>(a));
    else if (a.name_ == "Cat")
      cats_.push(dynamic_cast<Cat &>(a));
  }

  Dog dequeDogs() {
    Dog dog = dogs_.front();
    dogs_.pop();
    return dog;
  }

  Cat dequeCats() {
    Cat cat = cats_.front();
    cats_.pop();
    return cat;
  }

  Animal dequeueAny() {
    if (dogs_.empty()) {
      return dequeCats();
    } else if (cats_.empty()) {
      return dequeDogs();
    }

    Dog dog = dogs_.front();
    Cat cat = cats_.front();
    if (dog.isOlderThan(cat)) {
      return dequeDogs();
    } else {
      return dequeCats();
    }
  }


 private:
  int order_ = 0;
  queue<Dog> dogs_;
  queue<Cat> cats_;
};

int main()
{
}
