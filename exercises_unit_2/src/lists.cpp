#include <forward_list>
#include <iostream>
#include <list>

int main(int argc, char **argv) {

  std::list<std::string> laser_list{"range_max", "range_min", "angle_max",
                                    "angle_min"};

  // * added to dereference the non-iterable index of the list
  std::cout << "first value of list: " << *laser_list.begin() << std::endl;
  //   std::cout << "last value of list: " << *laser_list.end() << std::endl;
  std::cout << "third element from end of list: " << *next(laser_list.end(), -3)
            << std::endl; // laser_list.end() returns a segmentation error as it
                          // is the null pointer at the end

  std::forward_list<std::string> laser_forward_list{"range_max", "range_min",
                                                    "angle_max", "angle_min"};
  std::cout << "first value of forward list: " << *laser_forward_list.begin()
            << std::endl;

  // consider this for readability and execution
  auto test = laser_forward_list.begin();
  advance(test, 1);
  std::cout << "third element from end of list: " << *test << std::endl;

  return 0;
}