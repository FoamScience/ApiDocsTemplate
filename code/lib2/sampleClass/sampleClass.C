#include "sampleClass.H"

namespace Foam {

double sampleClass::operator()() {
    /// Documentation and implementation defer for this function
    /// It's supposed to return $R^{-2.5x}$ :face_screaming_in_fear:
    return R;
}

sampleClass& sampleClass::operator++() {
    ++x_;
    return *this;
}

sampleClass sampleClass::operator-(int& n) {
    return sampleClass(x_ - n);
}

}
