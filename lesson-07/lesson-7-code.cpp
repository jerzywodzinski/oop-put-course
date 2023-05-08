#include <iostream>
#include <cmath>

class Logarithm {
 public:
  Logarithm(double base, double argument) {
    base_ = base;
    argument_ = argument;
  }

  double Calculate() const {
      if(base_ <= 0|| base_==1){
        throw std::invalid_argument("base must be greater then 0 and cant be 1");
      }
      if(argument_ <= 0){
        throw std::invalid_argument("Argument must be greater then 0");
    }
    return std::log(argument_) / std::log(base_);
  }

 private:
  double base_;
  double argument_;
};

int main(){
    try{
        Logarithm x(0,40);
        std::cout<<x.Calculate()<<std::endl;
    }catch(const std::invalid_argument& e){
        std::cerr <<"Invalid argument: " <<e.what() << std::endl;
        }
    return 0;
}
