/*
 * MIT License
 *
 * Copyright (c) 2020 Mapless AI, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */
#include <iostream>
using namespace std;

#include "requirements-testing/example.hpp"

/**
 * @brief C ctor
 */
C::C(int i) : _m(i) {
  cout << "Class C initialized with " << _m << endl;
}

/**
 * @brief main entry point
 */
int main() {
  cout << "Hello world" << endl;

  C p(10);
  cout << p.get() << endl;

  for (unsigned i = 0; i < 100; ++i) {
    p.set(i);
  }
  cout << p.get() << endl;

  return EXIT_SUCCESS;
}
