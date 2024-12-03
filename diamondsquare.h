//
// Created by cocoa on 12/2/2024.
//

#ifndef DIAMONDSQUARE_H
#define DIAMONDSQUARE_H
#pragma once
#include <rand>

class DiamondSquareClass {
  public:
    void diamondSquare();
    void diamondStep();
    void squareStep();
    int randomNumber(int min, int max);

  private:
    std::random_device rd;

};


#endif //DIAMONDSQUARE_H
