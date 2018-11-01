#include "Critter.hpp"

void Critter::incrementAge() {
  age += 1;
}

void Critter::setAge(int a) {
  age = a;
}

void Critter::setHasMoved(int i) {
  if (i == 0) {
    hasMoved = false;
  } else if (i == 1) {
    hasMoved = true;
  }
}

bool getHasMoved() {
  return hasMoved;
}
  
int getRow() {
  return row;
}
  
int getCol() {
  return col;
}

//always returns false because only a doodlebug can starve
bool starve() {
  return false;
}
