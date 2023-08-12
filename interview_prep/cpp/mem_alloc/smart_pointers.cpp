#include <iostream>
#include <memory>

class Motor {
  public:
    int pin_1, pin_2, pin_pwm; std::string note;
    Motor(int p1, int p2, int pwm, std::string note): pin_1(p1), pin_2(p2), pin_pwm(pwm), note(note){
      std::cout << "created from " << note << std::endl;
    }

    ~Motor() {
      std::cout << "destroyed from " << note << std::endl;
    }
};

// unique pointers: when out of scope it will gets deleted!

// shared pointers: uses reference counting, keeps track of how many references has to the pointer, when 0 gets deleted!
// when it is created in an scope, it's a reference, when it's coppied to another shared ptr, it's another reference.
// when the execution get's out of the first scope which is the first shared pointer is created, the first reference dies.
// but since there's one more reference available to the pointer, the memory will not be freed.
// when that reference is also deleted, memory will be freed.

// shared pointers can be coppied to weak pointers but it does not increase the ref count!

int main(){

  {
    std::shared_ptr<Motor> mp_arr[4];

    for (int i=0; i < 4; i++){
      std::unique_ptr<Motor> m_u = std::unique_ptr<Motor>( new Motor(2+i, 6+i, 10+i, "unique") );
      std::cout << " unique : "<< m_u->pin_1 << "," << m_u->pin_2 << std::endl;
    }

    for (int i=0; i < 4; i++){
      mp_arr[i] = std::shared_ptr<Motor>( new Motor(2+i, 6+i, 10+i, "shared") );
    }    

    for (int i=0; i < 4; i++){
      std::cout << " motor   "<< i << " : ";
      std::cout << " shared: "<< mp_arr[i]->pin_1 << "," << mp_arr[i]->pin_2;
      std::cout << std::endl;
    }
  }
  std::cout << "shared pointer array is now freed" << std::endl;

  return 0;
}
