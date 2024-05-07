#include <iostream>

class Box {
private:
      double length;
      double height;
public:
      double getArea(){return length * height;}
      Box(){};
      Box(int a, int b): length(a), height(b){};
      Box operator+(const Box& b) {
         Box box;
         box.length = this->length + b.length;
         box.height = this->height + b.height;
         return box;
      }
};

int main() {
   Box Box1(2, 3);
   Box Box2(4, 7);
   Box Box3;
   double volume = 0.0;

   volume = Box1.getArea();
   std::cout << "Volume of Box1 : " << volume << std::endl;
   volume = Box2.getArea();
   std::cout << "Volume of Box2 : " << volume << std::endl;

   Box3 = Box1 + Box2;
   volume = Box3.getArea();
   std::cout << "Volume of Box3 : " << volume << std::endl;
}



class Canon {
private:
    std::string Name;
public:
    Canon(std::string str) : Name(str){};
    std::string getName() const;
    Canon &operator=( Canon const & rhs );
};

Canon &Canon::operator=( Canon const & rhs )
{
	this->Name = rhs.getName();
	return *this;
}

int main(){
    Canon a("Canon");
    Canon b("Nikon");
    std::cout << a.getName() << std::endl;
    std::cout << b.getName() << std::endl;
    a = b;
    std::cout << a.getName() << std::endl;
    return 0;
}