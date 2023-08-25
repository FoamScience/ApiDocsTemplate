#pragma once

#include "scalar.H"
#include <concepts>

namespace Foam {

/// @brief Base interface to shape objects.
/// A shape is basically a set of "surface" patches which define regions
/// of closed volumes. Discretization can happen on both sides of these patches
/// if required.
/// @note This is an inline note
/// @warning And an inline warning
/// @hyde-owner elwardi
class sampleClass {
public:

    /// Enumerating class state !
    enum class picker {
        /// When it hasn't benn changed for a while
        stable,
        /// Actively under development
        dev
    };

    /// @brief Sub-item spinner to showcase multi-line briefs
    /// so here is the second line
    /// @hyde-owner elwardi
    /// @hyde-owner another
    template<class T>
    requires std::regular<T>
    struct subItem {
        /// Store the subItem
        T a;
    };

    /// Construct from `x`
    sampleClass(int x) : x_(x) {};

    /// Default move construction
    sampleClass(sampleClass &&) = default;

    /// Deleted default copy constructor
    sampleClass(const sampleClass &) = delete;

    /// Default move assignment
    sampleClass &operator=(sampleClass &&) = default;

    /// Deleted default copyassignment
    sampleClass &operator=(const sampleClass &) = delete;

    /// Destructor
    ~sampleClass(){}

    /// Const-access to `x`
    /// @return `x`
    int x() const { return x_; }

    /// Run computation
    /// @return $k = \mathbb{R}^{-2.5x}$
    double operator()();

    /// @return A sampleClass with incremented `x`
    sampleClass& operator++();

    /// Substraction between sampleClass and ints
    sampleClass operator-(int&);

private:
    /// A Note for `x_`
    int x_;
    /// A private constexpr to make things easier
    static constexpr scalar R = 12;
};

}
